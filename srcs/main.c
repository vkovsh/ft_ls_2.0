/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 13:51:01 by vkovsh            #+#    #+#             */
/*   Updated: 2018/08/14 13:51:03 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ftls	*g_ftls = NULL;

int			main(int argc, char **argv)
{
	static t_ftls	ftls;

	g_ftls = &ftls;
	ft_bzero(&ftls, sizeof(t_ftls));
	get_args(argc, argv);
	g_ftls->print_arg =
		(IS_FLAG_SET(g_ftls->flags, LS_SMALL_L)) ?
		print_verbose_info : print_info;
	g_ftls->update_width_ptr =
		(IS_FLAG_SET(g_ftls->flags, LS_SMALL_L)) ?
		update_field_width : NULL;
	if (IS_FLAG_SET(g_ftls->flags, LS_ONE) ||
		IS_FLAG_SET(g_ftls->flags, LS_SMALL_L))
		g_ftls->delimiter = '\n';
	else
		g_ftls->delimiter = ' ';
	if (IS_FLAG_SET(g_ftls->flags, LS_SMALL_R) &&
		!IS_FLAG_SET(g_ftls->flags, LS_BIG_U))
		g_ftls->traverse = ft_bintree_infix_traverse_reverse;
	else
		g_ftls->traverse = ft_bintree_infix_traverse;

	if (IS_FLAG_SET(g_ftls->flags, LS_BIG_U))
		g_ftls->compare_func_ptr = ft_memcmp;
	else if (IS_FLAG_SET(g_ftls->flags, LS_BIG_S))
		g_ftls->compare_func_ptr = (t_compare_keys)comp_scalars;
	else if (IS_FLAG_SET(g_ftls->flags, LS_SMALL_T))
		g_ftls->compare_func_ptr = (t_compare_keys)comp_scalars;
	else
		g_ftls->compare_func_ptr = ft_memcmp;
	parse_args(g_ftls->arguments);
	return (0);
}
