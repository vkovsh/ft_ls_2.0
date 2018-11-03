#ifndef BINTREE_H
# define BINTREE_H
# include <sys/types.h>
# include <stdlib.h>
# define HEIGHT(n)((n)?n->height:0)
# define BFACTOR(n)(HEIGHT(n->right)-HEIGHT(n->left))

typedef struct			s_bintree
{
	unsigned char		height;
	void				*key;
	size_t				key_size;
	void				*value;
	size_t				value_size;
	struct s_bintree	*left;
	struct s_bintree	*right;
}						t_bintree;

typedef int	(*t_compare_keys)(const void *a,
			const void *b, size_t key_size);

typedef void	(*t_node_action)(
	void *key, size_t key_size,
	void *value, size_t value_size);

typedef void	(*t_del_node)(
	void *key, size_t key_size,
	void *value, size_t value_size);

void					ft_fixheight(t_bintree *t);

t_bintree				*ft_right_rotate(t_bintree *t);

t_bintree				*ft_left_rotate(t_bintree *t);

t_bintree				*ft_balance(t_bintree *p);

void					ft_bintree_add(t_bintree **t,
	t_bintree *node, t_compare_keys compare);

t_bintree				*ft_bintree_new(const void *key,
	size_t key_size,
	const void *value,
	size_t value_size);

t_bintree				*ft_bintree_find(t_bintree **t,
	void *key, size_t key_size, t_compare_keys compare);

void					ft_bintree_delone(t_bintree **t,
	t_del_node del);

void					ft_bintree_del(t_bintree **t,
	t_del_node del);

void					ft_bintree_infix_traverse(t_bintree **t,
						t_node_action action);

void					ft_bintree_prefix_traverse(t_bintree **t,
						t_node_action action);

void					ft_bintree_postfix_traverse(t_bintree **t,
						t_node_action action);

void					ft_bintree_infix_traverse_reverse(t_bintree **t,
						t_node_action action);
#endif
