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
		ft_putendl("SEMI");
	else if (node->type == TK_PIPE)
		ft_putendl("PIPE");
	else if (node->type == TK_COMMAND)
	{
		ft_putstr("COMMAND: ");
		ft_sstrprint(node->u_data.sstr, ',');
		ft_putchar('\n');
	}
	else if (node->type & TK_REDIR)
	{
		ft_putnbr(node->u_data.redir.n);
		if (node->type == TK_GREATAND || node->type == TK_LESSAND)
		{
			if (node->type == TK_GREATAND)
				ft_putstr(">&:");
			else
				ft_putstr("<&:");
			ft_putnbr(node->u_data.redir.u_word.fd);
			if (node->u_data.redir.close)
				ft_putstr(" (closed)");
		}
		else
		{
			if (node->type == TK_GREAT)
				ft_putendl(">:");
			else if (node->type == TK_LESS)
				ft_putstr("<:");
			else if (node->type == TK_DGREAT)
				ft_putstr(">>:");
			else if (node->type == TK_DLESS)
				ft_putstr("<<:");
			ft_putstr(node->u_data.redir.u_word.word);
		}
		ft_putchar('\n');
	}
	else
		ft_putendl("OTHER");
}
