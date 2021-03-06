/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_read_term.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:02:05 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/29 15:02:36 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

struct termios	bt_read_term(int init)
{
	static struct termios	term;

	if (init)
		tcgetattr(0, &term);
	return (term);
}

int				bt_read_terminit(t_read *data)
{
	struct termios	term;

	term = bt_read_term(1);
	if (!(data->flag & BT_READ_INTER))
		return (0);
	term.c_lflag &= ~(ICANON | ECHO);
	term.c_cc[VTIME] = data->timeout * 10;
	term.c_cc[VMIN] = data->timeout ? 0 : 1;
	term.c_cc[VEOL] = data->delim;
	if (tcsetattr(0, TCSANOW, &term) < 0)
	{
		SH_ERR("tcsetattr(): %s", strerror(errno));
		return (-1);
	}
	return (0);
}

int				bt_read_exit(t_read *data)
{
	struct termios	term;

	ft_strdel(&data->input);
	term = bt_read_term(0);
	if (tcsetattr(0, TCSANOW, &term) < 0)
		return (-1);
	return (0);
}
