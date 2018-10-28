#include "libft.h"

void	ft_bintree_delone(t_bintree **t,
		t_del_node del)
{
	del((*t)->key,
		(*t)->key_size,
		(*t)->value,
		(*t)->value_size);
	free(*t);
	*t = NULL;
}