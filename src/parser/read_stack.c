/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:32:10 by ariard            #+#    #+#             */
/*   Updated: 2017/02/09 16:02:30 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char			*read_state(t_sym current)
{
	if (current == CMD_NAME)
		return ("CMD_NAME");
	if (current == NEWLINE_LIST)
		return ("NEWLINE_LIST");
	if (current == SYM_DLESS)
		return ("DLESS");
	if (current == SYM_DGREAT)
		return ("DGREAT");
	if (current == SYM_GREATAND)
		return ("GREATAND");
	if (current == SYM_GREAT)
		return ("GREAT");
	if (current == SYM_LESSAND)
		return ("LESSAND");
	if (current == SYM_LESS)
		return ("LESS");
	return (NULL);
}

int			ft_read_stack(t_sym	stack[], int size)
{
	while (stack[size])
		ft_putstr(read_state(stack[size--]));
	return (0);
}
