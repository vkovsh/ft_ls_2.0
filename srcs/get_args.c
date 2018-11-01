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

void			set_flags_from_arg(char *str)
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
				g_ftls->flags |= 1 << j;
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

int				set_catalog_from_arg(t_bintree **args, char *str)
{
	t_catalog	tmp;

	tmp.clstat = (t_stat *)malloc(sizeof(t_stat));
	tmp.name = str;
	tmp.stat_res = stat(tmp.name, tmp.clstat);
	if ((tmp.lstat_res = lstat(tmp.name, tmp.clstat)) < 0)
	{
		ft_printf("ft_ls: cannot access '%s'%s",
		tmp.name, ": No such file or directory\n");
		return (-1);
	}
	tmp.filetype = get_file_type(&tmp);
	char *key;
	if (IS_FLAG_SET(g_ftls->flags, LS_SMALL_T))
		key = ctime(&(tmp.clstat->st_mtime));
	else
	{
		key = ft_strrchr(tmp.name, '/');
		if (key)
			key++;
		else
			key = tmp.name;
	}
	ft_bintree_add(args,
		ft_bintree_new(key, ft_strlen(key) + 1,
			&tmp, sizeof(tmp)), ft_memcmp);
	return (0);
}

void			get_args(int ac, char **av)
{
	int			i;
	int			empty_flag;

	i = ac;
	empty_flag = 0;
	while (--i >= 1)
		if (*(av[i]) == '-' && av[i][1])
			set_flags_from_arg(&(av[i][1]));
		else
			empty_flag =
				set_catalog_from_arg(&(g_ftls->arguments),
				ft_strdup(av[i]));
	if (g_ftls->arguments == NULL)
		if (!empty_flag)
			set_catalog_from_arg(&(g_ftls->arguments),
				ft_strdup("."));
}
