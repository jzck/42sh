/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_parens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:13:31 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/20 20:55:06 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		reduce_parens(t_list **alst, char *str)
{
	t_list	*start;
	t_list	*end;
	t_token	*token;
	int		num_p;
	int		tk;

	(void)str;
	tk = TK_PAREN_OPEN;
	if ((start = ft_lst_find(*alst, &tk, token_cmp_type)))
	{
		end = start->next;
		num_p = 1;
		while (end)
		{
			token = end->content;
			if (token->type == TK_PAREN_OPEN)
				num_p++;
			else if (token->type == TK_PAREN_CLOSE)
				num_p--;
			if (num_p == 0)
				break ;
			end = end->next;
			ft_lst_delif(alst, token, ft_addrcmp, token_free);
		}
		if (!end)
			return (-1);
		token = start->content;
		token->type = TK_SUBSHELL;
		token->data = ft_strbetween(token->data + 1, ((t_token*)end->content)->data);
		ft_lst_delif(alst, end->content, ft_addrcmp, token_free);
		return (1);
	}
	return (0);
}
