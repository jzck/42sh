/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_trailing_esc_nl.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:52:34 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/09 17:00:33 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		remove_trailing_esc_nl(char *str)
{
	char	*last;

	last = str + ft_strlen(str) - 1;
	if (*last == '\\')
	{
		*last = 0;
		return (1);
	}
	return (0);
}
