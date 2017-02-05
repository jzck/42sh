/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:22:19 by gwojda            #+#    #+#             */
/*   Updated: 2017/02/05 17:00:18 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_clear_before_history(char **str)
{
	if (*str)
	{
		if (POS)
		{
			--POS;
			ft_get_beggin_with_curs(*str, &POS);
		}
		ft_puttermcaps("cd");
		POS = 0;
		ft_strdel(str);
	}
}

void		ft_history_down(void)
{
	t_list_history	*head;

	head = data_singleton()->line.list_cur;
	if (!head)
		return ;
	ft_clear_before_history(&STR);
	if (head->next)
		head = head->next;
	if (!head->str)
		STR = NULL;
	else
		STR = ft_strdup(head->str);
	if (STR)
		ft_current_str(STR, POS);
	if (STR)
		POS = ft_strlen_next(STR, POS);
	else
		POS = 0;
	data_singleton()->line.list_cur = head;
}

void		ft_history_up(void)
{
	t_list_history	*head;

	head = data_singleton()->line.list_cur;
	if (!head)
		return ;
	ft_clear_before_history(&STR);
	if (head->prev)
		head = head->prev;
	if (!head->str)
		STR = NULL;
	else
		STR = ft_strdup(head->str);
	if (STR)
		ft_current_str(STR, POS);
	if (STR)
		POS = ft_strlen_next(STR, POS);
	else
		POS = 0;
	data_singleton()->line.list_cur = head;
}
