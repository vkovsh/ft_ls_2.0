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

void		pit(void *k, size_t k_size,
				void *v, size_t v_size)
{
	ft_printf("key = %s, key_size = %zu, value = %s, value_size = %zu\n",
		k, k_size, v, v_size);
}

void		del(void *k, size_t k_size,
				void *v, size_t v_size)
{
	free(k);
	free(v);
	(void)k_size;
	(void)v_size;
}

int			main(int argc, char **argv)
{
	/*t_bintree *node = NULL;
	t_bintree *bt0 = ft_bintree_new((void *)"0", 2, "0", 2);
	t_bintree *bt1 = ft_bintree_new("1", 2, "1", 2);
	t_bintree *bt2 = ft_bintree_new("2", 2, "2", 2);
	t_bintree *bt3 = ft_bintree_new("3", 2, "3", 2);
	t_bintree *bt4 = ft_bintree_new("4", 2, "4", 2);
	t_bintree *bt5 = ft_bintree_new("5", 2, "5", 2);
	t_bintree *bt6 = ft_bintree_new("6", 2, "6", 2);
	t_bintree *bt7 = ft_bintree_new("7", 2, "7", 2);
	t_bintree *bt8 = ft_bintree_new("8", 2, "8", 2);
	t_bintree *bt9 = ft_bintree_new("9", 2, "9", 2);
	t_bintree *bt10 = ft_bintree_new("10", 3, "10", 3);
	ft_bintree_add(&node, bt7, &ft_memcmp);
	ft_bintree_add(&node, bt0, &ft_memcmp);
	ft_bintree_add(&node, bt1, &ft_memcmp);
	ft_bintree_add(&node, bt10, &ft_memcmp);
	ft_bintree_add(&node, bt2, &ft_memcmp);
	ft_bintree_add(&node, bt3, &ft_memcmp);
	ft_bintree_add(&node, bt4, &ft_memcmp);
	ft_bintree_add(&node, bt5, &ft_memcmp);
	ft_bintree_add(&node, bt6, &ft_memcmp);
	ft_bintree_add(&node, bt8, &ft_memcmp);
	ft_bintree_add(&node, bt9, &ft_memcmp);
	ft_printf("%[*]{*}s\n", 0xff0000, 0x0000ff, "PREFIX");
	ft_bintree_prefix_traverse(&node, &pit);
	ft_printf("%[*]{*}s\n", 0xff0000, 0x0000ff, "INFIX");
	ft_bintree_infix_traverse(&node, &pit);
	ft_printf("%[*]{*}s\n", 0xff0000, 0x0000ff, "POSTFIX");
	ft_bintree_postfix_traverse(&node, &pit);
	ft_bintree_del(&node, del);*/
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
