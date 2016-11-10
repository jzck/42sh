/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:43:10 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/10 13:43:25 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

int		ft_cursor_left(t_data *data, t_dlist **input_chain, char *buf)
{
	char	*res;

	res = NULL;
	(void)buf;
	(void)data;
	if (*(char*)(*input_chain)->content == '\n')
		return (0);
	if (*(char*)(*input_chain)->content == '\0')
		return (0);
	*input_chain = (*input_chain)->prev;
	if ((res = tgetstr("le", NULL)) == NULL)
		return (-1);
	tputs(tgoto(res, 0, 0), 0, &ft_putchar);
	return (1);
}
