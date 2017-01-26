/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_script.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 23:06:34 by ariard            #+#    #+#             */
/*   Updated: 2017/01/26 22:42:07 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		shell_script()
{
	t_list	*token;
	t_btree	*ast;
	t_list	*list_ast;
	t_list	*tmp2;

	token = NULL;
	ast = NULL;
	list_ast = NULL;
	if (ft_tokenize(&token, data_singleton()->script.buffer , DEFAULT))
		return (1);
	if (!token)
		return (0);
	if (ft_post_tokenize(&token, data_singleton()->script.buffer))
		return (1);
	DG("after post_tokenize");
	token_print(token);
	if (ft_parse(&list_ast, &ast, &token))
		return (1);
	tmp2 = list_ast;
	while (tmp2)
	{
		btree_print(STDBUG, tmp2->content, &ft_putast);
		tmp2 = tmp2->next;
	}
	return (0);
	while (list_ast)
	{
		ast = list_ast->content;
		if (ft_exec(&ast))
			return (1);
		list_ast = list_ast->next;
	}
	return (0);
}
