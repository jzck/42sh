/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:35:14 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/15 09:14:30 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(void)
{
	t_data	data;
	t_list	*token;
	t_btree	*ast;

	ast = NULL;
	if (data_init(&data))
		return (1);
	if (signal(SIGINT, sig_handler) == SIG_ERR)
		ft_printf("\ncan't catch SIGINT\n");
	while (1)
	{
		if (ft_interactive_sh(&data))
			return (1);
		ft_printf("got command:'%s'\n", data.input);
		/* if (ft_tokenize(&token, data.history->prev->content)) */
		/* 	return (1); */
		/* token_print(token); */
		/* (void)ast; */
		/* if (ft_parse(&ast, token)) */
		/* 	return (1); */
		/* btree_print(ast, &tree_type); */
		/* ft_printf("root: %i\n", ((t_astnode*)ast->item)->type); */
		/* ft_lstdel(&token, &token_free); */
		token = NULL;
		/* if (ft_exec(ast)) */
		/* 	return (1); */

		/* char **av = ft_cmd_getav(data.history->prev->content); */
		/* if (av && av[0]) */
		/* 	ft_cmd_process(av, &data.env); */
	}
	return (0);
}
