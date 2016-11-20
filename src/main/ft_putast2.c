/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 18:18:04 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/14 18:21:50 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_putast2(void *nodein)
{
	t_astnode	*node;

	node = nodein;
	if (node->type == TK_SEMI)
		ft_putendl(";");
	else if (node->type == TK_PIPE)
		ft_putendl("|");
	else if (node->type == TK_COMMAND)
	{
		ft_putstr("COMMAND: ");
		ft_putstr(node->u_data.sstr[0]);
		/* ft_sstrprint(node->u_data.sstr, ','); */
		/* char **sstr = node->u_data.sstr; */
		/* while (*sstr) */
			/* ft_printf("%s,", *sstr++); */
		ft_putchar('\n');
	}
	if (node->type | TK_REDIR)
	{
		ft_putnbr(node->u_data.redir.n);
		if (node->type == TK_GREAT)
			ft_putendl(">:");
		else if (node->type == TK_LESS)
			ft_putendl("<:");
		else if (node->type == TK_DGREAT)
			ft_putendl(">>:");
		else if (node->type == TK_DLESS)
			ft_putendl("<<:");
		else if (node->type == TK_GREATAND)
			ft_putendl(">&:");
		else if (node->type == TK_LESSAND)
			ft_putendl("<&:");
	}
	else
		ft_putendl("OTHER");
}
