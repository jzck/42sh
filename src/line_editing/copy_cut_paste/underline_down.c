/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   underline_down.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 11:43:40 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/23 16:21:46 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		underline_down(char **str, size_t *pos, size_t pos_ref)
{
	size_t	pos_tmp;
	int		i;

	i = 0;
	pos_tmp = *pos;
	if ((*str)[pos_tmp] == '\n')
	{
		underline_right(str, pos, pos_ref);
		++pos_tmp;
	}
	i = ft_size_term();
	while (i && (*str)[pos_tmp] && (*str)[pos_tmp] != '\n')
	{
		underline_right(str, pos, pos_ref);
		++pos_tmp;
		--i;
	}
	if ((*str)[pos_tmp] == '\n')
	{
		underline_left(str, pos, pos_ref);
		--pos_tmp;
	}
	return (0);
}
