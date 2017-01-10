/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_singleton.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 11:36:39 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/10 11:47:11 by jhalford         ###   ########.fr       */
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
