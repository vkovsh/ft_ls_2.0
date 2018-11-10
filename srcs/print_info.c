/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 13:52:18 by vkovsh            #+#    #+#             */
/*   Updated: 2018/08/14 13:52:21 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void					print_info(t_catalog *c,
						char delim)
{
	const t_colorpair	cp[FILE_TYPE_TOTAL] = COLOR_PAIRS;
	t_colorpair			tmp;
	char				*name;

	name = ft_strrchr(c->name, '/');
	name = (name) ? name + 1 : (char *)(c->name);
	tmp = cp[c->filetype];
	if (IS_FLAG_SET(g_ftls->flags, LS_SMALL_I))
		ft_printf("%-9zu", c->clstat->st_ino);
	if (IS_FLAG_SET(g_ftls->flags, LS_SMALL_S))
		ft_printf("%-4zu", c->clstat->st_blocks);
	ft_printf("%[*]{*}s%c", tmp.bc, tmp.fc, name, delim);
}
