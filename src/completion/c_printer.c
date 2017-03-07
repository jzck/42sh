/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_printer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 12:55:39 by alao              #+#    #+#             */
/*   Updated: 2017/02/16 22:11:48 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**  Print the name with or without an underline and colored upon file type
** as follow:
**    -  (4) Folder: Red "\e[1;31m" and a trailing / is added.
**    - (10) Symlink: Cyan "\e[96m" and a trailing @ is added.
** If the element is under selection, the video mode is inverted instead.
** The rest of the placeholder is filled with space to align the list.
*/

static void	c_printer_node(t_clst *lst, int c_sx)
{
	int		i;

	i = lst->len;
	lst->type == 4 ? ft_putstr_fd("\e[1;31m", 2) : (0);
	lst->type == 10 ? ft_putstr_fd("\e[1;96m", 2) : (0);
	lst->cursor ? ft_putstr_fd("\e[0;7m", 2) : (0);
	ft_putstr_fd(lst->name, 2);
	lst->type == 4 ? ft_putstr_fd("/", 2) : (0);
	lst->type == 10 ? ft_putstr_fd("@", 2) : (0);
	lst->type != 4 && lst->type != 10 ? ft_putstr_fd(" ", 2) : (0);
	while (i++ < (c_sx))
		ft_putstr(" ");
	ft_putstr_fd("\e[00m", 2);
	ft_putstr(" ");
}

/*
** Cycle through the line to print on the same line the number of time to
** fill it PER LINE and add 2 space after the print to accomodate the
** trailing / for folder and a space in between.
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
** Control the number of time it cycle for LINE
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
