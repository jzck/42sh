/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:15:54 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/05 23:44:43 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

typedef struct s_parser		t_parser;
typedef struct	s_ld		t_ld;
typedef struct s_astnode	t_astnode;
typedef struct s_redir		t_redir;
typedef union u_astdata		t_astdata;
typedef union u_word		t_word;
typedef long long		t_type;

struct	s_parser
{
	t_type	type;
	int		(*f)(t_btree **ast,
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
	t_ld	*token;
	char	**sstr;
	char	*str;
};

struct	s_astnode
{
	t_type		type;
	t_astdata	data;
};

extern t_parser		g_parser[];

int		parse(t_btree **ast, t_list **token);

int		ft_parse(t_btree **ast, t_list **token);
int		get_instruction(t_list **lst);
int		get_sub_instruction(t_btree **ast, t_list **start, t_list **lst);

int		parse_newline(t_btree **ast, t_list **start, t_list **lst);
int		parse_separator(t_btree **ast, t_list **start, t_list **lst);
int		parse_less(t_btree **ast, t_list **start, t_list **lst);
int		parse_great(t_btree **ast, t_list **start, t_list **lst);
int		parse_dless(t_btree **ast, t_list **start, t_list **lst);
int		parse_dgreat(t_btree **ast, t_list **start, t_list **lst);
int		parse_lessand(t_btree **ast, t_list **start, t_list **lst);
int		parse_greatand(t_btree **ast, t_list **start, t_list **lst);
int		parse_word(t_btree **ast, t_list **start, t_list **lst);
int		parse_subshell(t_btree **ast, t_list **start, t_list **lst);
int		parse_newline(t_btree **ast, t_list **start, t_list **lst);
int		parse_while(t_btree **ast, t_list **start, t_list **lst);
int		parse_if(t_btree **ast, t_list **start, t_list **lst);
int		parse_do(t_btree **ast, t_list **start, t_list **lst);
int		parse_done(t_btree **ast, t_list **start, t_list **lst);
int		parse_list(t_btree **ast, t_list **start, t_list **lst);

int		delete_newline(t_list **start, t_list **lst);

#endif
