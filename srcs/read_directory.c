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

t_bintree			*read_directory(const char *dirname)
{
	DIR				*pdir;
	t_dirent		*pdirent;
	t_bintree		*dir_args;
	int				total;
	t_catalog		*catalog;

	dir_args = NULL;
	total = 0;
	if ((pdir = opendir(dirname)) == NULL)
		return (dir_args);
	static int i = -1;
	while ((pdirent = readdir(pdir)) != NULL)
	{
		if (APPEND_IT(g_ftls->flags, pdirent->d_name))
		{
			++i;
			set_catalog_from_arg(&dir_args,
				ft_strjoin_free(ft_strjoin(dirname, "/"),
				pdirent->d_name, TRUE, FALSE), &i);
			catalog = (t_catalog *)(dir_args->value);
			total += catalog->clstat->st_blocks;
		}
	}
	if (IS_FLAG_SET(g_ftls->flags, LS_SMALL_L))
		ft_printf("total %[*]{*}d\n", 0xff0000, 0xffff00, total);
	closedir(pdir);
	return (dir_args);
}
