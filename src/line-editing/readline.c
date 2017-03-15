/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 14:19:48 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/15 03:52:15 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		readline(int fd, int prompt, char **input)
{
	int ret;

	if (!SH_IS_INTERACTIVE(data_singleton()->opts))
		return ((ret = get_next_line(fd, input)) >= 0 ? !ret : ret);
	readline_init(prompt);
	*input = ft_read_stdin();
	if (STR)
		ft_current_str(STR, POS);
	ft_putchar('\n');
	if (!prompt)
		*input = ft_history_parsing();
	if (tcsetattr(0, TCSANOW, ft_save_termios(0)) == -1)
		return (-1);
	return (0);
}
