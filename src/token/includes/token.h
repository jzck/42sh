/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:31:42 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/11 20:44:28 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

typedef long long		t_type;

# define TK_WORD		0x0001
# define TK_NEWLINE		0x0002
# define TK_IOHERE		0x0004
# define TK_LESS		0x0010
# define TK_GREAT		0x0020
# define TK_DLESS		0x0040
# define TK_DGREAT		0x0080
# define TK_LESSAND		0x0100
# define TK_GREATAND	0x0200
# define TK_SCOLON		0x0400
# define TK_PIPE		0x0800
# define TK_UNKNOWN		0x1000

# define TK_OPERATOR	1 & (~TK_WORD | ~TK_NEWLINE | ~TK_IOHERE)
# define OPERATOR_ST	"<>;|0123456789"

# define NUM_BEFORE		0x0001
# define WORD_AFTER		0x0002
# define MIN_END		0x0004


typedef struct s_operator	t_operator;
typedef struct s_token		t_token;
typedef struct s_redir		t_redir;

struct s_operator
{
	t_type	type;
	char	symbol[3];
	t_type	format;
};

struct s_redir
{
	t_type	type;
	int		fd;
	char	*filename;
};

struct s_token
{
	t_type	type;
	char	*content;
	char	*size;
};

extern t_operator	g_ops[];

t_token	*token_init();
int		ft_tokenize(t_list **alst, char *str);
int		token_recognition(t_list *alst, char *str);
int		token_append(t_token *token, char str);
int		token_delimit(t_token *token);

#endif
