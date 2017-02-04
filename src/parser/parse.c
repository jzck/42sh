/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 16:52:51 by ariard            #+#    #+#             */
/*   Updated: 2017/02/04 20:43:45 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		parse(t_btree **ast, t_list **token)
{
	t_list	*start;

	start = *token;
	if (get_instruction(token))
		return (1);
	if (ft_parse(ast, &start))
		return (1);
	return (0);
}
