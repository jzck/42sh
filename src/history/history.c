/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:22:19 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/17 12:09:42 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_clear_before_history(char **str)
{
	if (*str)
	{
		if (data_singleton()->line.pos)
		{
			--data_singleton()->line.pos;
			ft_get_beggin_with_curs(*str, &data_singleton()->line.pos);
		}
		ft_puttermcaps("cd");
		data_singleton()->line.pos = 0;
		ft_strdel(str);
	}
}

int			ft_history_down(char **str, size_t *pos)
{
	t_list_history	*head;

	head = data_singleton()->line.list_cur;
	if (!head)
		return (0);
	ft_clear_before_history(str);
	if (head->next)
		head = head->next;
	if (!head->str)
		*str = NULL;
	else
		if (!(*str = ft_strdup(head->str)))
			return (-1);
	if (*str)
		ft_current_str(*str, *pos);
	if (*str)
		*pos = ft_strlen_next(*str, *pos);
	else
		*pos = 0;
	data_singleton()->line.list_cur = head;
	return (0);
}

int			ft_history_up(char **str, size_t *pos)
{
	t_list_history	*head;

	head = data_singleton()->line.list_cur;
	if (!head)
		return (0);
	ft_clear_before_history(str);
	if (head->prev)
		head = head->prev;
	if (!head->str)
		*str = NULL;
	else
		if (!(*str = ft_strdup(head->str)))
			return (-1);
	if (*str)
		ft_current_str(*str, *pos);
	if (*str)
		*pos = ft_strlen_next(*str, *pos);
	else
		*pos = 0;
	data_singleton()->line.list_cur = head;
	return (0);
}
