/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_script.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 23:06:34 by ariard            #+#    #+#             */
/*   Updated: 2017/01/24 20:14:52 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		shell_script()
{
	t_list	*token;
	t_list	*head;
	t_btree	*ast;
	t_list	*list_tmp;
	t_list	*tmp2;

	token = NULL;
	head = NULL;
	ast = NULL;
	list_tmp = data_singleton()->script.queue;
	while (list_tmp)
	{
		if (ft_tokenize(&token, list_tmp->content , DEFAULT))
			return (1);
		if (!token && !list_tmp->next)
			return (0);
		if (ft_post_tokenize(&token, list_tmp->content))
			return (1);
		list_tmp = list_tmp->next;
		ft_lst_merge(&head, token);
		token = NULL; 
	}
	DG("after post_tokenize");
	token_print(head);
	list_tmp = NULL;
	while (head)
	{
		if (ft_parse(&ast, &head))
			return (1);
		ft_lsteadd(&list_tmp, ft_lstnew(ast, sizeof(*ast)));
		ast = NULL;
		ft_lst_delif(&head, head->content, &ft_addrcmp, &token_free);
	}
	tmp2 = list_tmp;
	while (tmp2)
	{		
		btree_print(STDBUG, tmp2->content, &ft_putast);
		tmp2 = tmp2->next;
	}
	while (list_tmp)
	{
		ast = list_tmp->content;
		if (ft_exec(&ast))
			return (1);
		list_tmp = list_tmp->next;
	}
	return (0);
}
