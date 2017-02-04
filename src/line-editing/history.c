/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:22:19 by gwojda            #+#    #+#             */
/*   Updated: 2017/02/04 15:20:49 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_clear_before_history(char **str)
{
	size_t			*pos;

	pos = &POS;
	if (*str)
	{
		if (*pos)
		{
			--(*pos);
			ft_get_beggin_with_curs(*str, pos);
		}
		ft_puttermcaps("cd");
		*pos = 0;
		ft_strdel(str);
	}
}

void		ft_history_down(void)
{
	t_list_history	*head;
	char			**str;
	size_t			*pos;

	str = &STR;
	pos = &POS;
	head = data_singleton()->line.list_cur;
	if (!head)
		return ;
	ft_clear_before_history(str);
	if (head->next)
		head = head->next;
	if (!head->str)
		*str = NULL;
	else
		*str = ft_strdup(head->str);
	if (*str)
		ft_current_str(*str, *pos);
	if (*str)
		*pos = ft_strlen_next(*str, *pos);
	else
		*pos = 0;
	data_singleton()->line.list_cur = head;
}

void		ft_history_up(void)
{
	t_list_history	*head;
	char			**str;
	size_t			*pos;

	str = &STR;
	pos = &POS;
	head = data_singleton()->line.list_cur;
	if (!head)
		return ;
	ft_clear_before_history(str);
	if (head->prev)
		head = head->prev;
	if (!head->str)
		*str = NULL;
	else
		*str = ft_strdup(head->str);
	if (*str)
		ft_current_str(*str, *pos);
	if (*str)
		*pos = ft_strlen_next(*str, *pos);
	else
		*pos = 0;
	data_singleton()->line.list_cur = head;
}
