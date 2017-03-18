/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 16:21:05 by ariard            #+#    #+#             */
/*   Updated: 2017/03/18 19:00:17 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*join_heredoc_data(char *old_data, char *token_data)
{
	char	*del;
	char	*new;

	del = old_data;
	new = ft_str3join(old_data, token_data, "\n");
	ft_strdel(&del);
	return (new);
}

int				pop_heredoc(t_list **lst)
{
	t_token	*token;
	t_list	**head;
	t_redir	*redir;

	token = (*lst)->content;
	if (token->type == HEREDOCDATA
		&& data_singleton()->parser.heredoc_queue != NULL)
	{
		if (!(head = &data_singleton()->parser.heredoc_queue))
			return (0);
		redir = *(t_redir**)(*head)->content;
		if (ft_strcmp((char *)token->data, redir->word) == 0)
			ft_lst_delif(head, (t_redir**)(*head)->content,
				ft_addrcmp, ft_lst_cfree);
		else
			redir->heredoc_data = join_heredoc_data(redir->heredoc_data,
				(char*)token->data);
		ft_lstdel(lst, &token_free);
		return (1);
	}
	return (0);
}
