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

void		set_delimiter(void)
{
	if (IS_FLAG_SET(g_ftls->flags, LS_ONE) ||
		IS_FLAG_SET(g_ftls->flags, LS_SMALL_L))
		g_ftls->delimiter = '\n';
	else
		g_ftls->delimiter = ' ';
}

void		proceed_flags(void)
{
	if (IS_FLAG_SET(g_ftls->flags, LS_BIG_U))
		g_ftls->traverse = ft_bintree_prefix_traverse;
	else if (IS_FLAG_SET(g_ftls->flags, LS_SMALL_T))
	{
		if (IS_FLAG_SET(g_ftls->flags, LS_SMALL_R))
			g_ftls->traverse = ft_bintree_infix_traverse_reverse;
		else
			g_ftls->traverse = ft_bintree_infix_traverse;
	}
	else
	{
		if (IS_FLAG_SET(g_ftls->flags, LS_SMALL_R))
			g_ftls->traverse = ft_bintree_infix_traverse_reverse;
		else
			g_ftls->traverse = ft_bintree_infix_traverse;
	}
}

void		set_print_func(void)
{
	g_ftls->print_arg =
		(IS_FLAG_SET(g_ftls->flags, LS_SMALL_L)) ?
		print_verbose_info : print_info;
}

int			main(int argc, char **argv)
{
	static t_ftls	ftls;

	g_ftls = &ftls;
	ft_bzero(&ftls, sizeof(t_ftls));
	get_args(argc, argv);
	set_print_func();
	set_delimiter();
	proceed_flags();
	parse_args(g_ftls->arguments);
	return (0);
}
