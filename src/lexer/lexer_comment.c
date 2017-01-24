/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_comment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 18:22:35 by ariard            #+#    #+#             */
/*   Updated: 2017/01/24 20:07:14 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_comment(t_list **alst, char *str)
{
	t_token		*token;

	(void)str;
	token = (*alst)->content;
	if (!token->type)
		ft_lstdel(alst, &token_free);
	return (0);
}
