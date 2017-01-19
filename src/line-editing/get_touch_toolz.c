/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_touch_toolz.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 16:42:54 by gwojda            #+#    #+#             */
/*   Updated: 2017/01/19 16:42:45 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_history_2(char **str, int ret, t_list_history **head)
{
	if (*str)
	{
		ft_curse_move(*str);
		ft_strdel(str);
	}
	if (ret == FLECHE_BAS)
	{
		if ((*head)->next)
			(*head) = (*head)->next;
		if (!(*head)->str)
			*str = NULL;
		else
			*str = ft_strdup((*head)->str);
		if (*str)
			ft_putstr(*str);
	}
}

void		ft_history(char **str, int ret, t_list_history **head)
{
	if (!*head)
		return ;
	ft_history_2(str, ret, head);
	if (ret == FLECHE_HAUT)
	{
		if ((*head)->prev)
			(*head) = (*head)->prev;
		if (!(*head)->str)
			*str = NULL;
		else
			*str = ft_strdup((*head)->str);
		if (*str)
			ft_putstr(*str);
	}
}

void		ft_move_to_word(int ret, size_t *pos, char *str)
{
	if (!str)
		return ;
	if (ret == TOUCHE_OPT_LEFT)
		ft_found_prev_word(str, pos);
	else if (ret == TOUCHE_OPT_RIGHT)
		ft_found_next_word(str, pos);
}
