/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:40:58 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/10 14:00:17 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(void)
{
	t_list	*token;
	t_btree	*ast;

	token = NULL;
	ast = NULL;
	shell_init();
	DG("{inv}{bol}{gre}start of shell");
	while (1)
	{
		if (ft_readline(&data_singleton()->line))
			return (1);
		DG("{inv}{mag}got command '%s'", data_singleton()->line.input);
		token = NULL;
		if (ft_tokenize(&token, data_singleton()->line.input, DEFAULT))
			return (1);
		if (!token)
			continue ;
		token_print(token);
		if (ft_parse(&ast, &token))
			return (1);
		btree_print(STDBUG, ast, &ft_putast);
		/* ft_dprintf(STDBUG, "\n--- INFIX BREAKDOWN ---\n"); */
		/* btree_apply_infix(ast, &ft_putast2); */
		if (ft_exec(&ast))
			return (1);
	}
	return (0);
}
