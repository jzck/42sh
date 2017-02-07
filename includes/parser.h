/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:15:54 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/07 12:09:20 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

struct	s_parser
{
	t_type	type;
	int		(*f)(t_btree **ast, t_list **start, t_list **token);
};

union	u_word
{
	char	*word;
	int		fd;
};

struct	s_redir
{
	t_flag	type;
	int		n;
	t_word	word;
	int		close;
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

int		ft_parse(t_btree **ast, t_list **token);
int		parse_separator(t_btree **ast, t_list **start, t_list **lst);
int		parse_redir(t_btree **ast, t_list **start, t_list **lst);
int		parse_less(t_btree **ast, t_list **start, t_list **lst);
int		parse_great(t_btree **ast, t_list **start, t_list **lst);
int		parse_dless(t_btree **ast, t_list **start, t_list **lst);
int		parse_dgreat(t_btree **ast, t_list **start, t_list **lst);
int		parse_lessand(t_btree **ast, t_list **start, t_list **lst);
int		parse_greatand(t_btree **ast, t_list **start, t_list **lst);
int		parse_word(t_btree **ast, t_list **start, t_list **lst);
int		parse_subshell(t_btree **ast, t_list **start, t_list **lst);

#endif
