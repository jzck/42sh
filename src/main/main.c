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

int		main(void)
{
	t_data	data;
	t_list	*token;
	t_btree	*ast;

	data.env = ft_sstrdup(environ);
	if (signal(SIGINT, sig_handler) == SIG_ERR)
		ft_printf("\ncan't catch SIGINT\n");
	while (1)
	{
		if (ft_interactive_sh(&data))
			return (1);
		ft_printf("got command:'%s'\n", data.history->prev->content);
		if (ft_tokenize(&token, data.history->prev->content))
			return (1);
		token_print(token);
		if (ft_parse(&ast, token))
			return (1);
		ft_lstdel(&token, &token_free);
		if (ft_exec(ast))
			return (1);

		/* char **av = ft_cmd_getav(data.history->prev->content); */
		/* if (av && av[0]) */
		/* 	ft_cmd_process(av, &data.env); */
	}
	return (0);
}
