/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_script.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 23:06:34 by ariard            #+#    #+#             */
/*   Updated: 2017/01/22 23:32:27 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		shell_script()
{
	t_list	*token;
	t_btree	*ast;
	t_list	*tmp;

	token = NULL;
	ast = NULL;
	tmp = data_singleton()->script.queue;
	while (tmp)
	{
		if (ft_tokenize(&token, tmp->content , DEFAULT))
			return (1);
		tmp = tmp->next;
	}
	if (!token)
		return (0);
//	if (ft_post_tokenize(&token, command))
//		return (1);
	DG("after post_tokenize");
	token_print(token);
	if (ft_parse(&ast, &token))
		return (1);
	btree_print(STDBUG, ast, &ft_putast);
	if (ft_exec(&ast))
		return (1);
	return (0);
}
