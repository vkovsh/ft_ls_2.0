#include "libft.h"
#include <unistd.h>

t_bintree		*ft_bintree_new(const void *key,
				size_t key_size,
				const void *value,
				size_t value_size)
{
	t_bintree	*bintree;

	if (!(bintree = (t_bintree *)malloc(sizeof(t_bintree))))
		return (NULL);
	if (!(bintree->value = malloc(value_size)))
		return (NULL);
	ft_memcpy(bintree->value, value, value_size);
	bintree->value_size = value_size;
	if (!(bintree->key = malloc(key_size)))
		return (NULL);
	ft_memcpy(bintree->key, key, key_size);
	bintree->key_size = key_size;
	bintree->left = NULL;
	bintree->right = NULL;
	bintree->height = 1;
	return (bintree);
}