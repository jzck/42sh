/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 18:07:50 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/07 18:12:34 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	data_exit(t_data *data)
{
	ft_strdel(&data->line.input);
	ft_dlstdel(&data->line.history, &ft_lst_bfree);
	ft_lstdel(&data->line.qstack, &ft_lst_cfree);
	ft_sstrfree(data->env);
}
