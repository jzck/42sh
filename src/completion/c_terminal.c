/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_terminal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 10:44:40 by alao              #+#    #+#             */
/*   Updated: 2017/03/21 11:22:03 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "completion.h"

/*
** Clear the previous list from the screen and restore the same position.
*/

void				c_term_clear(t_comp *c)
{
	int				i;
	int				lcmd;

	ft_putstr(tgetstr("do", NULL));
	ft_putstr(tgetstr("cd", NULL));
	ft_putstr(tgetstr("up", NULL));
	i = 0;
	lcmd = 0;
	lcmd = (c->rcmd) ? ft_nb_last_line(data_singleton()->line.input,
												data_singleton()->line.pos) : 0;
	while (i < lcmd)
	{
		ft_putstr(tgetstr("nd", NULL));
		i++;
	}
}

/*
** Move the terminal up by the number of line needed and move it back up to
** the original position.
*/

void				c_term_mv_back(t_comp *c)
{
	int				i;
	int				lcmd;
	int				value;

	i = 0;
	if (c->c_line > c->win_y)
		value = c->m_size;
	else
		value = c->c_line;
	while (i != value)
	{
		ft_putstr(tgetstr("up", NULL));
		i++;
	}
	ft_putstr(tgetstr("cr", NULL));
	i = 0;
	lcmd = (c->rcmd) ? ft_nb_last_line(data_singleton()->line.input,
												data_singleton()->line.pos) : 0;
	while (i < lcmd)
	{
		ft_putstr(tgetstr("nd", NULL));
		i++;
	}
}

/*
** Move the terminal down by the number of line needed and move it back up to
** the first line under the prompt
*/

void				c_term_mv_down(t_comp *c)
{
	int				i;
	int				value;

	i = 0;
	if (c->c_line > c->win_y)
		value = c->m_size;
	else
		value = c->c_line;
	while (i < value)
	{
		ft_putstr(tgetstr("do", NULL));
		ft_putstr(tgetstr("cd", NULL));
		i++;
	}
	i = 0;
	if (c->c_line > c->win_y)
		value = c->m_size - 1;
	else
		value = c->c_line - 1;
	while (value >= 0 && i != value)
	{
		ft_putstr(tgetstr("up", NULL));
		i++;
	}
}

/*
** If the terminal has changed in size, the function will refresh these values
** and clear the previous print list.
*/

int					c_term_resize(t_comp *c)
{
	struct winsize	win;

	ioctl(0, TIOCGWINSZ, &win);
	if ((win.ws_col == c->win_x) && (win.ws_row == c->win_y))
		return (0);
	c->win_x = win.ws_col;
	c->win_y = win.ws_row;
	c_sizing(c);
	c_term_clear(c);
	return (0);
}
