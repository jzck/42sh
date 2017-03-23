/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   underline_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 20:55:24 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/22 22:59:02 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	underline_check_end_of_line(char *str, size_t pos)
{
	if (!str)
		return ;
	if (ft_nb_last_line(str, pos) == 0)
	{
		ft_putchar(str[pos]);
		ft_puttermcaps("le");
	}
}
