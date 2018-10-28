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

void		set_delimiter(t_ftls *ftls)
{
	if (is_flag_set(ftls->flags, LS_ONE) ||
		is_flag_set(ftls->flags, LS_SMALL_L))
		ftls->delimiter = '\n';
	else
		ftls->delimiter = ' ';
}

void		proceed_flags(t_ftls *ftls)
{
	if (is_flag_set(ftls->flags, LS_BIG_U))
	{
		ftls->compare = NULL;
		ftls->compare_operator = NULL;
	}
	else if (is_flag_set(ftls->flags, LS_SMALL_T))
	{
		ftls->compare = compare_by_mod_date;
		if (is_flag_set(ftls->flags, LS_SMALL_R))
			ftls->compare_operator = operator_bigger;
		else
			ftls->compare_operator = operator_lesser;
	}
	else
	{
		ftls->compare = compare_case_insensitive;
		if (is_flag_set(ftls->flags, LS_SMALL_R))
			ftls->compare_operator = operator_lesser;
		else
			ftls->compare_operator = operator_bigger;
	}
}

void		set_print_func(t_ftls *ftls)
{
	ftls->print_arg =
		(is_flag_set(ftls->flags, LS_SMALL_L)) ?
		print_verbose_info : print_info;
}

int			main(int argc, char **argv)
{
	t_ftls	ftls;

	ft_bzero(&ftls, sizeof(t_ftls));
	get_args(argc, argv, &ftls);
	set_print_func(&ftls);
	set_delimiter(&ftls);
	proceed_flags(&ftls);
	parse_args(&ftls,
		ftls.arguments,
		is_flag_set(ftls.flags, LS_SMALL_D));
	return (0);
}
