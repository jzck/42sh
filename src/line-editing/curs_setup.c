/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curs_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:36:43 by sbenning          #+#    #+#             */
/*   Updated: 2017/01/11 13:55:42 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_curs.h"

/*
 * Set coordonate cursor data
 * "\033[6n" ask for terminal to write on standard entry the cursor's coordonate
*/

int				curs_coo_setup(t_curs *curs)
{
	ft_putstr("\033[6n");
	curs->li = curs_li_ask() - 1;
	curs->co = curs_co_ask() - 1;
	return ((curs->li < 0 || curs->co < 0 ? -1 : 0));
}

/*
 * Set windows cursor data
*/

void		curs_win_setup(t_curs *curs)
{
	struct winsize	ws;

	ioctl(0, TIOCGWINSZ, &ws);
	curs->win_li = ws.ws_row;
	curs->win_co = ws.ws_col;
}

/*
 * Reset saved cursor data
*/

void		curs_reset(int sig)
{
	t_curs	*curs;

	curs = curs_single(NULL, 0);
	curs_win_setup(curs);
	curs_coo_setup(curs);
	return ;
	(void)sig;
}

/*
 * Save the cursor reference, init termcap and set cursor data
*/

int		curs_setup(t_curs *curs)
{
	curs_single(curs, 1);
	signal(SIGWINCH, curs_reset);
	if (tgetent(NULL, "xterm") != 1)
		return (-1);
	if (curs_term_setup() < 0)
		return (-1);
	curs_win_setup(curs);
	if (curs_coo_setup(curs) < 0)
		return (-1);
	return (0);
}

/*
 * Erase cursor data and reset terminal
*/

int		curs_cleanup(t_curs *curs)
{
	ft_bzero(curs, sizeof(t_curs));
	return (curs_term_cleanup());
}
