/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_flag_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 13:49:16 by vkovsh            #+#    #+#             */
/*   Updated: 2018/08/14 13:49:18 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

bool		is_flag_set(int flags, int flag)
{
	bool	is_set;

	is_set = flags & flag;
	return (is_set);
}