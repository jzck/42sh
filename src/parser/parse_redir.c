/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 18:58:27 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/02 19:04:32 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		parse_redir(t_btree **ast, t_list **start, t_list **lst)
{
	t_token		*tok;

	tok = (*lst)->content;
	if (tok->type == TK_LESS)
		return (parse_less(ast, start, lst));
	else if (tok->type == TK_GREAT)
		return (parse_great(ast, start, lst));
	else if (tok->type == TK_DLESS)
		return (parse_dless(ast, start, lst));
	else if (tok->type == TK_DGREAT)
		return (parse_dgreat(ast, start, lst));
	else if (tok->type == TK_LESSAND)
		return (parse_lessand(ast, start, lst));
	else if (tok->type == TK_GREATAND)
		return (parse_greatand(ast, start, lst));
	else
		return (-42);
}
