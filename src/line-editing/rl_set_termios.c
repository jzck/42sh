/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_set_termios.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 17:00:16 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/10 17:02:50 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		rl_set_termios(int input_mode)
{
	struct termios	term;

	if (tcgetattr(0, &term) == -1)
	{
			DG("tcgetattr failed, errno=%i", errno);
			return (-1);
		}
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
