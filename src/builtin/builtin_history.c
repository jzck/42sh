/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_history.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 14:54:53 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/20 14:04:02 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		builtin_history(const char *path, char *const av[], char *const envp[])
{
	size_t			len;
	t_list_history	*head;

	(void)path;
	(void)av;
	(void)envp;
	head = data_singleton()->line.list_end;
	len = 1;
	if (!head)
		return (builtin_return_status(0, 0));
	if (head && !head->str)
		head = head->next;
	while (head && head->str)
	{
		ft_putnc(' ', ft_nbr_len(data_singleton()->line.list_size)
		- ft_nbr_len(len));
		ft_printf("%zu  %s\n", len, head->str);
		++len;
		head = head->next;
	}
	return (builtin_return_status(0, 0));
}
