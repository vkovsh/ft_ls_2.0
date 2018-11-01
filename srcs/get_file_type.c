/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 13:48:55 by vkovsh            #+#    #+#             */
/*   Updated: 2018/08/14 13:48:57 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_filetype		get_file_type(t_catalog *c)
{
	t_filetype	result;
	int			type_mask;
	const int	type_macro[FILE_TYPE_TOTAL] = TYPE_ID_MACRO;

	if (c->lstat_res < 0)
		return (ERR);
	else
	{
		type_mask = c->clstat->st_mode & S_IFMT;
		result = ERR;
		while (++result < FILE_TYPE_TOTAL)
			if (type_mask == type_macro[result])
				return (result);
	}
	return (ERR);
}
