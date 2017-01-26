/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_read_term.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:02:05 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/26 20:27:00 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

struct termios	bt_read_term(int init)
{
	static struct termios	term;

	if (init)
		tcgetattr(0, &term);
	return (term);
}

int		bt_read_terminit(t_read *data)
{
	struct termios	term;

	(void)data;
	term = bt_read_term(1);
	term.c_lflag &= ~(ECHO | ICANON);
	if (data->opts & READ_OPT_LT)
	{
		term.c_cc[VTIME] = data->timeout * 10;
		term.c_cc[VMIN] = 0;
	}
	else
	{
		term.c_cc[VTIME] = 0;
		term.c_cc[VMIN] = 1;
	}
	if (tcsetattr(0, TCSANOW, &term) < 0)
		return (-1);
	DG("c_cc[VTIME]=%i", term.c_cc[VTIME]);
	return (0);
}

int		bt_read_termexit(void)
{
	struct termios	term;

	term = bt_read_term(0);
	if (tcsetattr(0, TCSANOW, &term) < 0)
		return (-1);
	return (0);
}
