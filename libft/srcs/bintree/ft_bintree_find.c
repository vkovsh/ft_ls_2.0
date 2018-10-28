#include "libft.h"

t_bintree		*ft_bintree_find(t_bintree **t,
				void *key, size_t key_size,
				t_compare_keys compare)
{
	t_bintree	*find;
	int			i;

	find = *t;
	while (find)
		if (!(i = compare(key, find->key, key_size)))
			return (find);
		else if (i < 0)
			find = find->left;
		else
			find = find->right;
	return (NULL);
}