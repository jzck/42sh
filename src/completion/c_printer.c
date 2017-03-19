/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_printer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 12:55:39 by alao              #+#    #+#             */
/*   Updated: 2017/03/19 12:14:02 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "completion.h"

/*
**  Print the name with or without an underline and colored upon file type
** as follow:
**    -  (4) Folder: Red "\e[1;31m" and a trailing / is added.
**    - (10) Symlink: Cyan "\e[96m" and a trailing @ is added.
** If the element is under selection, the video mode is inverted instead.
** The rest of the placeholder is filled with space to align the list.
*/

static void		c_printer_node(t_clst *lst, int c_sx)
{
	int			i;

	i = lst->len;
	lst->type == 4 ? ft_putstr_fd("\e[1;31m", 1) : (0);
	lst->type == 10 ? ft_putstr_fd("\e[1;96m", 1) : (0);
	lst->cursor ? ft_putstr_fd("\e[0;7m", 1) : (0);
	ft_putstr_fd(lst->name, 1);
	lst->type == 4 ? ft_putstr_fd("/", 1) : (0);
	lst->type == 10 ? ft_putstr_fd("@", 1) : (0);
	lst->type != 4 && lst->type != 10 ? ft_putstr_fd(" ", 1) : (0);
	while (i++ < (c_sx))
		ft_putstr(" ");
	ft_putstr_fd("\e[00m", 1);
	ft_putstr(" ");
}

/*
** Cycle through the line to print on the same line the number of time to
** fill it PER LINE and add 2 space after the print to accomodate the
** trailing / for folder and a space in between.
*/

static int		c_printer_line(t_comp *c, t_clst *lst, int loop, int i)
{
	t_clst		*ptr;

	ptr = lst->next;
	c_printer_node(lst, c->c_sx);
	while (loop)
	{
		i = 1;
		while (i++ < (c->c_line))
		{
			if (ptr == c->lst)
				return (0);
			ptr = ptr->next;
		}
		if (ptr != c->lst)
		{
			i = lst->len;
			c_printer_node(ptr, c->c_sx);
			lst = ptr;
			ptr = ptr->next;
		}
		loop--;
	}
	return (0);
}

/*
** Return the right pointer in the list from the offset value calculated below.
*/

static t_clst	*c_rolling_ptr(t_comp *c, int id)
{
	t_clst		*ptr;
	int			i;

	i = (id - 1) * (c->m_size - 1);
	ptr = c->lst;
	while (i)
	{
		ptr = ptr->next;
		i--;
	}
	return (ptr);
}

/*
** Controlling the offset value for the rolling list if the space in the
** terminal is too small to display the whole list.
**
** Controlled value are:
** - x : the column of the element currently selected.
*/

static t_clst	*c_rolling(t_comp *c)
{
	t_clst		*ptr;
	int			x;
	int			y;
	int			id;

	ptr = c->lst;
	while (!ptr->cursor)
		ptr = ptr->next;
	x = 1;
	while ((x * c->c_line) < ptr->id)
		x++;
	id = ((x == 1) ? ptr->id : (ptr->id - ((x - 1) * c->c_line)));
	y = 1;
	while ((y * (c->m_size - 1)) < id)
		y++;
	c->pos_x = id;
	c->pos_y = y;
	if (y > 1)
		return (c_rolling_ptr(c, y));
	return (c->lst);
}

/*
** Control the number of time it cycle for LINE
*/

void			c_printer(t_comp *c)
{
	t_clst		*ptr;
	int			loop;
	int			max_line;

	loop = c->c_line;
	if (!c->c_line)
		return ;
	max_line = c->c_line - (c->m_size - 1);
	ptr = c_rolling(c);
	if ((c->pos_y * (c->m_size - 1)) > c->c_line)
		max_line = (c->c_line % (c->m_size - 1));
	else
		max_line = c->m_size - 1;
	while (loop && max_line)
	{
		c_printer_line(c, ptr, c->c_pline, 1);
		loop > 1 ? ft_putstr(tgetstr("do", NULL)) : (0);
		ptr = ptr->next;
		loop--;
		max_line--;
	}
}
