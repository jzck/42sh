/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_parser_routine.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 14:24:14 by wescande          #+#    #+#             */
/*   Updated: 2017/03/21 16:09:48 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		do_parser_routine(t_list **token, t_btree **ast)
{
	t_data		*data;

	data = data_singleton();
	if (insert_newline(token))
		return (1);
	if (data->parser.state == SUCCESS && stack_init(&data->parser))
		exit(1);
	if (ft_parse(ast, token, &data->parser))
		exit(1);
	if ((data->lexer.state = data->parser.heredoc_queue ? HEREDOC : DEFAULT))
		return (0);
	if (data->parser.state == ERROR)
	{
		error_syntax(token);
		return (1);
	}
	else if (data->parser.state == SUCCESS)
		return (2);
	return (0);
}
