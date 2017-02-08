/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:40:58 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/07 17:18:21 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		shell_single_command(char *command)
{
	t_list	*token;
	t_btree	*ast;

	token = NULL;
	ast = NULL;

	DG("{inv}{mag}got command '%s'", command);
	if (ft_lexer(&token, &command) || !token)
		return (1);

	token_print(token);
	if (ft_parse(&ast, &token))
		return (1);

	btree_print(STDBUG, ast, &ft_putast);
	if (ft_exec(&ast))
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	t_data	*data;

	data = data_singleton();
	setlocale(LC_ALL, "");
	DG("{inv}{bol}{gre}start of shell{eoc} pid=%i pgrp=%i job_control is %s", getpid(), getpgrp(), SH_HAS_JOBC(data->opts) ? "ON" : "OFF");
	shell_init(ac, av);
	DG("{inv}{bol}{gre}start of shell{eoc} pid=%i pgrp=%i job_control is %s", getpid(), getpgrp(), SH_HAS_JOBC(data->opts) ? "ON" : "OFF");
	if (data_singleton()->opts & SH_OPTS_LC)
	{
		shell_single_command(ft_strdup(shell_get_avdata()));
		return (0);
	}
	while (1)
	{
		if (ft_readline())
			return (1);
		if (shell_single_command(ft_strdup(data_singleton()->line.input)) < 0)
			return (1);
	}
	return (0);
}
