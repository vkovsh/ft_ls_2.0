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

void					print_info(t_catalog *catalog,
						char delim)
{
	const t_colorpair	cp[FILE_TYPE_TOTAL] = COLOR_PAIRS;
	t_colorpair			tmp;
	char				*name;

	name = ft_strrchr(catalog->name, '/');
	name = (name) ? name + 1 : (char *)(catalog->name);
	tmp = cp[catalog->filetype];
	ft_printf("%[*]{*}s%c", tmp.bc, tmp.fc, name, delim);
}
