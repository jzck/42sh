/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 11:13:15 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/05 11:53:30 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTREE_H
# define BTREE_H

# include "libft.h"

struct	s_btree
{
	void			*item;
	size_t			content_size;
	struct s_btree	*left;
	struct s_btree	*right;
};

struct	s_printdata
{
	int		is_left;
	int		offset;
	int		depth;
	int		left;
	int		right;
};

typedef struct s_btree		t_btree;
typedef struct s_printdata	t_printdata;

t_btree	*btree_create_node(void const *item, size_t content_size);
void	btree_insert_data(
		t_btree **root,
		void *item,
		size_t content_size,
		int (*cmpf)(void *, void *));
void	*btree_search_item(t_btree *root,
		void *data_ref, int (*cmpf)(void *, void *));
int		btree_level_count(t_btree *root);
void	btree_apply_prefix(t_btree *root, void (*applyf)(void *));
void	btree_apply_infix(t_btree *root, void (*applyf)(void *));
void	btree_apply_suffix(t_btree *root, void (*applyf)(void *));
void	btree_print(int fd, t_btree *tree, char *(*printer)(void *));
void	btree_del(t_btree **root, void (*del)(void *, size_t));
void	btree_delone(t_btree **root, void (*del)(void *, size_t));

#endif
