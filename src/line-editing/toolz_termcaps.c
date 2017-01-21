/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolz_termcaps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 12:35:11 by gwojda            #+#    #+#             */
/*   Updated: 2017/01/21 14:31:47 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	return (len);
}

int		ft_nb_line(char *str, size_t pos)
{
	int	len;

	len = 0;
	if (!ft_get_ind_prev(str, pos))
		len += data_singleton()->line.prompt_size;
	len += ft_get_size_prev(str, pos);
	return (len / ft_size_term());
}

int		ft_nb_last_line(char *str, size_t pos)
{
	int	len;

	len = 0;
	if (str[pos] == '\n')
		--pos;
	if (!ft_get_ind_prev(str, pos))
		len += data_singleton()->line.prompt_size;
	len += ft_get_size_prev(str, pos);
	return (len % ft_size_term());
}

void	ft_move_to_beggin(char *str, size_t *pos)
{
	size_t	str_len;
	int		prompt_size;

	prompt_size = data_singleton()->line.prompt_size;
	str_len = 0;
	if (!str)
		return ;
	if (str[*pos] == '\n')
	{
		ft_putchar('\b');
		--(*pos);
	}
	while (*pos && str[*pos] != '\n')
	{
		ft_putchar('\b');
		--(*pos);
	}
	while (*pos && --prompt_size + 2)
		ft_puttermcaps("nd");
	while (*pos)
	{
		if (str[*pos] == '\n')
		{
			ft_printf("\n\n\nft_nb_line(str, *pos - 1) =  %d\n\n\n", ft_nb_line(str, *pos - 1));
			str_len = ft_nb_line(str, *pos - 1) + 1;
			while (str_len)
			{
				ft_puttermcaps("up");
				--str_len;
			}
		}
		--(*pos);
	}
}
