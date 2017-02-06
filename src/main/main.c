/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:40:58 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/06 14:38:45 by jhalford         ###   ########.fr       */
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
	setlocale(LC_ALL, "");
	DG("{inv}{bol}{gre}start of shell{eoc} job_control is %s", data_singleton()->opts & SHELL_OPTS_JOBC ? "ON" : "OFF");
	shell_init(ac, av);
	if (data_singleton()->opts & SHELL_OPTS_LC)
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
