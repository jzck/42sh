/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_stack_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 01:06:54 by sbenning          #+#    #+#             */
/*   Updated: 2017/01/21 22:39:22 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int			rl_stack_line(t_line *line)
{
	t_list	*elem;

	elem = ft_lstnew(line->input, line->used + 1);
	if (elem == NULL)
		return (-1);
	ft_lsteadd(&line->stack, elem);
	ft_memdel((void **)&line->input);
	line->pos = 0;
	line->size = 0;
	line->used = 0;
	if (RL_NOT(line->bitset, RL_ESC))
		return (0);
	elem = ft_lstnew("\n", 2);
	if (elem == NULL)
		return (-1);
	ft_lsteadd(&line->stack, elem);
	return (0);
}
