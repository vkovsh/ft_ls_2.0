#include "libft.h"

void				ft_fixheight(t_bintree *t)
{
	unsigned char	hl;
	unsigned char	hr;

	hl = HEIGHT(t->left);
	hr = HEIGHT(t->right);
	t->height = ((hl > hr) ? hl : hr) + 1;
}