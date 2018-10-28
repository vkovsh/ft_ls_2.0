/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_directory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 13:53:33 by vkovsh            #+#    #+#             */
/*   Updated: 2018/08/14 13:53:35 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static inline bool	append_it(int flags, const char *name)
{
	return (name[0] != '.' ||
		is_flag_set(flags, LS_SMALL_A));
}

t_list				*read_directory(const char *dirname,
					t_ftls *ftls)
{
	DIR				*pdir;
	t_dirent		*pdirent;
	t_list			*dir_args;
	int				total;
	t_catalog		*catalog;

	dir_args = NULL;
	total = 0;
	if ((pdir = opendir(dirname)) == NULL)
		return (dir_args);
	while ((pdirent = readdir(pdir)) != NULL)
	{
		if (append_it(ftls->flags, pdirent->d_name))
		{
			set_catalog_from_arg(&dir_args,
				ft_strjoin_free(ft_strjoin(dirname, "/"),
				pdirent->d_name, TRUE, FALSE));
			catalog = (t_catalog *)(dir_args->content);
			total += catalog->clstat.st_blocks;
		}
	}
	if (is_flag_set(ftls->flags, LS_SMALL_L))
		ft_printf("total %[*]{*}d\n", 0xff0000, 0xffff00, total);
	closedir(pdir);
	return (dir_args);
}
