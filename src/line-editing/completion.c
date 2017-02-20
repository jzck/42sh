/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 14:15:55 by gwojda            #+#    #+#             */
/*   Updated: 2017/02/16 14:22:44 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_completion(int ret)
{
	size_t	tmp;
	size_t	pos_tmp;
	int		beg_len;
	char	boolean;

	boolean = 0;
	beg_len = ft_strlen(data_singleton()->line.input);
	if (((ret != TOUCHE_TAB && ret != 10)
	|| (ret == 10)) && !(data_singleton()->comp))
		return (0);
	tmp = POS;
	pos_tmp = POS;
	if (data_singleton()->comp || ret == TOUCHE_TAB)
		boolean = completion(ret);
	if (boolean || ret == 10)
	{
		ft_puttermcaps("cd");
		ft_current_str(STR, tmp);
		ft_get_next_str(STR, &tmp);
		ft_putnc('\b', tmp -
			(pos_tmp + ft_strlen(data_singleton()->line.input) - beg_len));
		POS = pos_tmp + ft_strlen(data_singleton()->line.input) - beg_len;
	}
	return (1);
}
