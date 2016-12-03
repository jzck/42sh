/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:04:18 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/03 11:58:27 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fd_redirect(t_data *data)
{
	if (data->fdin != STDIN)
	{
		dup2(data->fdin, STDIN);
		close(data->fdin);
	}
	if (data->fdout != STDOUT)
	{
		dup2(data->fdout, STDOUT);
		close(data->fdout);
	}
}
