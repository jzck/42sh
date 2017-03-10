/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:11:57 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/08 17:43:14 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_nb_of_line(char *str, size_t pos)
{
	int	len;

	len = 1;
	if (pos && str[pos] == '\n')
		--pos;
	len += data_singleton()->line.prompt_size;
	len += ft_get_size_prev(str, pos);
	return (len / ft_size_term());
}
