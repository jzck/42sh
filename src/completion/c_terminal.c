/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_terminal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 10:44:40 by alao              #+#    #+#             */
/*   Updated: 2017/03/22 12:14:53 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "completion.h"

/*
** Clear the screen and restore cursor position.
**
** First thing is the move the cursor down (do), clear the terminal (cd), back
** up (up) and then move back in position.
*/

void				c_term_clear(t_comp *c)
{
	int				i;
	int				lcmd;
	t_data			*s;

	s = data_singleton();
	ft_putstr(tgetstr("do", NULL));
	ft_putstr(tgetstr("cd", NULL));
	ft_putstr(tgetstr("up", NULL));
	i = 0;
	lcmd = (c->rcmd) ? ft_nb_last_line(s->line.input, s->line.pos) : 0;
	while (i < lcmd)
	{
		ft_putstr(tgetstr("nd", NULL));
		i++;
	}
}

/*
** Restore cursor position.
**
** Move the cursor up as needed (up) then to the beginning of the line (cr).
** The value check if the current print is a rolling list (terminal too small to
** print the whole list at once). If so, m_size is used or c_line.
** The cursor is then moved to the right (nd) by restore the position.
*/

void				c_term_mv_back(t_comp *c)
{
	int				i;
	int				lcmd;
	int				value;
	t_data			*s;

	s = data_singleton();
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
	lcmd = (c->rcmd) ? ft_nb_last_line(s->line.input, s->line.pos) : 0;
	while (i < lcmd)
	{
		ft_putstr(tgetstr("nd", NULL));
		i++;
	}
}

/*
** Make room for the list.
**
** Move the cursor down as needed (do) and clear them (cd).
** The value check if the current print is a rolling list (terminal too small to
** print the whole list at once). If so, m_size is used or c_line.
** The cursor is then moved back up to the line just below where it was to begin
** printing the list.
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
** Retrieve new terminal size.
**
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
