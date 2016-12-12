/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_cut_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 14:19:20 by sbenning          #+#    #+#             */
/*   Updated: 2016/12/09 16:24:12 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int			rl_cut_function(t_line *line, long int input)
{
	if (line->clipboard)
		ft_memdel((void **)&line->clipboard);
	if (rl_clipboard_new_cut(line) < 0)
		return (-1);
	rl_reset_display_post(line);
	return (0);
	(void)input;
}
