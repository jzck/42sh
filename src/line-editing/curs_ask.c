/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curs_ask.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:03:49 by sbenning          #+#    #+#             */
/*   Updated: 2016/12/09 16:47:13 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_curs.h"

/*
 * Read the line number for cursor's coordonate
*/

int			curs_li_ask(void)
{
	char	buff;
	int		li;

	li = 0;
	buff = 0;
	while (buff != ';')
	{
		buff = 0;
		if (read(0, &buff, 1) < 0)
			return (-1);
		if (ft_isdigit(buff))
			li = li * 10 + (buff - '0');
	}
	return (li);
}

/*
 * Read the colomn number for cursor's coordonate
*/

int			curs_co_ask(void)
{
	char	buff;
	int		co;

	co = 0;
	buff = 0;
	while (buff != 'R')
	{
		buff = 0;
		if (read(0, &buff, 1) < 0)
			return (-1);
		if (ft_isdigit(buff))
			co = co * 10 + (buff - '0');
	}
	return (co);
}
