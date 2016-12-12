/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_copy_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 14:01:31 by sbenning          #+#    #+#             */
/*   Updated: 2016/12/09 18:22:38 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int			rl_copy_function(t_line *line, long int input)
{
	if (line->clipboard)
		ft_memdel((void **)&line->clipboard);
	if (rl_clipboard_new(line) < 0)
		return (-1);
	return (0);
	(void)input;
}
