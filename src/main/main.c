/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 14:45:40 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/20 20:31:21 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		do_readline_routine(char **stream)
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

static int		handle_instruction(t_list **token, t_btree **ast)
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
		if (do_lexer_routine(token, stream) > 0)
			continue ;
		if (do_parser_routine(token, ast) > 0)
			break ;
	}
	if (data->parser.state == SUCCESS && ft_exec(ast) < 0)
		exit(1);
	else if (data->parser.state != SUCCESS)
		set_exitstatus(1, 1);
	if (SH_IS_INTERACTIVE(data->opts) && data->lexer.str)
		ft_add_str_in_history(data->lexer.str);
	return (0);
}

int				main(int ac, char **av)
{
	int			ret;
	t_data		*data;
	t_list		*token;
	t_btree		*ast;

	g_argv = av;
	setlocale(LC_ALL, "");
	if (shell_init(ac, av) != 0)
		return (1);
	token = NULL;
	ast = NULL;
	data = data_singleton();
	while (1)
	{
		ret = handle_instruction(&token, &ast);
		lexer_destroy(&data->lexer);
		parser_destroy(&data->parser);
		ft_lstdel(&data_singleton()->exec.op_stack, &ft_lst_cfree);
		ft_lstdel(&token, &token_free);
		btree_del(&ast, &ast_free);
		if (ret == 1)
			break ;
	}
	builtin_exit(NULL, NULL, NULL);
	return (0);
}
