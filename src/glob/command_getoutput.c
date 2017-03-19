/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_getoutput.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 19:44:25 by wescande          #+#    #+#             */
/*   Updated: 2017/03/19 17:42:45 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#define BUF_SIZE	1024

static char		*manage_output(int *fds)
{
	int			ret;
	char		buf[BUF_SIZE + 1];
	char		*output;

	output = NULL;
	close(fds[PIPE_WRITE]);
	while ((ret = read(fds[PIPE_READ], buf, BUF_SIZE)) > 0)
	{
		buf[ret] = 0;
		ft_strappend(&output, buf);
	}
	close(fds[PIPE_READ]);
	return (output);
}

static char		*manage_command(char *const av_cmd[])
{
	char	*command;
	int		i;

	if (!av_cmd)
		return (NULL);
	i = -1;
	command = NULL;
	while (av_cmd[++i])
	{
		if (!command)
			command = ft_str3join("\"", av_cmd[i], "\"");
		else
			command = ft_strjoinf(command, ft_str3join("\"", av_cmd[i], "\""), 3);
	}
	return (command);
}

static void		execute_command(char *command, char *const av[], char **env)
{
	t_list		*token;
	t_btree		*ast;
	t_data		*data;

	token = NULL;
	ast = NULL;
	data = data_singleton();
	data->env = env;
	data->opts &= ~SH_INTERACTIVE;
	data->opts &= ~SH_OPTS_JOBC;
	command = command ? command : manage_command(av);
	DG("command is %s", command);
	if (do_lexer_routine(&token, command))
	{
		ft_dprintf(2, "{red}%s: syntax error in command substitution{eoc}\n",
				SHELL_NAME);
		exit(1);
	}
	if (do_parser_routine(&token, &ast) <= 0)
	{
		ft_dprintf(2, "{red}%s: parse error in command substitution{eoc}\n",
				SHELL_NAME);
		exit(1);
	}
	exit(data_singleton()->parser.state == SUCCESS && ft_exec(&ast) < 0);
}

char			*command_getoutput(char *command, char *const av[], char **env, int pipe_mode)
{
	int			ret;
	int			pid;
	int			fds[2];

	if (!command && !av)
		return (NULL);
	if (pipe_mode)
		pipe(fds);
	if (!(pid = fork()))
	{
		if (pipe_mode)
		{
			close(fds[PIPE_READ]);
			dup2_close(fds[PIPE_WRITE], STDOUT);
		}
		execute_command(command, av, env);
	}
	waitpid(pid, &ret, WUNTRACED);
	if (pipe_mode)
		return (manage_output(fds));
	return (NULL);
}
