/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 13:35:03 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/03 15:34:29 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		input_init(t_data *data)
{
	char	null;

	null = '\0';
	ft_strdel(&data->line.input);
	data->line.input = ft_memalloc(10);
	data->line.input_pos = 0;
	data->line.qstack = ft_lstnew(NULL, sizeof(t_qstate));
	*((t_qstate*)data->line.qstack->content) = Q_NONE;
	if (ft_set_termios(data, 1))
		return (-1);
	ft_prompt();
	return (0);
}
