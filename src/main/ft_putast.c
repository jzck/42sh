/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 18:18:04 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/10 14:02:06 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_putast(void *nodein)
{
	t_astnode	*node;
	struct s_tmp{
		char	str[5];
		t_type	type;
	};
	node = nodein;
	if (node->type == TK_AMP)
		return ("  &  ");
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
