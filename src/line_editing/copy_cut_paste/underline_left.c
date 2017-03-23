/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   underline_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 22:54:28 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/22 23:08:58 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	reset_term_hard(void)
{
	ft_putstr(data_singleton()->line.copy_tmp);
	ft_putnc('\b', ft_strlen(data_singleton()->line.copy_tmp));
	ft_strdel(&data_singleton()->line.copy_tmp);
	data_singleton()->line.pos_tmp = 0;
	return (0);
}

static void	left_abs(char **str, size_t *pos)
{
	--(*pos);
	ft_putchar('\b');
	data_singleton()->line.pos_tmp = 0;
	ft_puttermcaps("mr");
	data_singleton()->line.copy_tmp = ft_realloc_imput(data_singleton()->
	line.copy_tmp, (*str)[*pos], data_singleton()->line.pos_tmp);
	ft_putchar((*str)[*pos]);
	underline_check_end_of_line(*str, *pos + 1);
	ft_puttermcaps("me");
	ft_putchar('\b');
}

static void	left_mv_back(char **str, size_t *pos)
{
	--(*pos);
	ft_putchar('\b');
	ft_putchar((*str)[*pos]);
	underline_check_end_of_line(*str, *pos + 1);
	data_singleton()->line.copy_tmp = ft_remove_imput(data_singleton()->
	line.copy_tmp, data_singleton()->line.pos_tmp);
	if (data_singleton()->line.pos_tmp)
		--(data_singleton()->line.pos_tmp);
	ft_putchar('\b');
}

int			underline_left(char **str, size_t *pos, size_t pos_ref)
{
	if (!*pos)
		return (1);
	if ((*str)[*pos - 1] == '\n')
		return (reset_term_hard());
	if (*pos > pos_ref)
		left_mv_back(str, pos);
	else
		left_abs(str, pos);
	return (1);
}
