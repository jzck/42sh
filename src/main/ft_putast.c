/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 18:18:04 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/01 15:56:54 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_putast(void *nodein)
{
	t_astnode	*node;
	node = nodein;
	
	if (node->type == REDIR)
		return ("REDIR");
	if (node->type == CLOSE_LIST)
		return ("CLOSE_LIST");
	if (node->type == FNAME)
		return ("FNAME");
	if (node->type == TK_LBRACE)
		return ("TK_LBRACE");
	if (node->type == TK_ASSIGNEMENT_WORD)
		return ("ASSIGNEMENT_WORD");
	if (node->type == SUBSHELL)
		return ("SUBSHELL");
	if (node->type == TK_NAME)
		return ("TK_NAME");
	if (node->type == TK_FOR)
		return ("TK_FOR");
	if (node->type == TK_CASE)
		return ("TK_CASE");
	else if (node->type == TK_PAREN_OPEN)
		return ("TK_OPE");
	else if (node->type == TK_PAREN_CLOSE)
		return ("TK_CLO");
	else if (node->type == TK_IN)
		return ("TK_IN");
	else if (node->type ==TK_ESAC)
		return ("TK_ESAC");
	else if (node->type == TK_THEN)
		return ("THEN");
	else if (node->type == TK_FI)
		return ("FI");
	else if (node->type == TK_DO)
		return ("TK_DO");
	else if (node->type == TK_AMP)
		return ("  &  ");
	else if (node->type == TK_WORD)
		return (" TK_WORD");
	else if (node->type == TK_SEMI)
		return ("  ;  ");
	else if (node->type == TK_AND_IF)
		return (" &&  ");
	else if (node->type == TK_OR_IF)
		return (" ||  ");
	else if (node->type == TK_PIPE)
		return ("  |  ");
	else if (node->type == TK_COMMAND)
		return (" COM ");
	else if (node->type == TK_WHILE)
		return (" WHILE ");
	else if (node->type == TK_IF)
		return ("IF");
	else if (node->type == TK_ELIF)
		return ("ELIF");
	else if (node->type == TK_ELSE)
		return ("ELSE");
	else if (node->type == TK_UNTIL)
		return ("UNTIL");
	else if (node->type == TK_NEWLINE)
		return ("NEW");
	else if (node->type == TK_GREAT)
		return ("  >  ");
	else if (node->type == TK_LESS)
		return ("  <  ");
	else if (node->type == TK_DGREAT)
		return (" >>  ");
	else if (node->type == TK_DLESS)
		return (" <<  ");
	else if (node->type == TK_GREATAND)
		return (" >&  ");
	else if (node->type == TK_LESSAND)
		return (" <&  ");
	else
		return ("OTHER");
}
