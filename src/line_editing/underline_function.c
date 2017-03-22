/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   underline_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 20:55:24 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/22 21:28:31 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	underline_check_end_of_line(char *str, size_t pos)
{
	if (!str)
		return ;
	if (ft_nb_last_line(str, pos) == 0)
	{
		ft_putchar(str[pos]);
		ft_puttermcaps("le");
	}
}

void		underline_right(char **str, size_t *pos, size_t pos_ref)
{
	if (!(*pos < ft_strlen(*str)))
		return ;
	if (*pos >= pos_ref)
	{
		ft_puttermcaps("mr");
		data_singleton()->line.copy_tmp = ft_realloc_imput(data_singleton()->
		line.copy_tmp, (*str)[*pos], data_singleton()->line.pos_tmp);
		ft_putchar((*str)[*pos]);
		ft_puttermcaps("me");
		++(data_singleton()->line.pos_tmp);
		++(*pos);
		underline_check_end_of_line(*str, *pos);
	}
	else
	{
		data_singleton()->line.copy_tmp = ft_remove_imput(data_singleton()->
		line.copy_tmp, data_singleton()->line.pos_tmp);
		ft_putchar((*str)[*pos]);
		if (data_singleton()->line.pos_tmp)
			--(data_singleton()->line.pos_tmp);
		++(*pos);
		underline_check_end_of_line(*str, *pos);
	}
}

void		underline_left(char **str, size_t *pos, size_t pos_ref)
{
	if (!*pos)
		return ;
	if (*pos > pos_ref)
	{
		--(*pos);
		ft_putchar('\b');
		ft_putchar((*str)[*pos]);
		underline_check_end_of_line(*str, *pos + 1);
		ft_putchar('\b');
		data_singleton()->line.copy_tmp = ft_remove_imput(data_singleton()->
		line.copy_tmp, data_singleton()->line.pos_tmp);
		if (data_singleton()->line.pos_tmp)
			--(data_singleton()->line.pos_tmp);
	}
	else
	{
		data_singleton()->line.pos_tmp = 0;
		--(*pos);
		ft_putchar('\b');
		ft_puttermcaps("mr");
		data_singleton()->line.copy_tmp = ft_realloc_imput(data_singleton()->
		line.copy_tmp, (*str)[*pos], data_singleton()->line.pos_tmp);
		ft_putchar((*str)[*pos]);
		underline_check_end_of_line(*str, *pos + 1);
		ft_puttermcaps("me");
		ft_putchar('\b');
	}
}
