/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_printer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 12:55:39 by alao              #+#    #+#             */
/*   Updated: 2017/02/15 19:28:43 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "completion.h"

/*
** AUTOCOMPLETION: Print the name with or without an underline and colored upon
**                 file type as follow:
**                 - (4) Folder: Red "\e[1;31m"
**                 - (10) Symlink: Cyan "\e[96m"
*/

static void	c_printer_node(t_clst *lst, int c_sx)
{
	int		i;

	i = lst->len;
	if (lst->cursor)
		ft_putstr_fd("\e[7m", 2);
	else
	{
		lst->type == 4 ? ft_putstr_fd("\e[1;31m", 2) : (0);
		lst->type == 10 ? ft_putstr_fd("\e[1;96m", 2) : (0);
	}
	ft_putstr_fd(lst->name, 2);
	if (lst->type == 4)
		ft_putstr_fd("/", 2);
	else if (lst->type == 10)
		ft_putstr_fd("@", 2);
	else
		ft_putstr_fd(" ", 2);
	while (i++ < (c_sx))
		ft_putstr(" ");
	ft_putstr_fd("\e[00m", 2);
	ft_putstr(" ");
}

/*
** AUTOCOMPLETION: Cycle through the line to print on the same line the
** number of time to fill it PER LINE and add 2 space after the print to
** accomodate the trailing / for folder and a space in between.
*/

static int	c_printer_line(t_comp *c, t_clst *lst, int loop, int i)
{
	t_clst	*ptr;

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
** AUTOCOMPLETION: Control the number of time it cycle for LINE
*/

void		c_printer(t_comp *c)
{
	t_clst	*ptr;
	int		loop;

	ptr = c->lst;
	loop = c->c_line;
	while (loop)
	{
		c_printer_line(c, ptr, c->c_pline, 1);
		loop > 1 ? ft_putstr(tgetstr("do", NULL)) : (0);
		ptr = ptr->next;
		loop--;
	}
}
