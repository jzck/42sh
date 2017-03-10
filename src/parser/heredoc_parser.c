/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 16:21:05 by ariard            #+#    #+#             */
/*   Updated: 2017/03/10 13:19:06 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			pop_heredoc(t_list **lst)
{
	t_token	*token;
	t_list	*temp;
	t_list	*temp2;
	t_redir	*head;

	temp = NULL;
	token = (*lst)->content;
	if (token->type == HEREDOCDATA && data_singleton()->heredoc_queue)
	{
		head = data_singleton()->heredoc_queue->content;
		temp = data_singleton()->heredoc_queue;
		DG("compare %s with %s", (char *)token->data, head->word);
		if (head && token && ft_strcmp((char *)token->data, head->word) == 0)
		{
			DG();
			temp2 = temp->next;
			free(temp);
			data_singleton()->heredoc_queue = temp2;
		}
		else if (token)
			head->heredoc_data = ft_strjoin(head->heredoc_data, token->data);
		ft_lstdel(lst, &token_free);
		return (1);
	}
	return (0);
}
