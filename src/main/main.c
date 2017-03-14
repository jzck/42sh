/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:40:58 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/14 21:50:56 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		handle_instruction(int fd)
{
	t_list		*token;
	t_list		*ltoken;
	t_lexer		lexer;
	t_parser	parser;
	t_btree		*ast;
	char		*str;
	int			ret;

	lexer_init(&lexer);
	parser_init(&parser);
	token = NULL;
	ast = NULL;
	while (1)
	{
		if ((ret = readline(fd, get_lexer_stack(lexer) ||
			parser.state == UNDEFINED || lexer.state == HEREDOC, &str)))
		{
			if (ret == -1)
				return (-1);
			return (parser.state == UNDEFINED ? error_eof(&token,
			&parser, &ast) : 1);
		}
		if (lexer.state == HEREDOC)
		{
			ft_strappend(&lexer.str, (char[]){'\n', 0});
			lexer.pos++;
		}
		ft_strappend(&lexer.str, str);
		if (get_lexer_stack(lexer) == BACKSLASH)
			pop(&lexer.stack);
		ltoken = ft_lstlast(token);
		if (lexer_lex(token ? &ltoken : &token, &lexer))
			return (1);
		if (get_lexer_stack(lexer) > 2)
			continue ;
		lexer.state = DEFAULT;
		if (get_reserved_words(&token))
			return (1);
		token_print(token);
		if (insert_newline(&token))
			return (1);
		if (ft_parse(&ast, &token, &parser))
			continue ;
		if (parser.state == ERROR)
			error_syntax(&token, &parser, &ast);
		lexer.state = data_singleton()->heredoc_queue ? HEREDOC : 0;
		if (lexer.state)
			continue;
		else if (parser.state == SUCCESS)
			break ;
		else if (parser.state == ERROR && SH_IS_INTERACTIVE(data_singleton()->opts))
		{
			ft_add_str_in_history(lexer.str);
			return (error_syntax(&token, &parser, &ast));
		}
	}
	btree_print(STDBUG, ast, &ft_putast);
	if (ft_exec(&ast))
		return (1);
	instruction_free(&token, &parser, &ast);
	if (SH_IS_INTERACTIVE(data_singleton()->opts) && *lexer.str)
		ft_add_str_in_history(lexer.str);
	ft_strdel(&lexer.str);
	free(parser.new_sym);
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
		fd = fds[PIPE_READ];
		file = *cliopts_getdata(av);
		write(fds[PIPE_WRITE], file, ft_strlen(file));
		close(fds[PIPE_WRITE]);
		fcntl(fd, F_SETFD, FD_CLOEXEC);
		return (fd);
	}
	else if ((file = *cliopts_getdata(av)))
	{
		stat(file, &buf);
		fd = -1;
		if (S_ISDIR(buf.st_mode))
			ft_printf("{red}%s: %s: is a directory\n{eoc}", g_argv[0], file);
		else if ((fd = open(file, O_RDONLY | O_CLOEXEC)) < 0)
			ft_printf("{red}%s: %s: No such file or directory\n{eoc}", g_argv[0], file);
		return (fd);
	}
	return (STDIN);
}

int		main(int ac, char **av)
{
	int		fd;

	g_argv = av;
	setlocale(LC_ALL, "");
	DG("{inv}{bol}{gre}start of shell{eoc}");
	if (shell_init(ac, av))
		return (1);
	if ((fd = get_input_fd(av)) < 0)
		return (1);
	DG("JOBC is %s, fd=[%i]", SH_HAS_JOBC(data_singleton()->opts)?"ON":"OFF", fd);
	while (handle_instruction(fd) == 0)
		;
	builtin_exit(NULL, NULL, NULL);
	return (0);
}
