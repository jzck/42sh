/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_singleton.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 11:36:39 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/03 15:25:13 by gwojda           ###   ########.fr       */
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
