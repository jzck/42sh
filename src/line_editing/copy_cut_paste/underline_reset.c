/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   underline_reset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 21:14:07 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/23 11:06:25 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	reset_term(char **str, size_t *pos)
{
	size_t	pos_ref;

	pos_ref = *pos;
	if (*pos)
	{
		--(*pos);
		ft_get_beggin_with_curs(*str, pos);
	}
	ft_puttermcaps("cd");
	ft_current_str(*str, *pos);
	ft_get_next_str(*str, pos);
	ft_putnc('\b', *pos - pos_ref + (((*str)[*pos]) ? 1 : 0));
	(*pos) = pos_ref;
}

void	reset_and_remove_term(char **str, size_t *pos, char *copy_tmp)
{
	size_t	pos_ref;

	pos_ref = *pos;
	if (!data_singleton()->line.pos_tmp)
		pos_ref += ft_strlen(data_singleton()->line.copy_tmp);
	if (*pos)
	{
		--(*pos);
		ft_get_beggin_with_curs(*str, pos);
	}
	while (*copy_tmp)
	{
		--pos_ref;
		*str = ft_remove_imput(*str, pos_ref);
		++copy_tmp;
	}
	ft_puttermcaps("cd");
	ft_current_str(*str, *pos);
	ft_get_next_str(*str, pos);
	ft_putnc('\b', *pos - pos_ref + (((*str)[*pos]) ? 1 : 0));
	(*pos) = pos_ref;
}
