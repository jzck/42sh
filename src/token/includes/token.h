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

# define TK_WORD		0x0001
# define TK_NEWLINE		0x0002
# define TK_IOHERE		0x0004

# define TK_LESS		0x0010
# define TK_GREAT		0x0020
# define TK_DLESS		0x0048
# define TK_DGREAT		0x0080
# define TK_LESSAND		0x0100
# define TK_GREATAND	0x0200
# define TK_SCOLON		0x0400
# define TK_PIPE		0x0800

# define TK_OP_MIN		TK_LESS

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
