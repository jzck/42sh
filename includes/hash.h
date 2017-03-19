/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 11:10:14 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/19 16:37:44 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_H
# define HASH_H

# define MAX_HASH 200

extern t_list	*g_hash[MAX_HASH];

typedef struct	s_hash
{
	char	*key;
	char	*path;
}				t_hash;

char			*ft_add_hash(char *cmd);
char			*ft_hash(char *cmd);
char			*ft_is_hash(char *cmd);
int				ft_hash_str(char *str);

void			ft_hash_free(void *ptr, size_t size);
void			ft_free_hash_table(void);

#endif
