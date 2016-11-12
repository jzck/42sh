/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:44:26 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/10 13:44:26 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

int		ft_key_del(t_data *data, t_dlist **input_chain, char *buf)
{
	char	*res;

	(void)data;
	(void)buf;
	if (!(*input_chain)->prev)
		return (0);
	if (*(char*)(*input_chain)->content == '\n')
		return (0);
	ft_dlstdelone(input_chain, &ft_lst_cfree);
	if ((res = tgetstr("le", NULL)) == NULL)
	{
		ft_printf("le error\n");
		return (-1);
	}
	tputs(tgoto(res, 0, 0), 0, &ft_putchar);
	if ((res = tgetstr("DC", NULL)) == NULL)
	{
		ft_printf("DC error\n");
		return (-1);
	}
	tputs(tgoto(res, 0, 0), 0, &ft_putchar);
	return (1);
}
