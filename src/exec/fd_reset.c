/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_reset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 19:20:05 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/29 19:47:01 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fd_reset(t_data	*data)
{
	dup2(data->save_in, STDIN);
	dup2(data->save_out, STDOUT);
	data->fdin = STDIN;
	data->fdout = STDOUT;
}
