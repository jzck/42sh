/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_bquotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:46:27 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/09 20:45:08 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		reduce_bquotes(t_list **alst, char **str)
{
	t_list	*start;
	t_list	**end;
	t_token	*token;
	int		tk;
	char	*new;
	char	*fit;
	char	*bq_start;
	char	*bq_end;
	t_lexer	lexer;

	tk = TK_BQUOTE;
	if ((start = ft_lst_find(*alst, &tk, token_cmp_type)))
	{
		end = &start->next;
		while (end && *end)
		{
			token = (*end)->content;
			if (token->type == TK_BQUOTE)
				break ;
			end = &(*end)->next;
		}
		if (!*end)
			return (-1);
		bq_start = ((t_token*)start->content)->data;
		bq_end = ((t_token*)(*end)->content)->data;
		ft_lstdel(end, token_free);
		fit = command_getoutput(ft_strbetween(bq_start + 1, bq_end));
		new = ft_strreplace(str, bq_start, bq_end, fit);
		ft_strdel(str);
		*str = new;
		ft_lstdel(alst, token_free);

		lexer.pos = 0;
		lexer.str = *str;
		lexer.state = DEFAULT;
		lexer_lex(alst, &lexer);
		return (1);
	}
	return (0);
}

