/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:35:14 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/11 17:10:01 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char	**environ;
int			g_mode;

int		main(void)
{
	t_data	data;
	char	*cmd;
	char	**av;
	t_list	*token;

	data.env = ft_sstrdup(environ);
	token = NULL;
	if (signal(SIGINT, sig_handler) == SIG_ERR)
		ft_printf("\ncan't catch SIGINT\n");
	while (1)
	{
		g_mode = MODE_INPUT;
		if (ft_interactive_sh(&data))
			return (1);
		cmd = ft_strdup(data.history->prev->content);
		g_mode = MODE_EXEC;

		ft_printf("got command:'%s'\n", cmd);

		/* (void)av; */
		/* ft_printf("got string:'%s'\n", cmd); */

		/* av = ft_cmd_getav(cmd); */
		/* if (av && av[0]) */
		/* 	ft_cmd_process(av, &data.env); */

		(void)av;
		if (ft_tokenize(&token, cmd))
			return (1);
	}
	return (0);
}
