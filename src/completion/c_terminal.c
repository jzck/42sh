/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_terminal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 10:44:40 by alao              #+#    #+#             */
/*   Updated: 2017/02/03 17:33:08 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "completion.h"

/*
** AUTOCOMPLETION: Move the terminal up by the number of line needed and
** move it back up to the original position
*/

void			c_term_mv_back(t_comp *c)
{
	int		i;
	int		lcmd;

	i = 0;
	while (i != (c->c_line))
	{
		ft_putstr(tgetstr("up", NULL));
		i++;
	}
	ft_putstr(tgetstr("cr", NULL));
	i = 0;
	lcmd = 0;
	c->rcmd ? lcmd += (int)ft_strlen(c->rcmd) + c->prompt + 1 : 0;
	while (i < lcmd)
	{
		ft_putstr(tgetstr("nd", NULL));
		i++;
	}
}

/*
** AUTOCOMPLETION: Move the terminal down by the number of line needed and
** move it back up to the first line under the prompt
*/

void			c_term_mv_down(t_comp *c)
{
	int		i;

	i = 0;
	while (i < c->c_line)
	{
		ft_putstr(tgetstr("do", NULL));
		i++;
	}
	i = 0;
	while (i != (c->c_line - 1))
	{
		ft_putstr(tgetstr("up", NULL));
		i++;
	}
}