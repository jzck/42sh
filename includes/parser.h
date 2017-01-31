/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:15:54 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/31 19:31:01 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

typedef struct s_parser		t_parser;
typedef struct s_astnode	t_astnode;
typedef struct s_redir		t_redir;
typedef union u_astdata		t_astdata;
typedef union u_word		t_word;
typedef long long		t_type;

struct	s_parser
{
	t_type	type;
	int		(*f)(t_list **list_ast, t_btree **ast,
			t_list **start, t_list **token);
};

union	u_word
{
	char	*word;
	int		fd;
};

struct	s_redir
{
	int		n;
	int		close;
	t_word	word;
};

union	u_astdata
{
	t_redir	redir;
	char	**sstr;
	char	*str;
};

struct	s_astnode
{
	t_type		type;
	t_astdata	data;
};

extern t_parser		g_parser[];

int		ft_parse(t_list	**list_ast, t_btree **ast, t_list **token);

int		parse_newline(t_list **list_ast, t_btree **ast,
		t_list **start, t_list **lst);
int		parse_separator(t_list **list_ast, t_btree **ast,
		t_list **start, t_list **lst);
int		parse_less(t_list **list_ast, t_btree **ast,
		t_list **start, t_list **lst);
int		parse_great(t_list **list_ast, t_btree **ast,
		t_list **start, t_list **lst);
int		parse_dless(t_list **list_ast, t_btree **ast,
		t_list **start, t_list **lst);
int		parse_dgreat(t_list **list_ast, t_btree **ast,
		t_list **start, t_list **lst);
int		parse_lessand(t_list **list_ast, t_btree **ast,
		t_list **start, t_list **lst);
int		parse_greatand(t_list **list_ast, t_btree **ast,
		t_list **start, t_list **lst);
int		parse_word(t_list **list_ast, t_btree **ast,
		t_list **start, t_list **lst);
int		parse_subshell(t_list **list_ast, t_btree **ast,
		t_list **start, t_list **lst);
int		parse_newline(t_list **list_ast, t_btree **ast,
		t_list **start, t_list **lst);
int		parse_while(t_list **list_ast, t_btree **ast,
		t_list **start, t_list **lst);
int		parse_do(t_list **list_ast, t_btree **ast,
		t_list **start, t_list **lst);
int		parse_done(t_list **list_ast, t_btree **ast,
		t_list **start, t_list **lst);
int		parse_list(t_list **list_ast, t_btree **ast,
		t_list **start, t_list **lst);

#endif
