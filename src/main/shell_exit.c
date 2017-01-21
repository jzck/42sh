/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:37:04 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/19 21:50:05 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shell_exit(void)
{
	DG("shell_exit()");
	data_exit();
	job_kill_all();
	tcsetattr(STDIN, TCSANOW, &data_singleton()->jobc.shell_tmodes);
}
