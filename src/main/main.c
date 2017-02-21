/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:40:58 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/21 14:29:13 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		handle_instruction(int fd)
{
	t_list	*token;
	t_list	*ltoken;
	t_lexer	lexer;
	t_btree	*ast;
	char	*str;

	lexer_init(&lexer);
	token = NULL;
	ast = NULL;
	do {
		str = readline(fd, stack_to_prompt(lexer.stack));
		ft_strappend(&lexer.str, str);
		if (get_lexer_stack(lexer) == BACKSLASH)
			pop(&lexer.stack);
		else if (get_lexer_stack(lexer) == DLESS)
			lexer.state = DLESS;
		ltoken = ft_lstlast(token);
		if (lexer_lex(token ? &ltoken : &token, &lexer))
			return (1);
		//token_print(token);
	} while (get_lexer_stack(lexer));
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

int		get_input_fd()
{
	t_data	*data;

	data = data_singleton();
	if (SH_IS_INTERACTIVE(data->opts))
		return (STDIN);
	/* else if (data->opts & SHELL_OPTS_LC) */
	/* { */
	/* } */
	else
	{
		return (open(shell_get_avdata(), O_RDONLY));
	}
}

int		main(int ac, char **av)
{
	int		fd;

	setlocale(LC_ALL, "");
	shell_init(ac, av);
//	DG("{inv}{bol}{gre}start of shell{eoc} JOBC is %s", SH_HAS_JOBC(data->opts)?"ON":"OFF");
	fd = get_input_fd();
	while (handle_instruction(fd))
	{
		;
	}
	return (0);
}
