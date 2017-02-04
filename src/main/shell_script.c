/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_script.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 23:06:34 by ariard            #+#    #+#             */
/*   Updated: 2017/02/04 22:16:49 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		shell_script()
{
	t_list	*token;
	t_btree	*ast;
	t_list	*list_ast;

	token = NULL;
	ast = NULL;
	list_ast = NULL;
	if (ft_lexer(&token, &data_singleton()->script.buffer) || !token)
		return (1);
	DG("after post_tokenize");
	token_print(token);

//	while (token)
//	{
		if (parse(&ast, &token))
			return (1);
		btree_print(STDBUG, ast, &ft_putast);
//		if (ft_exec(&ast))
//			return (1);
		ast = NULL;
//	}
	return (0);
}
