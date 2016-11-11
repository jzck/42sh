/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:37:11 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/10 17:04:10 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_tokenize(t_list **alst, char *str)
{
	static int		quoted = 0;
	t_token			*token;

	if (!*alst)
		alst = ft_lstnew(token_init(), sizeof(t_token));
	else
		token  = (*alst)->content;
	if (!*str)
		return (0);
	else if ((token->type >= TK_OP_MIN) && !quoted)
	{
		if (can_be_used_in_op)
			token_append(token, *str);
		else
			ft_tokenize(&(*alst)->next, str);
	}
	else if (can_be_first_of_op && !quoted)
	{
		(*alst)->next = ft_lstnew(token_init(), sizeof(t_token));
		(*alst) = (*alst)->next;
		token = (*alst)->content;
	}
	else if (*str == '\n' && !quoted)
		ft_tokenize(&(*alst)->next, str + 1);
	else if (*str == ' ' && !quoted)
		ft_tokenize(&(*alst)->next, str + 1);
	else if (token->type == TOKEN_WORD)
		token_append(token, *str);
	else if (*str = '#')
	{
		while (*str && *str != '\n')
			str++;
		ft_tokenize(alst, str);
	}
	(*alst)->next = ft_lstnew(token_init(), sizeof(t_token));
	token->type = TK_WORD;
	token_append(token, *str);
	ft_tokenize(&(*alst)->next, str + 1);
}
