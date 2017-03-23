/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   underline_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 23:18:15 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/22 23:42:27 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	underline_end(char **str, size_t *pos, size_t pos_ref)
{
	size_t	pos_tmp;

	pos_tmp = *pos;
	if ((*str)[pos_tmp] == '\n')
	{
		underline_right(str, pos, pos_ref);
		++pos_tmp;
	}
	while ((*str)[pos_tmp] && (*str)[pos_tmp] != '\n')
	{
		underline_right(str, pos, pos_ref);
		++pos_tmp;
	}
	if ((*str)[pos_tmp] == '\n')
	{
		underline_left(str, pos, pos_ref);
		--pos_tmp;
	}
}
