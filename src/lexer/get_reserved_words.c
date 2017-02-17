/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_reserved_words.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 00:07:05 by ariard            #+#    #+#             */
/*   Updated: 2017/02/17 17:30:54 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		get_reserved_words(t_list **alst)
{
	t_token		*token;
	t_token		*previous_token;
	t_list		*temp;

	temp = *alst;
	previous_token = NULL;
	while (temp)
	{	
		token = temp->content;
		if (!previous_token || (previous_token->type & RW_SEP))
		{
			if (token->type == TK_N_WORD)
			{		
				if (ft_strncmp(token->data, "while", 5) == 0)
					token->type = TK_WHILE;
				else if (ft_strncmp(token->data, "done", 4) == 0)
					token->type = TK_DONE;
				else if	(ft_strncmp(token->data, "do" , 2) == 0)
					token->type = TK_DO;
				else if (ft_strncmp(token->data, "if", 2) == 0)
					token->type = TK_IF;
				else if (ft_strncmp(token->data, "then", 4) == 0)
					token->type = TK_THEN;
				else if(ft_strncmp(token->data, "fi", 4) == 0)
					token->type = TK_FI;
				else if (ft_strncmp(token->data, "elif", 4) == 0)
					token->type = TK_ELIF;
				else if (ft_strncmp(token->data, "else", 4) == 0)
					token->type = TK_ELSE;
				else if (ft_strncmp(token->data, "until", 5) == 0)
					token->type = TK_UNTIL;
			}
		}
		previous_token = token;
		temp = temp->next;
	}
	return (0);
}
