/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:04:18 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/29 20:21:17 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fd_redirect(t_data *data)
{
	if (data->fdin != STDIN)
	{
		/* ft_dprintf(2, "redirecting input: %i->STDIN\n", data->fdin); */
		dup2(data->fdin, STDIN);
		close(data->fdin);
	}
	if (data->fdout != STDOUT)
	{
		/* ft_dprintf(2, "redirecting output: %i->STDOUT\n", data->fdout); */
		dup2(data->fdout, STDOUT);
		close(data->fdout);
	}
}
