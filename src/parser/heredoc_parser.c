/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 16:21:05 by ariard            #+#    #+#             */
/*   Updated: 2017/03/16 17:51:54 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			pop_heredoc(t_list **lst)
{
	t_token	*token;
	t_list	**head;
	t_redir	*redir;
	char	*tmp;

	token = (*lst)->content;
	if (token->type == HEREDOCDATA && data_singleton()->parser.heredoc_queue != NULL)
	{
		head = &data_singleton()->parser.heredoc_queue;
		redir = *(t_redir**)(*head)->content;
		if (head && token)
		{
			/* DG("comparing w/ input [%s], head @ %p", token->data, *head); */
			/* DG("redir1 @ %p word=[%s]", redir, redir->word); */
			if (ft_strcmp((char *)token->data, redir->word) == 0)
			{
				ft_lst_delif(head, (t_redir**)(*head)->content, ft_addrcmp, ft_lst_cfree);
				/* DG("matched heredoc EOF, new head @ %p", *head); */
			}
			else
			{
				tmp = redir->heredoc_data;
				redir->heredoc_data = ft_str3join(redir->heredoc_data,
						(char*)token->data, "\n");
				ft_strdel(&tmp);
			}
		}
		ft_lstdel(lst, &token_free);
		return (1);
	}
	return (0);
}
