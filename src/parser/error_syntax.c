/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 20:15:35 by ariard            #+#    #+#             */
/*   Updated: 2017/02/13 22:09:03 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			error_syntax(t_list **lst)
{	
	t_token		*token;

	token = (*lst)->content;
	if (token->type == TK_SEMI)
		ft_putstr_fd("syntax error near unexepected token ';'", 2);
	else if (token->type == TK_WORD)
		ft_putstr_fd("syntax error near unexepected token 'word'", 2);
	else if (token->type == TK_GREAT)
		ft_putstr_fd("syntax error near unexepected token '>'", 2);
	else if (token->type == TK_NEWLINE)
		ft_putstr_fd("syntax error near unexepected token 'newline'", 2);
	else if (token->type == TK_LESS)
		ft_putstr_fd("syntax error near unexepected token '<'", 2);
	else
		ft_putstr_fd("grammar error, notify ariard", 2);
	return (1);
}
