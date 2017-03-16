/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:40:58 by jhalford          #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	do_readline_routine(char **stream)
{
	int		ret;
	int		has_prompt;
	t_data	*data;

	data = data_singleton();
	has_prompt = !(get_lexer_stack(data->lexer) 
		|| data->parser.state == UNDEFINED || data->lexer.state == HEREDOC);
	ret = readline(has_prompt, stream);
	if (ret == -1)
		exit(1);
	if (ret == 1 && data->parser.state == UNDEFINED)
		error_eof();
	return (ret);
}

static int	do_lexer_routine(char *stream)
{
	t_list		*ltoken;
	t_data		*data;

	data = data_singleton();
	if (data->lexer.state == HEREDOC || data->parser.state == UNDEFINED)
	{
		ft_strappend(&data->lexer.str, (char[]){'\n', 0});
		data->lexer.pos++;
	}
	ft_strappend(&data->lexer.str, stream);
	if (get_lexer_stack(data->lexer) == BACKSLASH)
		pop(&data->lexer.stack);
	ltoken = ft_lstlast(data->token);
	if (lexer_lex(data->token ? &ltoken : &data->token, &data->lexer) < 0)
		exit(1);
	if (get_lexer_stack(data->lexer) > 2)
		return (1);
	data->lexer.state = DEFAULT;
	return (0);
}

static int	do_parser_routine(void)
{
	t_data		*data;

	data = data_singleton();
	if (get_reserved_words(&data->token))
		return (1);
	if (insert_newline(&data->token))
		return (1);
	if (data->parser.state == SUCCESS && stack_init(&data->parser))
		exit(1);
	if (ft_parse(&data->ast, &data->token, &data->parser))
		exit(1);
	if ((data->lexer.state = data->parser.heredoc_queue ? HEREDOC : DEFAULT))
		return (0);
	if (data->parser.state == ERROR)
	{
		error_syntax(&data->token);
		return (1);
	}
	else if (data->parser.state == SUCCESS)
		return (1);
	return (0);
}

static int		handle_instruction()
{
	int			ret;
	char		*stream;
	t_data		*data;

	stream = NULL;
	data = data_singleton(); 
	while (1)
	{
		if ((ret = do_readline_routine(&stream)) > 0)
			return (ret);
		if (do_lexer_routine(stream) > 0)
			continue ;
		if (do_parser_routine() > 0)
			break ;
	}
	/* btree_print(STDBUG, ast, &ft_putast); */
	if (data->parser.state == SUCCESS && ft_exec(&data->ast) < 0)
		exit(1);
	if (SH_IS_INTERACTIVE(data->opts) && data->lexer.str)
		ft_add_str_in_history(data->lexer.str);
	return (0);
}

int		main(int ac, char **av)
{
	int			ret;
	t_data		*data;

	g_argv = av;
	setlocale(LC_ALL, "");
	DG("{inv}{bol}{gre}start of shell{eoc}");
	if (shell_init(ac, av))
		return (1);
	DG("JOBC is %s", SH_HAS_JOBC(data_singleton()->opts)?"ON":"OFF");
	data = data_singleton();
	while (1)
	{
		ret = handle_instruction();
		lexer_destroy(&data->lexer);
		parser_destroy(&data->parser);
		ft_lstdel(&data->token, &ft_lst_cfree);
		btree_del(&data->ast, &ft_lst_cfree);
		if (ret == 1)
			break ;
	}
	builtin_exit(NULL, NULL, NULL);
	return (0);
}
