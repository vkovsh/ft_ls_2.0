#include "libft.h"

void	ft_bintree_add(t_bintree **t,
		t_bintree *node,
		t_compare_keys compare)
{
	if (*t == NULL)
		*t = node;
	else
	{
		if (compare(node->key, (*t)->key, node->key_size) < 0)
		{
			if ((*t)->left)
				ft_bintree_add(&((*t)->left), node, compare);
			else
				(*t)->left = node;
		}
		else
		{
			if ((*t)->right)
				ft_bintree_add(&((*t)->right), node, compare);
			else
				(*t)->right = node;
		}
	}
}