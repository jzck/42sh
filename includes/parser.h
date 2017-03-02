/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:15:54 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/02 22:02:15 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

/*
 * Parse POSIX grammar
 *
*/

enum	e_parstate
{
	ERROR = 0,
	UNDEFINED,
	SUCCESS,
};

# define TK_REDIR(x)			(TK_LESS <= x && x <= TK_GREATAND)

# define MATCH_STACK(x, y)		(x == y || y == ALL)

struct	s_parser
{
	t_parstate	state;
	t_sym		*stack;
	t_sym		*new_sym;
};

struct	s_aggrematch
{
	t_sym 	top;
	t_sym 	under;
	t_sym 	new_sym;
	int	erase_sym;
};

extern t_aggrematch g_aggrematch[];

struct	s_prodmatch
{
	t_type	token;
	t_sym	stack;
	t_sym	new_sym;
};

extern t_prodmatch g_prodmatch[];

struct	s_stackmatch
{
	t_sym top;
	t_sym under;
};

extern t_stackmatch g_stackmatch[];

struct	s_errormatch
{
	t_type	token;
	char	*error;
};

extern t_errormatch	g_errormatch[];

void	parser_init(t_parser *parser);
int		ft_parse(t_btree **ast, t_list **token, t_parser *parser);

int		produce_sym(t_sym stack, t_sym *new_sym, t_list **lst);
int		eval_sym(t_sym stack, t_sym new_sym);
int		aggregate_sym(t_sym **stack, t_sym *new_sym, t_parstate *state);

int		push_stack(t_sym *stack, t_sym new_sym);
int		pop_stack(t_sym **stack, t_sym erase_sym);

int		error_syntax(t_list **token);
int		error_EOF(void);

int		ft_read_stack(t_sym *stack);
char	*read_state(t_sym current);


/*
 * Build AST - rewriting
 *
*/

struct	s_treematch
{
	t_type	type;
	int	(*add)(t_btree **ast, t_list **lst);
};

extern t_treematch g_treematch[];

int		build_tree(t_btree **ast, t_list **lst);

int		add_sep(t_btree **ast, t_list **lst);
int		add_cmd(t_btree **ast, t_list **lst);
int		add_file(t_btree **ast, t_list **lst);
int		add_loop_cmd(t_btree **ast, t_list **lst);
int		add_loop_sep(t_btree **ast, t_list **lst);
int		add_loop_condition(t_btree **ast, t_list **lst);
int		add_condition_cmd(t_btree **ast, t_list **lst);
int		add_condition_sep(t_btree **ast, t_list **lst);
int		add_branch(t_btree **ast, t_list **lst);
int		add_redir_word(t_btree **ast, t_list **lst);
int		add_redir_type(t_btree **ast, t_list **lst);
int		add_case_cmd(t_btree **ast, t_list **lst);
int		add_case_sep(t_btree **ast, t_list **lst);
int		add_pattern(t_btree **ast, t_list **lst);
int		add_subshell_cmd(t_btree **ast, t_list **lst);
int		add_subshell_sep(t_btree **ast, t_list **lst);
int		add_func_cmd(t_btree **ast, t_list **lst);
int		add_func_sep(t_btree **ast, t_list **lst);
int		add_one_func(t_btree **ast, t_list **lst);
int		isloop(t_btree **ast, t_list **lst);
int		iscase(t_btree **ast, t_list **lst);
int		iscondition(t_btree **ast, t_list **lst);
int		issubshell(t_btree **ast, t_list **lst);
int		isfunc(t_btree **ast, t_list **lst);
int		join_ast(t_btree **ast, t_btree **new_node);
int		gen_node(t_btree **ast);
int		isdir(t_btree **ast);
int		iscondition(t_btree **ast, t_list **list);
int		isdir_sep(t_btree **ast, t_list **list);
int		isdir_word(t_btree **ast, t_list **list);

/*
 * Build AST
 *
*/

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

struct	s_cmd
{
	t_list	*redir;
	t_ld	*token;
};

union	u_astdata
{
	t_list	*cmds;
	t_list	*wordlist;
	char	**sstr;
	char	*str;
};

struct	s_astnode
{
	int			pattern;
	int			nest;
	int			full;
	t_type		type;
	t_astdata	data;
};

#endif
