/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_termios.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:14:09 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/07 14:20:59 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

int		ft_set_termios(t_data *data, int input_mode)
{
	struct termios	term;

	(void)data;
	if (tcgetattr(0, &term) == -1)
		return (-1);
	if (input_mode)
		term.c_lflag &= ~(ICANON) & ~(ISIG) & ~(ECHO);
	else
		term.c_lflag |= ICANON | ISIG | ECHO;
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	return (0);
}
