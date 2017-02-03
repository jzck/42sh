/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 14:15:55 by gwojda            #+#    #+#             */
/*   Updated: 2017/02/03 16:10:54 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_completion(int ret)
{
	size_t	tmp;
	char	boolean;

	boolean = 0;
	if (((ret != TOUCHE_TAB && ret != 10)
	|| (ret == 10)) && !(data_singleton()->comp))
		return (0);
	tmp = data_singleton()->line.pos;
	if (data_singleton()->comp || ret == TOUCHE_TAB)
		boolean = completion(ret);
	if (boolean || ret == 10)
	{
		ft_puttermcaps("cd");
		ft_current_str(data_singleton()->line.input, tmp);
		ft_get_next_str(data_singleton()->line.input, &tmp);
		data_singleton()->line.pos = tmp;
	}
	return (1);
}
