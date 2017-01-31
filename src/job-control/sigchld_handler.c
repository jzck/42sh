/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigchld_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 17:37:56 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/31 15:09:29 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigchld_handler(int signo)
{
	t_data	*data;

	(void)signo;
	data = data_singleton();
}
