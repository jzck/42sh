/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_lexer_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 14:24:38 by wescande          #+#    #+#             */
/*   Updated: 2017/03/20 15:19:05 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		do_lexer_routine(t_list **token, char *stream)
{
	t_list		*ltoken;
	t_data		*data;

	data = data_singleton();
	if (data->lexer.state == HEREDOC || data->parser.state == UNDEFINED)
	{
		ft_strappend(&data->lexer.str, (char[]){'\n', 0});
		data->lexer.pos++;
	}
	ft_strappend(&data->lexer.str, stream);
	if (get_lexer_stack(data->lexer) == BACKSLASH)
		pop(&data->lexer.stack);
	ltoken = ft_lstlast(*token);
	if (lexer_lex(*token ? &ltoken : token, &data->lexer) < 0)
		exit(1);
	if (get_lexer_stack(data->lexer) > 2)
		return (1);
	data->lexer.state = DEFAULT;
	return (0);
}
