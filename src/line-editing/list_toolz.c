/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_toolz.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 11:37:47 by gwojda            #+#    #+#             */
/*   Updated: 2017/01/19 16:42:57 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list_history	*ft_create_history_list(char *str)
{
	t_list_history	*list;

	list = (t_list_history *)malloc(sizeof(t_list_history));
	if (!list)
		return (NULL);
	if (!str)
		list->str = NULL;
	else
		list->str = ft_strdup(str);
	list->prev = NULL;
	list->next = NULL;
	return (list);
}

void			ft_push_back_history(t_list_history **head, t_list_history *new)
{
	if (!*head)
	{
		*head = new;
		(*head)->prev = ft_create_history_list(NULL);
		(*head)->prev->next = (*head);
		(*head)->next = ft_create_history_list(NULL);
		(*head)->next->prev = (*head);
		(*head) = (*head)->next;
		return ;
	}
	while ((*head)->next)
		(*head) = (*head)->next;
	new->prev = (*head)->prev;
	(*head)->prev->next = new;
	new->next = (*head);
	(*head)->prev = new;
}

void			ft_get_head(t_list_history **head)
{
	if (head && *head)
	{
		while ((*head)->next && (*head)->next->str)
			(*head) = (*head)->next;
	}
}
