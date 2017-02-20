/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:40:58 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/20 19:13:50 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		non_interactive_shell(char *command)
{
	t_list	*token;
	t_lexer	lexer;
	t_btree	*ast;

	lexer_init(&lexer);
	lexer.str = command;
	token = NULL;
	ast = NULL;
	while (lexer.str[lexer.pos])
	{
		if (lexer.stack && *(int*)lexer.stack->content == BACKSLASH)
			pop(&lexer.stack);
		do {
			lexer_lex(&token, &lexer);
		} while (lexer.str[lexer.pos] == '\n');
		if (!token)
			return (0);
//		if (bquotes_expand(&token))
//			return (1);
		//token_print(token);
		if (ft_parse(&ast, &token))
			return (1);
		if (ft_exec(&ast))
			return (1);
	}
	return (0);
}

int		interactive_shell()
{
	t_list	*token;
	t_list	*ltoken;
	t_lexer	lexer;
	t_btree	*ast;

	lexer_init(&lexer);
	token = NULL;
	ast = NULL;
	do {
		ft_strappend(&lexer.str, readline(stack_to_prompt(lexer.stack)));
		if (get_lexer_stack(lexer) == BACKSLASH)
			pop(&lexer.stack);
		else if (get_lexer_stack(lexer) == DLESS)
			lexer.state = DLESS;
		ltoken = ft_lstlast(token);
		if (lexer_lex((token ? &ltoken : &token), &lexer))
			return (1);
		//token_print(token);
	} while (get_lexer_stack(lexer));
//	if (bquotes_expand(&token))
//		return (1);
	if (!token)
		return (0);
	ft_add_str_in_history(lexer.str);
	if (ft_parse(&ast, &token))
		return (1);
	btree_print(STDBUG, ast, &ft_putast);
	if (ft_exec(&ast))
		return (1);
	ft_strdel(&lexer.str);
	return (0);
}

int		main(int ac, char **av)
{
	t_data	*data;

	data = data_singleton();
	setlocale(LC_ALL, "");
	shell_init(ac, av);
//	DG("{inv}{bol}{gre}start of shell{eoc} JOBC is %s", SH_HAS_JOBC(data->opts)?"ON":"OFF");
	if (SH_IS_INTERACTIVE(data->opts))
	{
		while (1)
			interactive_shell();
	}
	else
		non_interactive_shell(shell_get_avdata());
	return (0);
}
