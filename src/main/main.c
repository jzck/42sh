/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:40:58 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/16 15:02:12 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	do_lexer_routine(t_list **token, t_lexer *lexer)
{
	t_list		*ltoken;

	if (lexer->state == HEREDOC)
	{
		ft_strappend(&lexer->str, (char[]){'\n', 0});
		lexer->pos++;
	}
	ft_strappend(&lexer->str, str);
	if (get_lexer_stack(lexer) == BACKSLASH)
		pop(&lexer->stack);
	ltoken = ft_lstlast(*token);
	if (lexer_lex(token ? &ltoken : token, lexer) < 1)
		exit(1);
	if (get_lexer_stack(lexer) > 2)
		return (1);
	lexer->state = DEFAULT;
	return (0);
}

static int	do_parser_routine(t_list **token, t_lexer *lexer, t_parser *parser)
{
	if (get_reserved_words(token))
		return (1);
	token_print(*token);
	if (insert_newline(token))
		return (1);
	ft_parse(ast, token, &parser);
	if ((lexer->state = data_singleton()->heredoc_queue ? HEREDOC : DEFAULT))
		return (0);
	if (parse->state == ERROR)
	{
		error_syntax(token, &parser, ast);
		return (1);
	}
	else if (parser->state == SUCCESS)
		return (1);
	return (0);
}

static int	do_readline_routine(t_list **token, t_lexer *lexer, t_parser *parser)
{
	int		ret;
	int		prompt;
	char	*str;

	has_prompt = !(get_lexer_stack(lexer) || parser->state == UNDEFINED || lexer->state == HEREDOC);
	ret = readline(has_prompt, &str);
	{
		if (ret == -1)
			return (-1);
		return (parser.state == UNDEFINED ? error_eof(token,
				&parser, ast) : 1);
	}
}

static int		handle_instruction( t_list **token,
		t_btree **ast,
		t_lexer *lexer,
		t_parser *parser)
{

	while (1)
	{
		if (do_readline_routine(lexer, parser) > 0)
		if (do_lexer_routine(token, lexer) > 0)
			continue ;
		if (do_parser_routine(token, lexer, parser) > 0)
			break ;
	}
	/* btree_print(STDBUG, ast, &ft_putast); */
	if (parser->state == SUCCESS && ft_exec(ast) < 0)
		exit(1);
	if (SH_IS_INTERACTIVE(data_singleton()->opts) && *lexer->str)
		ft_add_str_in_history(lexer->str);
	return (0);
}

int		get_input_fd(char **av)
{
	t_data		*data;
	char		*file;
	int			fds[2];
	int			fd;
	struct stat	buf;

	data = data_singleton();
	if (SH_IS_INTERACTIVE(data->opts))
		return (STDIN);
	else if (data->opts & SH_OPTS_LC)
	{
		pipe(fds);
		dup2_close(fds[PIPE_READ], 10);
		fd = 10;
		file = *cliopts_getdata(av);
		write(fds[PIPE_WRITE], file, ft_strlen(file));
		close(fds[PIPE_WRITE]);
		fcntl(fd, F_SETFD, FD_CLOEXEC);
		return (fd);
	}
	else if ((file = *cliopts_getdata(av)) && !stat(file, &buf))
	{
		fd = -1;
		if (S_ISDIR(buf.st_mode))
			ft_printf("{red}%s: %s: is a directory\n{eoc}", av[0], file);
		else if ((fd = open(file, O_RDONLY | O_CLOEXEC)) < 0)
			ft_printf("{red}%s: %s: No such file or directory\n{eoc}", av[0], file);
		if (fd > 0 && !dup2_close(fd, 10) && (fd = 10))
			return (fd);
	}
	return (STDIN);
}

int		main(int ac, char **av)
{
	int		fd;
	t_list		*token;
	t_lexer		lexer;
	t_parser	parser;
	t_btree		*ast;

	g_argv = av;
	setlocale(LC_ALL, "");
	DG("{inv}{bol}{gre}start of shell{eoc}");
	if (shell_init(ac, av))
		return (1);
	if ((fd = get_input_fd(av)) < 0)
		return (1);
	dup2_close(fd, STDIN);
	lexer_init(&lexer);
	parser_init(&parser);
	token = NULL;
	ast = NULL;
	DG("JOBC is %s, fd=[%i]", SH_HAS_JOBC(data_singleton()->opts)?"ON":"OFF", fd);
	while (handle_instruction(&token, &ast, lexer, parser) == 0)
	{
		instruction_free(&token, &ast, &lexer, &parser);
	}
	builtin_exit(NULL, NULL, NULL);
	return (0);
}
