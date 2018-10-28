/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 13:48:19 by vkovsh            #+#    #+#             */
/*   Updated: 2018/08/14 13:48:22 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			set_flags_from_arg(t_ftls *ftls, char *str)
{
	int			i;
	int			j;
	const char	flags[LS_FLAG_TOTAL] = FLAGS_ARRAY;

	i = 0;
	while (str[i])
	{
		j = -1;
		while (++j < LS_FLAG_TOTAL)
		{
			if (str[i] == flags[j])
				ftls->flags |= 1 << j;
			else if (!ft_isalnum(str[i]))
			{
				ft_printf("%s '%c'\n",
					"ft_ls: invalid option --", str[i]);
				exit(1);
			}
		}
		i++;
	}
}

int				set_catalog_from_arg(t_list **args, char *str)
{
	t_catalog	tmp;

	tmp.name = str;
	tmp.stat_res = stat(tmp.name, &tmp.cstat);
	if ((tmp.lstat_res = lstat(tmp.name, &tmp.clstat)) < 0)
	{
		ft_printf("ft_ls: cannot access '%s'%s",
		tmp.name, ": No such file or directory\n");
		return (-1);
	}
	tmp.filetype = get_file_type(&tmp);
	ft_lstadd(args, ft_lstnew(&tmp, sizeof(t_catalog)));
	return (0);
}

void			get_args(int ac, char **av, t_ftls *ftls)
{
	int			i;
	int			empty_flag;

	i = ac;
	empty_flag = 0;
	while (--i >= 1)
		if (*(av[i]) == '-' && av[i][1])
			set_flags_from_arg(ftls, &(av[i][1]));
		else
			empty_flag =
				set_catalog_from_arg(&(ftls->arguments),
				ft_strdup(av[i]));
	if (ftls->arguments == NULL)
		if (!empty_flag)
			set_catalog_from_arg(&(ftls->arguments),
				ft_strdup("."));
}
