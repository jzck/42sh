/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 16:21:05 by ariard            #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			pop_heredoc(t_list **lst)
{
	t_token	*token;
	t_list	*temp;
	t_redir	*head;

	temp = NULL;
	token = (*lst)->content;
	if (token->type == HEREDOCDATA && data_singleton()->heredoc_queue != NULL)
	{
		temp = data_singleton()->heredoc_queue;
		head = temp->content;
		if (head && token)
		{
			if (ft_strcmp((char *)token->data, head->word) == 0)
				ft_lst_removeif(&data_singleton()->heredoc_queue, temp->content, &ft_addrcmp);
			else
			{
				head->heredoc_data = ft_strjoin(head->heredoc_data,
					token->data);
				head->heredoc_data = ft_strjoin(head->heredoc_data, "\n");
			}
		}
		ft_lstdel(lst, &token_free);
		return (1);
	}
	return (0);
}
