/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:31:42 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/14 18:22:04 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include "libft.h"

# define TK_LESS		0x0001
# define TK_GREAT		0x0002
# define TK_DLESS		0x0004
# define TK_DGREAT		0x0008
# define TK_LESSAND		0x0010
# define TK_GREATAND	0x0020
# define TK_SEMI		0x0040
# define TK_PIPE		0x0080
# define TK_WORD		0x0100
# define TK_COMMAND		0x0200

# define TK_REDIR		0x1 | 0x2 | 0x4 | 0x8 | 0x10 | 0x20

typedef long long			t_type;
typedef struct s_token		t_token;
typedef struct s_parser		t_parser;
typedef struct s_astnode	t_astnode;
typedef struct s_redir		t_redir;

struct s_redir
{
	int		n;
	union u_word
	{
		char	*word;
		int		fd;
	} u_word;
};

struct s_token
{
	t_type	type;
	char	*data;
	int		size;
};

struct s_parser
{
	t_type	type;
	int		(*f)(t_btree **ast, t_list *start, t_list *token);
};

struct s_astnode
{
	t_type	type;
	union u_astdata
	{
		t_redir	redir;
		char	**sstr;
	} u_data;
};

extern t_parser		g_parser[];

t_token	*token_init();
t_token	*token_getnext(int *pos,char *line);
int		ft_tokenize(t_list **alst, char *str);
int		token_append(t_token *token, char c);
void	token_free(void *data, size_t size);
int		token_cmp_type(t_type data, t_type ref);
void	token_print(t_list *lst);

int		ft_parse(t_btree **ast, t_list *token);
int		parse_separator(t_btree **ast, t_list *start, t_list *lst);
int		parse_less(t_btree **ast, t_list *start, t_list *lst);
int		parse_great(t_btree **ast, t_list *start, t_list *lst);
int		parse_dless(t_btree **ast, t_list *start, t_list *lst);
int		parse_dgreat(t_btree **ast, t_list *start, t_list *lst);
int		parse_lessand(t_btree **ast, t_list *start, t_list *lst);
int		parse_greatand(t_btree **ast, t_list *start, t_list *lst);
int		parse_word(t_btree **ast, t_list *start, t_list *lst);

void	tree_type(t_btree *tree);
#endif
