/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 13:51:27 by vkovsh            #+#    #+#             */
/*   Updated: 2018/08/14 13:51:29 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_bintree	**g_dirs;
int g_depth = 0;

static void			del_catalog_entry(void *key,
					size_t key_size,
					void *value,
					size_t value_size)
{
	t_catalog		*to_del;

	to_del = (t_catalog *)value;
	(void)to_del;
	ft_strdel(&(to_del->name));
	ft_memdel((void *)&(to_del->clstat));
	ft_memdel(&key);
	ft_memdel(&value);
	(void)key_size;
	(void)value_size;
}

static void			extract_arg_from_dirs(void *key,
					size_t key_size,
					void *value,
					size_t value_size)
{
	t_catalog		*catalog;
	char			*name_buf;
	t_bintree		*new_args;

	(void)key;
	(void)key_size;
	(void)value_size;
	catalog = (t_catalog *)(value);
	if (!is_system_dot_dir(catalog->name) || g_depth == 0)
	{
		if ((name_buf = ft_strchr(catalog->name, '/')))
			name_buf++;
		else
			name_buf = catalog->name;
		if (ft_strcmp(".", catalog->name))
			ft_printf("%[*]{*}s:\n",
			0x00ff00, 0x0000ff, name_buf);
		if (!(new_args = read_directory(catalog->name)))
			FT_ERROR(cut_name(catalog->name));
		else
		{
			g_depth++;
			parse_args(new_args);
		}
	}
}

static void			extract_arg(void *key,
					size_t key_size,
					void *value,
					size_t value_size)
{
	t_catalog		catalog;

	catalog = *((t_catalog *)(value));
	if (catalog.filetype == DIR_FILE)
	{
		if (IS_FLAG_SET(g_ftls->flags, LS_SMALL_D))
			g_ftls->print_arg(&catalog, g_ftls->delimiter);
		else
		{
			catalog.name = ft_strdup(catalog.name);
			catalog.clstat = (t_stat *)malloc(sizeof(t_stat));
			lstat(catalog.name, catalog.clstat);
			ft_bintree_add(g_dirs,
				ft_bintree_new(key, key_size,
					&catalog, value_size), ft_memcmp);
			if (g_depth)
				g_ftls->print_arg(&catalog, g_ftls->delimiter);
		}
	}
	else
		g_ftls->print_arg(&catalog, g_ftls->delimiter);
}

void				parse_args(t_bintree *args)
{
	t_bintree		*dirs;

	if (args != NULL)
	{
		dirs = NULL;
		g_dirs = &dirs;
		g_ftls->traverse(&args, extract_arg);
		ft_putchar('\n');
		if (IS_FLAG_SET(g_ftls->flags, LS_BIG_R) ||
			g_depth == 0)
		{
			if (IS_FLAG_SET(g_ftls->flags, LS_SMALL_L))
				ft_bzero(g_ftls, 6);
			if (!IS_FLAG_SET(g_ftls->flags, LS_SMALL_D))
				g_ftls->traverse(&dirs, extract_arg_from_dirs);
		}
		if (args)
			ft_bintree_del(&args, del_catalog_entry);
		if (dirs)
			ft_bintree_del(&dirs, del_catalog_entry);
	}
}
