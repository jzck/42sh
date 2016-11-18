/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_tc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:27:57 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/10 14:39:28 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

int		ft_set_termios(t_data *data, int input_mode)
{
	struct termios	term;
	char			*term_name;

	if ((term_name = ft_getenv(data->env, "TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, term_name) != 1)
		return (-1);
	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag &= ~(ICANON); // Met le terminal en mode canonique.
	if (input_mode)
		term.c_lflag &= ~(ISIG) & ~(ECHO);
	else
		term.c_lflag |= ISIG | ECHO;
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	return (0);
}
