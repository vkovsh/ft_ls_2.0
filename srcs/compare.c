/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 13:47:57 by vkovsh            #+#    #+#             */
/*   Updated: 2018/08/14 13:48:00 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

bool			operator_bigger(int a, int b)
{
	return (a > b);
}

bool			operator_lesser(int a, int b)
{
	return (a < b);
}

bool			compare_case_insensitive(t_list *a,
				t_list *b, void *compare_operator)
{
	char		*to_upper_a;
	char		*to_upper_b;

	to_upper_a =
		ft_strtoupper(((t_catalog *)(a->content))->name);
	to_upper_b =
		ft_strtoupper(((t_catalog *)(b->content))->name);
	if (((t_compoproute)compare_operator)(ft_strcmp(to_upper_a, to_upper_b), 0))
	{
		ft_strdel(&to_upper_a);
		ft_strdel(&to_upper_b);
		return (true);
	}
	ft_strdel(&to_upper_a);
	ft_strdel(&to_upper_b);
	return (false);
}

bool			compare_by_mod_date(t_list *a,
				t_list *b, void *compare_operator)
{
	t_catalog	*catalog_a;
	t_catalog	*catalog_b;
	time_t		date_a;
	time_t		date_b;

	catalog_a = (t_catalog *)(a->content);
	catalog_b = (t_catalog *)(b->content);
	date_a = catalog_a->clstat.st_mtime;
	date_b = catalog_b->clstat.st_mtime;
	return (((t_compoproute)compare_operator)(date_a, date_b));
}
