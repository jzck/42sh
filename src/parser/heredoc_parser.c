/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 16:21:05 by ariard            #+#    #+#             */
/*   Updated: 2017/03/08 23:18:29 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			pop_heredoc(t_list **heredoc_queue, t_list **lst)
{
	t_token	*token;
	t_list	*temp;
	t_list	*temp2;
	t_redir	*head;

	temp = NULL;
	if (!heredoc_queue && !*heredoc_queue)
		return (0);
	token = (*lst)->content;
	if (token->type == HEREDOCDATA)
	{
		head = data_singleton()->heredoc_queue->content;
		temp = data_singleton()->heredoc_queue;
		DG("compare %s with %s", (char *)token->data, head->word);
		if (head && ft_strcmp((char *)token->data, head->word) == 0)
		{
			temp2 = temp->next;
			free(temp);
			data_singleton()->heredoc_queue = temp2;
		}
		else
			head->heredoc_data = ft_strjoin(head->heredoc_data, token->data);
		ft_lstdel(lst, &token_free);
		return (1);
	}
	return (0);
}
