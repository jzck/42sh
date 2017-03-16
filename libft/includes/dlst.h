/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:21:04 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/07 17:25:50 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLST_H
# define DLST_H

struct	s_dlist
{
	void			*content;
	size_t			content_size;
	struct s_dlist	*next;
	struct s_dlist	*prev;
};

typedef struct s_dlist	t_dlist;

void	ft_dlstadd_after(t_dlist **alst, t_dlist *new);
void	ft_dlstadd_before(t_dlist **alst, t_dlist *new);
void	ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t));
void	ft_dlstdelone(t_dlist **alst, void (*del)(void *, size_t));
int		ft_dlstsize(t_dlist *list);
t_dlist	*ft_dlstnew(void const *content, size_t content_size);
t_dlist	*ft_dlstlast(t_dlist *list);
char	*ft_dlsttostr(t_dlist *list);

#endif
