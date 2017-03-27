/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobc_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 03:09:41 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/27 15:59:29 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			jobc_destroy(t_jobc *jobc)
{
	if (jobc)
		ft_lstdel(&jobc->first_job, job_free);
	return (0);
}
