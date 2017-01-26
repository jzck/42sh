/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:40:58 by jhalford          #+#    #+#             */
<<<<<<< HEAD:src/main/main.c
/*   Updated: 2017/01/12 14:02:30 by jhalford         ###   ########.fr       */
=======
/*   Updated: 2017/01/05 16:07:09 by wescande         ###   ########.fr       */
>>>>>>> premier commit. working. . .:srcs/main/main.c
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		shell_single_command(char *command)
{
	t_list	*token;
	t_btree	*ast;

	token = NULL;
	ast = NULL;
	if (!command)
		return (0);
	DG("{inv}{mag}got command '%s'", command);
	if (ft_tokenize(&token, command, DEFAULT))
		return (1);
	if (!token)
		return (0);
	token_print(token);
	if (ft_post_tokenize(&token, command))
		return (1);
	DG("after post_tokenize");
	token_print(token);
	if (ft_parse(&ast, &token))
		return (1);
	/* btree_print(STDBUG, ast, &ft_putast); */
	/* /1* ft_dprintf(STDBUG, "\n--- INFIX BREAKDOWN ---\n"); *1/ */
	/* /1* btree_apply_infix(ast, &ft_putast2); *1/ */
	if (ft_exec(&ast))
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	DG("{inv}{bol}{gre}start of shell{eoc} job_control is %s", data_singleton()->opts & SHELL_OPTS_JOBC ? "ON" : "OFF");
	shell_init(ac, av);
	if (data_singleton()->opts & SHELL_OPTS_LC)
	{
		shell_single_command(shell_get_avdata());
		return (0);
	}
	while (1)
	{
<<<<<<< HEAD:src/main/main.c
		if (ft_readline())
=======
		if (ft_interactive_sh(&data))
			return (1);
		DG("{inv}{mag}got command '%s'", data.line.input);
		token = NULL;
		if (ft_tokenize(&token, data.line.input, DEFAULT))
			return (1);
		if (!token)
			continue ;
//		token_print(token);
		glob_print(token, &data);
		if (ft_parse(&ast, &token))
>>>>>>> premier commit. working. . .:srcs/main/main.c
			return (1);
		if (shell_single_command(data_singleton()->line.input))
			return (1);
	}
	return (0);
}
