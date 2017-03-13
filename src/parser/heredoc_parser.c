/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 16:21:05 by ariard            #+#    #+#             */
/*   Updated: 2017/03/11 20:01:42 by ariard           ###   ########.fr       */
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
	if (token->type == HEREDOCDATA && data_singleton()->heredoc_queue != NULL)
	{
		head = data_singleton()->heredoc_queue->content;
		temp = data_singleton()->heredoc_queue;
		if (head && token)
		{
			if (ft_strcmp((char *)token->data, head->word) == 0)
			{
				temp2 = temp->next;
//				free(temp);
				data_singleton()->heredoc_queue = temp2;
				DG("data is %s et adr %p", head->heredoc_data, temp);
			}
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
