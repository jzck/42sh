/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:40:58 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/16 15:45:57 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	do_lexer_routine(t_list **token, t_lexer *lexer, t_parser *parser, char *str)
{
	t_list		*ltoken;

	if (lexer->state == HEREDOC || parser->state == UNDEFINED)
	{
		ft_strappend(&lexer->str, (char[]){'\n', 0});
		lexer->pos++;
	}
	ft_strappend(&lexer->str, str);
	if (get_lexer_stack(*lexer) == BACKSLASH)
		pop(&lexer->stack);
	ltoken = ft_lstlast(*token);
	if (lexer_lex(token ? &ltoken : token, lexer) < 1)
		exit(1);
	if (get_lexer_stack(*lexer) > 2)
		return (1);
	lexer->state = DEFAULT;
	return (0);
}

static int	do_parser_routine(t_list **token, t_btree **ast, t_lexer *lexer, t_parser *parser)
{
	if (get_reserved_words(token))
		return (1);
	token_print(*token);
	if (insert_newline(token))
		return (1);
	ft_parse(ast, token, parser);
	if ((lexer->state = data_singleton()->heredoc_queue ? HEREDOC : DEFAULT))
		return (0);
	if (parser->state == ERROR)
	{
		error_syntax(token, parser, ast);
		return (1);
	}
	else if (parser->state == SUCCESS)
		return (1);
	return (0);
}

static int	do_readline_routine(t_lexer *lexer, t_parser *parser, char **str)
{
	int		ret;
	int		has_prompt;

	has_prompt = !(get_lexer_stack(*lexer) || parser->state == UNDEFINED || lexer->state == HEREDOC);
	ret = readline(has_prompt, str);
	if (ret == -1)
		exit(1);
	if (ret == 1 && parser->state == UNDEFINED)
		error_eof();
	return (ret);
}

static int		handle_instruction(t_lexer *lexer, t_parser *parser)
{
	t_list		*token;
	t_btree		*ast;
	int			ret;
	char	*str;

	token = NULL;
	ast = NULL;
	str = NULL;
	while (1)
	{
		if ((ret = do_readline_routine(lexer, parser, &str)) > 0)
			return (ret);
		if (do_lexer_routine(&token, lexer, parser, str) > 0)
			continue ;
		if (do_parser_routine(&token, &ast, lexer, parser) > 0)
			break ;
	}
	/* btree_print(STDBUG, ast, &ft_putast); */
	if (parser->state == SUCCESS && ft_exec(&ast) < 0)
		exit(1);
	if (SH_IS_INTERACTIVE(data_singleton()->opts) && *lexer->str)
		ft_add_str_in_history(lexer->str);
	return (0);
}


int		main(int ac, char **av)
{
	int			ret;
	t_lexer		lexer;
	t_parser	parser;

	g_argv = av;
	setlocale(LC_ALL, "");
	DG("{inv}{bol}{gre}start of shell{eoc}");
	if (shell_init(ac, av))
		return (1);
	lexer_init(&lexer);
	parser_init(&parser);
	DG("JOBC is %s", SH_HAS_JOBC(data_singleton()->opts)?"ON":"OFF");
	while (1)
	{
		ret = handle_instruction(&lexer, &parser);
		/* instruction_free(&token, &ast, &lexer, &parser); */
		if (ret == 1)
			break ;
	}
	builtin_exit(NULL, NULL, NULL);
	return (0);
}
