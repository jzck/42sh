/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:44:31 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/10 13:44:31 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

int		ft_line_go_down(t_dlist **input_chain)
{
	char	*res;

	(void)input_chain;
	if ((res = tgetstr("up", NULL)) == NULL)
		return (-1);
	tputs(tgoto(res, 0, 0), 0, &ft_putchar);
	return (0);
}
