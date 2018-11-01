#include "libft.h"

void	ft_bintree_infix_traverse(t_bintree **t,
		t_node_action action)
{
	if (*t == NULL)
		return ;
	ft_bintree_infix_traverse(&((*t)->left), action);
	action((*t)->key, (*t)->key_size,
			(*t)->value, (*t)->value_size);
	ft_bintree_infix_traverse(&((*t)->right), action);
}

void	ft_bintree_infix_traverse_reverse(t_bintree **t,
		t_node_action action)
{
	if (*t == NULL)
		return ;
	ft_bintree_infix_traverse_reverse(&((*t)->right), action);
	action((*t)->key, (*t)->key_size,
			(*t)->value, (*t)->value_size);
	ft_bintree_infix_traverse_reverse(&((*t)->left), action);
}