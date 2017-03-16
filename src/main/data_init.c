/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:26:32 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/16 23:25:46 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char	**environ;

int		data_init(int ac, char **av)
{
	t_data	*data;
	char	*term_name;
	char*	shlvl;

	data = data_singleton();
	data->argc = ac;
	data->argv = ft_sstrdup(av);
	data->env = ft_sstrdup(environ);
	data->local_var = NULL;
	builtin_setenv(NULL, (char *[]){"local", "IFS", "\n ", 0}, NULL);
	set_exitstatus(0, 1);
	shlvl = ft_itoa(ft_atoi(ft_getenv(data->env, "SHLVL")) + 1);
	builtin_setenv(NULL, (char *[]){"setenv", "SHLVL", shlvl, 0}, NULL);
	ft_strdel(&shlvl);
	data->comp = NULL;
	data->opts = 0;
	exec_reset();
	data->lst_func = NULL;
	data->token = NULL;
	data->ast = NULL;
	lexer_init(&data->lexer);
	parser_init(&data->parser);
	if ((term_name = ft_getenv(data->env, "TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, term_name) != 1)
		return (-1);
	return (0);
}
