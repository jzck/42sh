/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 16:31:18 by wescande          #+#    #+#             */
/*   Updated: 2017/01/12 19:00:08 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOB_H
# define GLOB_H

# include "minishell.h"

typedef struct	s_ld
{
	void			*content;
	struct s_ld		*next;
	struct s_ld		*prev;
}				t_ld;

char			**glob(const char *str, char **env);
t_ld			*expand_brace(const char *pat);
void			glob_print(t_list *token, t_data *data);

/*
** LIST D:
*/
void			ft_ld_new(t_ld **alst, void *content);
t_ld			*ft_ld_front(t_ld	*ld);
void			ft_ld_pushfront(t_ld **alst, void *content);
void			ft_ld_pushback(t_ld **alst, void *content);
size_t			ft_ld_size(t_ld *ld);
void			ft_ld_del(t_ld **ld, void (*del)());
void			ft_ld_clear(t_ld **ld, void (*del)());
void			ft_ld_reverse(t_ld **lst);
t_ld			*ft_ld_back(t_ld *ld);
t_ld			*ft_ld_swap(t_ld *l_cur);
char			**ft_ld_to_tab(t_ld *ld);


#endif
