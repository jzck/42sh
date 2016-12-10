/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_stack_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 01:06:54 by sbenning          #+#    #+#             */
/*   Updated: 2016/12/10 09:54:10 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int			rl_stack_line(t_line *line)
{
	t_list	*elem;

	elem = ft_lstnew(line->input, line->used);
	if (elem == NULL)
		return (-1);
	ft_lsteadd(&line->stack, elem);
	ft_memdel((void **)&line->input);
	line->pos = 0;
	line->size = 0;
	line->used = 0;
	return (0);
}
