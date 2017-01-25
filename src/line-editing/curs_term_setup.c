/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curs_term_setup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:50:26 by sbenning          #+#    #+#             */
/*   Updated: 2017/01/25 15:04:17 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_curs.h"

/*
 * Return a static termios structure reference
*/

static struct termios		*curs_term(void)
{
	static struct termios	term;

	return (&term);
}

/*
 * Save the current termios state and set termios to RAW
*/

int							curs_term_setup(void)
{
	struct termios			*single;
	struct termios			term;

	single = curs_term();
	if (tcgetattr(0, single) < 0)
		return (-1);
	term = *single;
	term.c_lflag &= ~(ECHO | ICANON | ISIG);
	term.c_cc[VTIME] = 0;
	term.c_cc[VMIN] = 1;
	if (tcsetattr(0, TCSADRAIN, &term) < 0)
		return (-1);
	return (0);
}

/*
 * Set termios to the saved state
*/

int							curs_term_cleanup(void)
{
	struct termios			*single;
	struct termios			term;

	single = curs_term();
	term = *single;
	term.c_lflag |= ECHO | ICANON | ISIG;
	if (tcsetattr(0, TCSADRAIN, single) < 0)
		return (-1);
	return (0);
}
