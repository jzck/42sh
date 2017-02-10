/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   produce_sym.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:58:34 by ariard            #+#    #+#             */
/*   Updated: 2017/02/10 01:42:12 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_prodmatch		g_prodmatch[] =
{
	{TK_N_WORD, EMPTY, CMD_NAME},
	{TK_GREAT, ALL, TK_GREAT},
	{TK_N_WORD, ALL, CMD_NAME},
	{0, 0, 0},
};

int		produce_sym(t_sym stack, t_sym *new_sym, t_list **lst)
{
	t_token		*token;
	int			i;

	token = (*lst)->content;
	i = 0;
	while (g_prodmatch[i].new_sym)
	{
		if (token->type == g_prodmatch[i].token
			&& stack & g_prodmatch[i].stack)
			*new_sym = g_prodmatch[i].new_sym;
		i++;
	}
	return (0);
}
