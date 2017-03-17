/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 14:19:48 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/17 14:56:35 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		readline(int has_prompt, char **input)
{
	int ret;

	if (!SH_IS_INTERACTIVE(data_singleton()->opts))
		return ((ret = get_next_line(STDIN, input)) >= 0 ? !ret : ret);
	readline_init(has_prompt);
	ret = ft_read_stdin(input);
	DG("ret = %s", input);
	if (ret < 0)
		return (ret);
	if (data_singleton()->line.input)
		ft_current_str(data_singleton()->line.input,
													data_singleton()->line.pos);
	ft_putchar('\n');
	if (has_prompt)
		ret = ft_history_parsing(has_prompt, input);
	if (tcsetattr(0, TCSANOW, ft_save_termios(0)) == -1)
		return (-1);
	return (ret);
}
