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

	if (data_init(&data))
		return (1);
	if (signal(SIGINT, sig_handler) == SIG_ERR)
		ft_printf("\ncan't catch SIGINT\n");
	while (1)
	{
		if (ft_interactive_sh(&data))
			return (1);
		ft_printf("command='%s'\n", data.input);
		if (ft_tokenize(&token, data.input, DEFAULT))
			return (1);
		token_print(token);
		ast = NULL;
		if (ft_parse(&ast, &token))
			return (1);
		btree_print(ast, &ft_putast);
		ft_printf("\n--- INFIX BREAKDOWN ---\n");
		btree_apply_infix(ast, &ft_putast2);
		/* ft_lstdel(&token, &token_free); */
		token = NULL;
		if (ft_exec(ast))
			return (1);

	}
	return (0);
}
