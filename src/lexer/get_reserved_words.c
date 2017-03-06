/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_reserved_words.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 00:07:05 by ariard            #+#    #+#             */
/*   Updated: 2017/03/06 17:56:14 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"


t_rvwords		g_rvwords[] =
{
	{"while", TK_WHILE},
	{"done", TK_DONE},
	{"do", TK_DO},
	{"if", TK_IF},
	{"then", TK_THEN},
	{"fi", TK_FI},
	{"elif", TK_ELIF},
	{"else", TK_ELSE},
	{"until", TK_UNTIL},
	{"case", TK_CASE},
	{"esac", TK_ESAC},
	{"for", TK_FOR},
	{"null", 0},
};


static int		recognization_rvwords(t_token *pv_tk)
{
	if (!pv_tk || (pv_tk->type == TK_NEWLINE || pv_tk->type == TK_AMP 
		|| pv_tk->type == TK_SEMI || pv_tk->type == TK_WHILE
		|| pv_tk->type == TK_DONE || pv_tk->type == TK_DO
		|| pv_tk->type == TK_IF || pv_tk->type == TK_FI || pv_tk->type == TK_THEN
		|| pv_tk->type == TK_ELIF || pv_tk->type == TK_ELSE))
		return (1);
	return (0);
}

int				get_reserved_words(t_list **alst)
{
	t_token		*token;
	t_token		*pv_tk;
	t_token		*ante_token;
	t_list		*temp;
	int			i;

	temp = *alst;
	pv_tk = NULL;
	ante_token = NULL;
	while (temp)
	{
		token = temp->content;
		//no more comp &
		if (recognization_rvwords(pv_tk))
		{
			if (token->type == TK_WORD)
			{
				i = 0;
				while (g_rvwords[i].type)
				{
					if (ft_strcmp(token->data, g_rvwords[i].word) == 0)
						token->type = g_rvwords[i].type;
					i++;
				}
			}
		}
		if (ante_token && (ante_token->type == TK_CASE || ante_token->type == TK_FOR)
			&& ft_strncmp(token->data, "in", 2) == 0)
			token->type = TK_IN;
		if (pv_tk && pv_tk->type == TK_FOR && token->type == TK_WORD)
			token->type = TK_NAME;
		ante_token = pv_tk;	
		pv_tk = token;
		temp = temp->next;
	}
	return (0);
}
