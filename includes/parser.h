/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:31:42 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/14 18:22:04 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

typedef long long			t_type;
typedef struct s_parser		t_parser;
typedef struct s_astnode	t_astnode;
typedef struct s_redir		t_redir;

struct s_parser
{
	t_type	type;
	int		(*f)(t_btree **ast, t_list *start, t_list *token);
};

struct s_redir
{
	int		n;
	union u_word
	{
		char	*word;
		int		fd;
	} word;
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
