/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_verbose_info.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 13:52:56 by vkovsh            #+#    #+#             */
/*   Updated: 2018/08/14 13:52:58 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void					get_permission_str(
						t_catalog *c,
						char *perm)
{
	const int			pm[10] = PERM_MACRO;
	t_perm				i;

	perm[10] = '\0';
	perm[0] = FILE_TYPE_MARKERS[c->filetype];
	i = 0;
	while (++i <= PERM_TOTAL)
		perm[i] = (c->clstat->st_mode & pm[i]) ?
			PERM_FULL[i] : '-';
	if (c->clstat->st_mode & S_ISVTX)
		perm[9] = 't';
}

const char				*cut_name(const char *name)
{
	char				*result;

	result = ft_strrchr(name, '/');
	return ((result) ? result + 1 : name);
}

void					print_from_stat(t_catalog *c,
						const char *tname,
						t_colorpair pair)
{
	char				perm[11];
	struct passwd		*pw;
	struct group		*gr;
	char				*date;

	date = ctime(&c->clstat->st_mtime);
	pw = getpwuid(c->clstat->st_uid);
	gr = getgrgid(c->clstat->st_gid);
	get_permission_str(c, perm);
	if (IS_FLAG_SET(g_ftls->flags, LS_SMALL_I))
		ft_printf("%-9zu", c->clstat->st_ino);
	if (IS_FLAG_SET(g_ftls->flags, LS_SMALL_S))
		ft_printf("%-4zu", c->clstat->st_blocks);
	//char list[1024];
	if (c->filetype == CHR_FILE || c->filetype == BLK_FILE)
	{
		ft_printf("%s%c%*d %-*s%-*s %*d,%*d %.12s %[*]{*}s",
			perm,
			listxattr(c->name, NULL, 0) ? '+' : ' ',
			g_ftls->nlink_width, c->clstat->st_nlink,
			g_ftls->pw_name_width + 1, pw->pw_name,
			g_ftls->gr_name_width + 1, gr->gr_name,
			g_ftls->major_width + 1, major(c->clstat->st_rdev),
			g_ftls->minor_width + 1, minor(c->clstat->st_rdev),
			&date[4],
			pair.bc,
			pair.fc,
			cut_name(c->name));
	}
	else
	{
		ft_printf("%s%c%*d%*s%*s %*d %.12s %[*]{*}s",
		perm,
		listxattr(c->name, NULL, 0) ? '+' : ' ',
		g_ftls->nlink_width, c->clstat->st_nlink,
		g_ftls->pw_name_width + 1, pw->pw_name,
		g_ftls->gr_name_width + 1, gr->gr_name,
		g_ftls->size_width, c->clstat->st_size,
		&date[4],
		pair.bc,
		pair.fc,
		cut_name(c->name));
	}
	if (tname)
		ft_printf(" -> %s", tname);
	//ft_printf("[[ %s ]]\n", list);
}

void					print_verbose_info(t_catalog *c,
						char delim)
{
	char				tn[NAME_MAX + 1];
	const t_colorpair	cp[FILE_TYPE_TOTAL] = COLOR_PAIRS;

	if (c->filetype == LNK_FILE)
	{
		ft_bzero(tn, NAME_MAX + 1);
		readlink(c->name, tn, NAME_MAX + 1);
		if (c->stat_res < 0)
			print_from_stat(c, tn,
			(t_colorpair){.fc = 0xff0000});
		else
			print_from_stat(c, tn, cp[c->filetype]);
	}
	else
	{
		if (c->filetype == REG_FILE &&
			IS_BIN(c->clstat->st_mode))
		{
			print_from_stat(c, NULL,
			(t_colorpair){.fc = 0xff0000});
		}
		else
			print_from_stat(c, NULL, cp[c->filetype]);
	}
	ft_putchar(delim);
}
