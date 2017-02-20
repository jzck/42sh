/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:37:04 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/20 18:37:46 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shell_exit(void)
{
//	DG("shell_exit()");
	data_exit();
	if (SH_HAS_JOBC(data_singleton()->opts))
		job_kill_all();
	tcsetattr(STDIN, TCSANOW, &data_singleton()->jobc.shell_tmodes);
}
