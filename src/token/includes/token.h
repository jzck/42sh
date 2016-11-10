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

# define TK_WORD		0x001
# define TK_NEWLINE		0x002
# define TK_IOHERE		0b00000100
# define TK_DLESS		0b00001000
# define TK_DGREAT		0b00010000
# define TK_LESS		0b00100000
# define TK_GREAT		0b00100000
# define TK_LESSAND		0b00100000
# define TK_GREATAND	0b01000000
# define TK_OPERATOR	0b01111100

typedef struct s_token	t_token;

struct s_token
{
	int		type;
	int		id;
	char	*content;
	char	*size;
};

t_token	*token_init();
int		ft_tokenize(t_list **alst, char *str);
int		token_recognition(t_list *alst, char *str);

#endif
