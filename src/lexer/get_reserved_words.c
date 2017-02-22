/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_reserved_words.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 00:07:05 by ariard            #+#    #+#             */
/*   Updated: 2017/02/21 21:06:16 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		get_reserved_words(t_list **alst)
{
	t_token		*token;
	t_token		*previous_token;
	t_token		*ante_token;
	t_list		*temp;

	temp = *alst;
	previous_token = NULL;
	ante_token = NULL;
	while (temp)
	{
		token = temp->content;
		if (!previous_token || (previous_token->type & RW_SEP))
		{
			if (token->type == TK_WORD)
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
				else if (ft_strncmp(token->data, "case", 4) == 0)
					token->type = TK_CASE;
				else if (ft_strncmp(token->data, "for", 3) == 0)
					token->type = TK_FOR;
			}
		}
		if (ante_token && (ante_token->type == TK_CASE || ante_token->type == TK_FOR)
			&& ft_strncmp(token->data, "in", 2) == 0)
			token->type = TK_IN;
		if (previous_token && previous_token->type == TK_FOR && token->type == TK_WORD)
			token->type = TK_NAME;
		ante_token = previous_token;	
		previous_token = token;
		temp = temp->next;
	}
	return (0);
}
