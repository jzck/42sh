/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:37:04 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/21 20:14:43 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shell_exit(void)
{
	t_data	*data;

	/* DG("shell_exit()"); */
	data = data_singleton();
	data_exit();
	if (SH_HAS_JOBC(data->opts))
		job_kill_all();
	if (SH_IS_INTERACTIVE(data->opts))
		tcsetattr(STDIN, TCSANOW, &data_singleton()->jobc.shell_tmodes);
}
