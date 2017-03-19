/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   home_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 11:13:24 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/17 11:54:33 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_end(char **str, size_t *pos)
{
	if (!*str)
		return (0);
	if (*pos)
	{
		--(*pos);
		ft_get_beggin_with_curs(*str, pos);
	}
	ft_puttermcaps("cd");
	while ((*str)[*pos])
		++(*pos);
	ft_get_beggin(*str, pos);
	ft_current_str(*str, *pos);
	ft_get_next_str(*str, pos);
	return (0);
}

int			ft_home(char **str, size_t *pos)
{
	if (!*str)
		return (0);
	if (*pos)
	{
		--(*pos);
		ft_get_beggin_with_curs(*str, pos);
		if ((*str)[*pos + 1] == '\n')
			ft_puttermcaps("nd");
	}
	ft_puttermcaps("cd");
	*pos = 0;
	ft_current_str(*str, *pos);
	ft_get_next_str(*str, pos);
	ft_check_end_of_line(*str, *pos);
	if (!(*str)[*pos])
		--(*pos);
	ft_get_beggin_with_curs(*str, pos);
	return (0);
}
