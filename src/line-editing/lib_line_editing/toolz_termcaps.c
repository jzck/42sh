/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolz_termcaps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 12:35:11 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/07 17:33:05 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_put(int nb)
{
	write(1, &nb, 1);
	return (1);
}

int		ft_get_ind_prev(char *str, size_t pos)
{
	while (pos && str[pos] != '\n')
		--pos;
	return (pos);
}

int		ft_get_size_prev(char *str, size_t pos)
{
	size_t	len;

	len = 0;
	while (pos && str[pos] != '\n')
	{
		--pos;
		++len;
	}
	if (str[pos] == '\n')
		--len;
	return (len);
}

int		ft_nb_last_line(char *str, size_t pos)
{
	int	len;

	len = 1;
	if (pos && str[pos] == '\n')
		--pos;
	len += data_singleton()->line.prompt_size;
	len += ft_get_size_prev(str, pos);
	return ((len) ? len % ft_size_term() : -1);
}

void	ft_check_end_of_line(char *str, size_t pos)
{
	if (!str)
		return ;
	if (ft_nb_last_line(str, pos) == 0)
	{
		ft_putchar(' ');
		ft_puttermcaps("le");
	}
}
