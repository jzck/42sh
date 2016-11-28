/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 18:18:04 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/28 14:47:40 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_putast(void *nodein)
{
	t_astnode	*node;

	node = nodein;
	if (node->type == TK_SEMI)
		return ("  ;  ");
	else if (node->type == TK_PIPE)
		return ("  |  ");
	else if (node->type == TK_COMMAND)
	{
		/*char **sstr = node->u_data.sstr; */
		/* while (*sstr) */
		/* 	ft_printf("%s,", *sstr++); */
		/* return (ft_itoa_base(node->type, "0123456789abcdef", "")); */
		return (" COM ");
	}
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
