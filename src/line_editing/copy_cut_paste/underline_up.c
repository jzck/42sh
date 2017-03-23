/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   underline_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 11:35:48 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/23 16:22:12 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		underline_up(char **str, size_t *pos, size_t pos_ref)
{
	size_t	pos_tmp;
	int		i;

	i = 0;
	pos_tmp = *pos;
	if ((*str)[pos_tmp] == '\n')
	{
		underline_left(str, pos, pos_ref);
		--pos_tmp;
	}
	i = ft_size_term();
	while (i && (pos_tmp && (*str)[pos_tmp] != '\n')
	&& (pos_tmp + 1 > 0 && (*str)[pos_tmp - 1] != '\n'))
	{
		underline_left(str, pos, pos_ref);
		--pos_tmp;
		--i;
	}
	*pos = pos_tmp;
	return (0);
}
