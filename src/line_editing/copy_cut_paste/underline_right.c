/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   underline_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 22:50:52 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/23 16:25:34 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	reset_term_hard(void)
{
	ft_putnc('\b', ft_strlen(data_singleton()->line.copy_tmp));
	ft_putstr(data_singleton()->line.copy_tmp);
	ft_strdel(&data_singleton()->line.copy_tmp);
	data_singleton()->line.pos_tmp = 0;
	return (1);
}

static void	right_abs(char **str, size_t *pos)
{
	ft_puttermcaps("mr");
	ft_putstr("\x1b[38;5;196m");
	data_singleton()->line.copy_tmp = ft_realloc_imput(data_singleton()->
	line.copy_tmp, (*str)[*pos], data_singleton()->line.pos_tmp);
	ft_putchar((*str)[*pos]);
	ft_putstr("\033[22;37m");
	ft_puttermcaps("me");
	++(data_singleton()->line.pos_tmp);
	++(*pos);
	underline_check_end_of_line(*str, *pos);
}

static void	right_mv_back(char **str, size_t *pos)
{
	data_singleton()->line.copy_tmp = ft_remove_imput(data_singleton()->
	line.copy_tmp, data_singleton()->line.pos_tmp);
	ft_putchar((*str)[*pos]);
	if (data_singleton()->line.pos_tmp)
		--(data_singleton()->line.pos_tmp);
	++(*pos);
	underline_check_end_of_line(*str, *pos);
}

int			underline_right(char **str, size_t *pos, size_t pos_ref)
{
	if (!(*pos < ft_strlen(*str)))
		return (0);
	if ((*str)[*pos] == '\n')
		return (reset_term_hard());
	if (*pos >= pos_ref)
		right_abs(str, pos);
	else
		right_mv_back(str, pos);
	return (0);
}
