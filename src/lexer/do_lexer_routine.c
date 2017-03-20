/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_lexer_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 14:24:38 by wescande          #+#    #+#             */
/*   Updated: 2017/03/20 16:42:26 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		do_lexer_routine(t_list **token, char *stream)
{
	t_list				*ltoken;
	t_data				*data;
	static t_type		last;

	data = data_singleton();
	if (data->lexer.state == HEREDOC)
		ft_strappend(&data->lexer.str, (char[]){'\n', 0});
	if (data->parser.state == UNDEFINED && !isrw_delim(last)) 
		ft_strappend(&data->lexer.str, (char[]){';', 0});
	else if (data->parser.state == UNDEFINED && last != 0)
		ft_strappend(&data->lexer.str, (char[]){' ', 0});
	if (data->lexer.state == HEREDOC || (data->parser.state == UNDEFINED 
		&& last != 0))
		data->lexer.pos++;
	ft_strappend(&data->lexer.str, stream);
	if (get_lexer_stack(data->lexer) == BACKSLASH)
		pop(&data->lexer.stack);
	ltoken = ft_lstlast(*token);
	if (lexer_lex(*token ? &ltoken : token, &data->lexer) < 0)
		exit(1);
	if (get_lexer_stack(data->lexer) > 2)
		return (1);
	if (get_reserved_words(*token))
		return (1);
	keep_last_type(&last, *token);
	data->lexer.state = DEFAULT;
	return (0);
}
