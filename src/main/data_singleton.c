/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_singleton.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 11:19:51 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/15 15:41:08 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_data		*data_singleton()
{
	static t_data	*data = NULL;

	if (data == NULL)
		data = malloc(sizeof(t_data));
	return (data);
}
