/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_merge_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 01:25:03 by sbenning          #+#    #+#             */
/*   Updated: 2017/01/21 22:34:25 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int			rl_merge_line(t_line *line)
{
	t_list	*next;
	char	*chunk;
	size_t	size;

	while (line->stack)
	{
		next = line->stack->next;
		chunk = (char *)line->stack->content;
		size = line->stack->content_size - 1;
		if (input_maj(line, chunk, size) < 0)
			return (-1);
		line->pos += size;
	/*	if (next)
		{
			if (input_maj(line, "\n", 1) < 0)
				return (-1);
			line->pos += 1;
		}
	*/	free(chunk);
		free(line->stack);
		line->stack = next;
	}
	return (0);
}
