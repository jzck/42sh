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
	else if (token->type == TOKEN_OPERATOR && !quoted)
	{
		if (can_be_used_in_op)
			token_append(token, *str);
		else
			ft_tokenize(&(*alst)->next, str);
	}
	else if (can_be_first_of_op && !quoted)
	{
		
	}
	ft_tokenize(&(*alst)->next, str + 1);
	ft_tokenize(alst, str + 1);
}
