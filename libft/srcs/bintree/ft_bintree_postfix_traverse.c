#include "libft.h"

void	ft_bintree_postfix_traverse(t_bintree **t,
		t_node_action action)
{
	if (*t == NULL)
		return ;
	ft_bintree_postfix_traverse(&((*t)->left), action);
	ft_bintree_postfix_traverse(&((*t)->right), action);
	action((*t)->key, (*t)->key_size,
			(*t)->value, (*t)->value_size);
}