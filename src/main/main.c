/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:40:58 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/13 12:05:51 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(void)
{
	t_list	*token;
	t_btree	*ast;
	t_data	*data;

	token = NULL;
	ast = NULL;
	data = data_singleton();
	shell_init();
	DG("{inv}{bol}{gre}start of shell");
	while (1)
	{
		if (ft_interactive_sh(data))
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
		if (ft_exec(&ast))
			return (1);
	}
	return (0);
}
