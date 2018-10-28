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

static void			del_catalog_entry(void *c, size_t size)
{
	t_catalog		*to_del;

	if (size == sizeof(t_catalog))
	{
		to_del = (t_catalog *)c;
		ft_strdel(&(to_del->name));
		ft_memdel(&c);
	}
	else
		ft_printf("Free error\n");
}

static void			extract_args_from_dirs(t_ftls *ftls,
					t_list *dirs, int depth)
{
	t_catalog		*catalog;
	char			*name_buf;
	t_list			*new_args;

	while (dirs)
	{
		catalog = (t_catalog *)(dirs->content);
		if (!is_system_dot_dir((char *)catalog->name) || depth == 0)
		{
			if ((name_buf = ft_strchr(catalog->name, '/')))
				name_buf++;
			else
				name_buf = catalog->name;
			if (ft_strcmp(".", catalog->name))
				ft_printf("%[*]{*}s:\n",
				0x00ff00, 0x0000ff, name_buf);
			if (!(new_args = read_directory(catalog->name, ftls)))
				ft_error(cut_name(catalog->name));
			else
				parse_args(ftls, new_args, depth + 1);
		}
		dirs = dirs->next;
	}
}

static void			extract_args(t_list *args,
					t_list **dirs,
					t_ftls *ftls,
					int depth)
{
	t_catalog		*catalog;

	while (args)
	{
		catalog = (t_catalog *)(args->content);
		if (catalog->filetype == DIR_FILE)
		{
			ft_lstadd(dirs,
				ft_lstnew(catalog, sizeof(t_catalog)));
			((t_catalog *)((*dirs)->content))->name =
				ft_strdup(catalog->name);
			if (depth)
				ftls->print_arg(catalog, ftls->delimiter);
		}
		else
			ftls->print_arg(catalog, ftls->delimiter);
		args = args->next;
	}
	ft_putchar('\n');
}

static void			sort_args(t_list **args,
					t_ftls *ftls)
{
	if (ftls->compare)
		bubblesort(args,
			ftls->compare,
			ftls->compare_operator);
	else
		ft_lstrev(args);
}

void				parse_args(t_ftls *ftls,
					t_list *args, int depth)
{
	t_list			*dirs;

	if (args != NULL)
	{
		dirs = NULL;
		sort_args(&args, ftls);
		extract_args(args, &dirs, ftls, depth);
		ft_lstrev(&dirs);
		if (is_flag_set(ftls->flags, LS_BIG_R) || depth == 0)
		{
			if (!is_flag_set(ftls->flags, LS_SMALL_D))
				extract_args_from_dirs(ftls, dirs, depth);
		}
		if (dirs)
			ft_lstdel(&dirs, &del_catalog_entry);
		ft_lstdel(&args, &del_catalog_entry);
	}
}
