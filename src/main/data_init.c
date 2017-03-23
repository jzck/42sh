/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:26:32 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/23 06:19:27 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char	**environ;

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

int				data_init(int ac, char **av)
{
	t_data	*data;
	char	*term_name;

	data = data_singleton();
	data->argc = ac;
	data->argv = ft_sstrdup(av);
	data->env = ft_sstrdup(environ);
	data->c_arg = NULL;
	set_exitstatus(0, 1);
	localenv_init();
	if (shlvl_inc())
		return (-1);
	data->comp = NULL;
	data->opts = SH_INTERACTIVE | SH_OPTS_JOBC;
	exec_reset();
	data->lst_func = NULL;
	lexer_init(&data->lexer);
	parser_init(&data->parser);
	/* if (!ft_getenv(data_singleton()->env, "FUNC_LVL")) */
	/* 	builtin_setenv("setenv", (char *[]){"env", "FUNC_LVL", "-1", */
		/* NULL}, NULL); */
	if ((term_name = ft_getenv(data->env, "TERM")) == NULL)
	{
		term_name = "dumb";
		/* ft_dprintf(2, "{red}TERM not set\n{eoc}"); */
		/* return (-1); */
	}
	if (tgetent(NULL, term_name) != 1)
	{
		ft_dprintf(2, "{red}TERM name is not a tty\n{eoc}");
		return (-1);
	}
	return (0);
}
