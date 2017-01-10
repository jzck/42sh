/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:40:58 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/10 11:56:39 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(void)
{
	t_data	*data;
	t_list	*token;
	t_btree	*ast;

	token = NULL;
	ast = NULL;
	data = data_singleton();
	if (data_init(data))
		return (1);
	if (signal(SIGINT, sig_handler) == SIG_ERR)
		ft_dprintf(STDERR, "\ncan't catch SIGINT\n");
	DG("{inv}{bol}{gre}start of shell");
	while (1)
	{
		if (ft_readline(&data->line))
			return (1);
		DG("{inv}{mag}got command '%s'", data->line.input);
		token = NULL;
		if (ft_tokenize(&token, data->line.input, DEFAULT))
			return (1);
		if (!token)
			continue ;
		token_print(token);
		if (ft_parse(&ast, &token))
			return (1);
		btree_print(STDERR, ast, &ft_putast);
		/* ft_dprintf(STDERR, "\n--- INFIX BREAKDOWN ---\n"); */
		/* btree_apply_infix(ast, &ft_putast2); */
		if (ft_exec(&ast, data))
			return (1);
	}
	return (0);
}
