/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   underline_home.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 23:11:05 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/23 16:22:01 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		underline_home(char **str, size_t *pos, size_t pos_ref)
{
	size_t	pos_tmp;

	pos_tmp = *pos;
	if ((*str)[pos_tmp] == '\n')
	{
		underline_left(str, pos, pos_ref);
		--pos_tmp;
	}
	while ((pos_tmp && (*str)[pos_tmp] != '\n')
	&& (pos_tmp + 1 > 0 && (*str)[pos_tmp - 1] != '\n'))
	{
		underline_left(str, pos, pos_ref);
		--pos_tmp;
	}
	*pos = pos_tmp;
	return (0);
}
