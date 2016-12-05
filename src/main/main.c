/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 21:13:34 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/05 12:11:27 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(void)
{
	t_data	data;
	t_list	*token;
	t_btree	*ast;

	token = NULL;
	ast = NULL;
	if (data_init(&data))
		return (1);
	if (signal(SIGINT, sig_handler) == SIG_ERR)
		ft_dprintf(STDERR, "\ncan't catch SIGINT\n");
	while (1)
	{
		if (ft_interactive_sh(&data))
			return (1);
		/* ft_dprintf(STDERR, "command='%s'\n", data.input); */
		token = NULL;
		if (ft_tokenize(&token, data.line.input, DEFAULT))
			return (1);
		if (!token)
			continue ;
		token_print(token);
		if (ft_parse(&ast, &token))
			return (1);
		btree_print(STDERR, ast, &ft_putast);
		/* ft_dprintf(STDERR, "\n--- INFIX BREAKDOWN ---\n"); */
		/* btree_apply_infix(ast, &ft_putast2); */
		if (ft_exec(&ast, &data))
			return (1);
	}
	return (0);
}
