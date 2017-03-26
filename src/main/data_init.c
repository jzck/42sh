/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:26:32 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/26 21:54:19 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		path_binary_save(char *binary)
{
	char	*directory;

	if (binary[0] != '/')
	{
		if (!(directory = getcwd(NULL, 0)))
			return (1);
		while (binary[0] == '.' && binary[1] == '/')
			binary += 2;
		binary = ft_strjoin(
				directory[ft_strlen(directory) - 1] != '/' ? "/" : "", binary);
		binary = ft_strjoinf(directory, binary, 3);
	}
	else
		binary = ft_strdup(binary);
	if (access(binary, F_OK | X_OK))
		return (1);
	data_singleton()->binary = binary;
	return (0);
}

static int		localenv_init(void)
{
	t_data	*data;
	char	*pid;

	pid = ft_itoa(getpid());
	data = data_singleton();
	data->local_var = NULL;
	builtin_setenv(NULL, (char *[]){"local", "IFS", " \t\n", 0}, NULL);
	builtin_setenv(NULL, (char *[]){"local", "PS2", " >", 0}, NULL);
	ft_strdel(&pid);
	return (0);
}

static int		shlvl_inc(void)
{
	t_data	*data;
	char	*shlvl;

	data = data_singleton();
	if ((shlvl = ft_getenv(data->env, "SHLVL")))
	{
		if (!(shlvl = ft_itoa(ft_atoi(shlvl) + 1)))
			return (-1);
	}
	else if (!(shlvl = ft_strdup("1")))
		return (-1);
	builtin_setenv(NULL, (char *[]){"setenv", "SHLVL", shlvl, 0}, NULL);
	ft_strdel(&shlvl);
	return (0);
}

int				data_init(int ac, char **av, char **env)
{
	t_data	*data;
	char	*term_name;

	data = data_singleton();
	data->argc = ac;
	data->argv = ft_sstrdup(av);
	data->env = ft_sstrdup(env);
	data->c_arg = NULL;
	set_exitstatus(0, 1);
	localenv_init();
	if (shlvl_inc())
		return (-1);
	data->comp = NULL;
	data->opts = SH_INTERACTIVE | SH_OPTS_JOBC;
	data->lst_func = NULL;
	lexer_init(&data->lexer);
	parser_init(&data->parser);
	exec_init(&data->exec);
	if ((term_name = ft_getenv(data->env, "TERM")) == NULL)
		term_name = "dumb";
	if (tgetent(NULL, term_name) != 1)
		return (SH_ERR("TERM name is not a tty") ? -1 : -1);
	if (path_binary_save(av[0]))
		return (SH_ERR("Failed to resolve binary name") ? -1 : -1);
	return (0);
}
