/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 13:54:21 by vkovsh            #+#    #+#             */
/*   Updated: 2018/08/14 13:54:23 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			swap(t_list *a, t_list *b)
{
	void		*tmp;

	tmp = a->content;
	a->content = b->content;
	b->content = tmp;
}

void			bubblesort(t_list **args,
					void *compare,
					void *compare_operator)
{
	t_list		*tmp;
	int			swap_count;

	swap_count = 1;
	while (swap_count != 0)
	{
		swap_count = 0;
		tmp = *args;
		while (tmp->next)
		{
			if (((t_comproute)compare)(tmp, tmp->next, compare_operator))
			{
				swap_count++;
				swap(tmp, tmp->next);
			}
			tmp = tmp->next;
		}
	}
}
