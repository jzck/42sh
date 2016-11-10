/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:31:42 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/10 17:04:12 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# define TOKEN_WORD			0b000001
# define TOKEN_OPERATOR		0b000010

typedef struct s_token	t_token;

struct s_token
{
	int		type;
	char	*content;
	char	*size;
};

t_token	*token_init();
int		ft_tokenize(t_list **alst, char *str);
int		token_recognition(t_list *alst, char *str);

#endif
