/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_touch_toolz.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 16:42:54 by gwojda            #+#    #+#             */
/*   Updated: 2017/01/24 10:21:48 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_history_2(char **str, int ret, t_list_history **head, size_t *pos)
{
	if (*str)
	{
		if (*pos)
			--(*pos);
		ft_get_beggin_with_curs(*str, pos);
		ft_puttermcaps("cd");
		*pos = 0;
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
			ft_current_str(*str, *pos);
	}
}

void		ft_history(char **str, int ret, t_list_history **head, size_t *pos)
{
	if (!*head)
		return ;
	ft_history_2(str, ret, head, pos);
	if (ret == FLECHE_HAUT)
	{
		if ((*head)->prev)
			(*head) = (*head)->prev;
		if (!(*head)->str)
			*str = NULL;
		else
			*str = ft_strdup((*head)->str);
		if (*str)
			ft_current_str(*str, *pos);
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
