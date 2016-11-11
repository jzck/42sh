/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:37:11 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/11 20:37:49 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_operator	g_ops[] =
{
	{TK_LESS, "<", NUM_BEFORE | WORD_AFTER},
	{TK_GREAT, ">", NUM_BEFORE | WORD_AFTER},
	{TK_DGREAT, ">>", NUM_BEFORE | WORD_AFTER},

	{TK_LESSAND, "<&", NUM_BEFORE | WORD_AFTER | MIN_END},
	{TK_GREATAND, ">&", NUM_BEFORE | WORD_AFTER | MIN_END},

	{TK_DLESS, "<<", NUM_BEFORE | WORD_AFTER},

	{TK_SCOLON, ";", 0},
	{TK_PIPE, "|", 0},
}

int		ft_tokenize(t_list **alst, char *str)
{
	static int		quoted = 0;
	t_token			*token;

	if (!*alst)
		alst = ft_lstnew(token_init(), sizeof(t_token));
	else
		token  = (*alst)->content;
	if (!*str)
	{
		token_delimit(token);
		return (0);
	}
	else if ((token->type | TK_OPERATOR) && !quoted)
	{
		if (token_operator_match(token, *str))
			token_append(token, *str);
		else
		{
			token_delimit(token);
			ft_tokenize(&(*alst)->next, str);
		}
	}
	else if (ft_strchr(OPERATOR_START, *str) && !quoted)
	{
		token_delimit(token);
		(*alst)->next = ft_lstnew(token_init(), sizeof(t_token));
		(*alst) = (*alst)->next;
		token = (*alst)->content;
		token->type = TK_UNKNOWN;
		token_append(token, *str);
		ft_tokenize(alst, str + 1);
	}
	else if (*str == ' ' && !quoted)
	{
		token_delimit(token);
		ft_tokenize(&(*alst)->next, str + 1);
	}
	else if (token->type == TOKEN_WORD)
		token_append(token, *str);
	else if (*str = '#')
	{
		while (*str && *str != '\n')
			str++;
		ft_tokenize(alst, str);
	}
	else
	{
		(*alst)->next = ft_lstnew(token_init(), sizeof(t_token));
		token->type = TK_WORD;
		token_append(token, *str);
	}
	ft_tokenize(&(*alst)->next, str + 1);
}
