/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 18:42:31 by sbenning          #+#    #+#             */
/*   Updated: 2016/12/12 10:28:59 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"


int			input_extend(t_line *line, int size)
{
	char	*tmp;

	size = (RL_OFFSET > size ? RL_OFFSET : size) + line->size;
	if ((tmp = ft_strnew(size)) == NULL)
		return (-1);
	if (line->input)
	{
		ft_memcpy(tmp, line->input, line->size);
		free(line->input);
	}
	line->input = tmp;
	line->size = size;
	return (0);
}

int			rl_dynamic_buffer_extend(t_line *line, int size)
{
	return (input_extend(line, size));
}

int		input_maj(t_line *line, char *str, int size)
{
	if (line->used + size >= line->size)
	{
		if (rl_dynamic_buffer_extend(line, size) < 0)
			return (-1);
	}
	ft_memcpy(line->input + line->pos, str, size);
	if (line->pos + size > line->used)
		line->used = line->pos + size;
	return (0);
}

int			input_move(t_line *line, char *str, int size)
{
	char	*dup;

	if (line->used + size >= line->size)
	{
		if (rl_dynamic_buffer_extend(line, size) < 0)
			return (-1);
	}
	if ((dup = ft_strdup(line->input + line->pos)) == NULL)
		return (-1);
	ft_memcpy(line->input + line->pos, str, size);
	ft_memcpy(line->input + line->pos + size, dup, ft_strlen(dup));
	free(dup);
	line->used += size;
	return (0);
}

void		input_remove(t_line *line, int size)
{
	char	*start;

	if (size < 0)
	{
		start = line->input + line->pos;
		size *= -1;
	}
	else
		start = (line->input + line->pos) - size;
	ft_strcpy(start, start + size);
	line->used -= size;
	ft_bzero(line->input + line->used, line->size - line->used);
}


int			rl_dynamic_buffer_replace(t_line *line, char *str, int size)
{
	return (input_maj(line, str, size));
}

int			rl_dynamic_buffer_insert(t_line *line, char *str, int size)
{
	return (input_move(line, str, size));
}

void		rl_dynamic_buffer_remove(t_line *line, int size)
{
	input_remove(line, size);
}
