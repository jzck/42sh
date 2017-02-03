/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_reserved_words.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 00:07:05 by ariard            #+#    #+#             */
/*   Updated: 2017/02/03 19:39:01 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		get_reserved_words(t_list **alst)
{
	t_token		*token;
	t_list		*temp;
	int			i;

	temp = *alst;
	i = 0;
	while (temp)
	{
		token = temp->content;
		if (i == 0)
			if (token->type == TK_N_WORD)
				if (ft_strncmp(token->data, "while", 5) == 0)
					token->type = TK_WHILE;
		if ((token->type & (TK_NEWLINE | TK_AMP | TK_SEMI)))
		{
			if ((temp = temp->next))
				token = temp->content;
			else
				break;
			if (token->type == TK_N_WORD)
			{	
				if (ft_strncmp(token->data, "while", 5) == 0)
					token->type = TK_WHILE;
				else if (ft_strncmp(token->data, "done", 4) == 0)
					token->type = TK_DONE;
				else if	(ft_strncmp(token->data, "do" , 2) == 0)
					token->type = TK_DO;
			}
		}
		temp = temp->next;
		i++;
	}
	return (0);
}
