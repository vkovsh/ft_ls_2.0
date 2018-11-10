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

	i = -1;
	while (str[++i])
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
	}
}

int				comp_scalars(int64_t *a, int64_t *b)
{
	return (*b - *a);
}

void			update_field_width(void *ptr)
{
	t_catalog	*c;

	c = ptr;
	int width = ft_nbrlen(c->clstat->st_size);
	if (width > g_ftls->size_width)
		g_ftls->size_width = width;
	width = ft_nbrlen(c->clstat->st_nlink);
	if (width > g_ftls->nlink_width)
		g_ftls->nlink_width = width;
	width = ft_strlen((char *)getpwuid(c->clstat->st_uid));
	if (width > g_ftls->pw_name_width)
		g_ftls->pw_name_width = width;
	width = ft_strlen((char *)getgrgid(c->clstat->st_gid));
	if (width > g_ftls->gr_name_width)
		g_ftls->gr_name_width = width;
	width = ft_nbrlen(major(c->clstat->st_rdev));
	if (width > g_ftls->major_width)
		g_ftls->major_width = width;
	width = ft_nbrlen(minor(c->clstat->st_rdev));
	if (width > g_ftls->minor_width)
		g_ftls->minor_width = width;
	if (g_ftls->minor_width + g_ftls->major_width - 3 > g_ftls->size_width)
		g_ftls->size_width = g_ftls->minor_width + g_ftls->major_width + 4;	
}

int				set_catalog_from_arg(t_bintree **args,
				char *str,
				void *order)
{
	t_catalog	tmp;

	if (!(tmp.clstat = (t_stat *)malloc(sizeof(t_stat))))
		exit (1);
	tmp.name = str;
	tmp.stat_res = stat(tmp.name, tmp.clstat);
	if ((tmp.lstat_res = lstat(tmp.name, tmp.clstat)) < 0)
	{
		ft_printf("ft_ls: cannot access '%s'%s",
		tmp.name, ": No such file or directory\n");
		return (-1);
	}
	if (g_ftls->update_width_ptr)
		g_ftls->update_width_ptr(&tmp);
	tmp.filetype = get_file_type(&tmp);
	void *key;
	int key_size;
	if (IS_FLAG_SET(g_ftls->flags, LS_BIG_U))
	{
		key = order;
		key_size = sizeof(int);
	}
	else if (IS_FLAG_SET(g_ftls->flags, LS_BIG_S))
	{
		key = (void *)&(tmp.clstat->st_size);
		key_size = sizeof(__off_t);
	}
	else if (IS_FLAG_SET(g_ftls->flags, LS_SMALL_T))
	{
		key = (void *)&(tmp.clstat->st_mtime);
		key_size = sizeof(time_t);
	}
	else
	{
		key = (char *)cut_name(tmp.name);
		key_size = ft_strlen(key) + 1;
	}
	ft_bintree_add(args,
		ft_bintree_new(key, key_size,
			&tmp, sizeof(tmp)),
			g_ftls->compare_func_ptr);
	return (0);
}

void			get_args(int ac, char **av)
{
	static int	i;
	int			empty_flag;

	i = ac;
	empty_flag = 0;
	while (--i >= 1)
		if (*(av[i]) == '-' && av[i][1])
			set_flags_from_arg(&(av[i][1]));
		else
			empty_flag =
				set_catalog_from_arg(&(g_ftls->arguments),
				ft_strdup(av[i]), &i);
	if (g_ftls->arguments == NULL)
		if (!empty_flag)
			set_catalog_from_arg(&(g_ftls->arguments),
				ft_strdup("."), &i);
}
