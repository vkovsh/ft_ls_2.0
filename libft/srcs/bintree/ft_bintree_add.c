#include "libft.h"
#include <stdio.h>

void	ft_bintree_add(t_bintree **t,
		t_bintree *node,
		t_compare_keys compare)
{
	if (*t == NULL)
		*t = node;
	else
	{
		if (compare(node->key, (*t)->key, node->key_size) < 0)
			ft_bintree_add(&((*t)->left), node, compare);
		else
			ft_bintree_add(&((*t)->right), node, compare);
		//printf("[%d] -> ", (*t)->height);
		//*t = ft_balance(*t);
		//printf("[%d]\n", (*t)->height);
	}
}