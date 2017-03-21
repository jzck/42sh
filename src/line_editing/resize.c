/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 10:56:08 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/21 18:11:12 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigwinch_resize(int sig)
{
	size_t	pos_tmp;

	pos_tmp = 0;
	(void)sig;
	if (data_singleton()->comp)
	{
		c_term_resize(data_singleton()->comp);
		ft_puttermcaps("cl");
		data_singleton()->line.is_prompt ? ft_prompt() : ft_putstr("> ");
		ft_putall_current_str(data_singleton()->line.input, &pos_tmp);
		ft_putnc('\b', pos_tmp - data_singleton()->line.pos);
		c_dispatcher(data_singleton());
	}
}
