/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_history.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 14:54:53 by gwojda            #+#    #+#             */
/*   Updated: 2017/01/25 15:48:52 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_history_builtin(void)
{
	size_t			len;
	t_list_history	*head;

	head = data_singleton()->line.list_end;
	len = 1;
	if (!head)
		return ;
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
}
