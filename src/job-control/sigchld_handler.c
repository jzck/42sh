/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigchld_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 17:37:56 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/12 16:49:07 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigchld_handler(int signo)
{
	t_data	*data;

	(void)signo;
	data = data_singleton();
	if (data->mode == MODE_INPUT)
	{
		DG("got SIGCHLD in MODE_INPUT (asynchronos notification)");
		check_chlds();
		ft_putstr(SHELL_PROMPT);
		ft_putstr(data->line.input);
	}
	else
		DG("got SIGCHLD in MODE_EXEC, will check before next prompt");
}
