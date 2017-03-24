/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_job_in_background.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:03:29 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/24 17:24:46 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		put_job_in_background(t_job *j, int cont)
{
	if (cont)
		if (kill(-j->pgid, SIGCONT) < 0)
			SH_ERR("kill(): %s", strerror(errno));
	return (0);
}
