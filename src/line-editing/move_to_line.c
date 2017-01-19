/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:21:40 by gwojda            #+#    #+#             */
/*   Updated: 2017/01/19 16:43:01 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_up(size_t *pos, char *str)
{
	int	i;
	int	j;
	int	len;
	int	tmp;
	int	size_window;

	size_window = ft_size_term();
	i = 0;
	len = 0;
	j = 0;
	if (!*pos)
		return ;
	while (len < size_window && *pos - i)
	{
		if (i && str[*pos - i] == '\n')
		{
			ft_puttermcaps("up");
			tmp = ft_nb_last_line(str, *pos - 1 - i) + 3;
			if (ft_get_ind_prev(str, *pos - 1 - i))
				tmp -= 2;
			while (j < tmp - 1)
			{
				ft_puttermcaps("nd");
				++j;
			}
			if (!ft_get_ind_prev(str, *pos - 1 - i))
				ft_putchar('\b');
			len += ft_size_term() - tmp;
		}
		else
		{
			ft_putchar('\b');
			len++;
		}
		i++;
	}
	if (!(*pos - i))
	{
		(*pos) = 0;
		return ;
	}
	if (j)
	{
		ft_puttermcaps("nd");
		++(*pos);
	}
	*pos -= i;
}

static void	ft_down(size_t *pos, char *str)
{
	int		len;
	int		size_window;
	char	boolean;

	len = 0;
	boolean = 0;
	size_window = ft_size_term();
	while (str[*pos] && len < size_window)
	{
		if (str[*pos] == '\n' && !boolean)
		{
			len += size_window - ft_nb_last_line(str, *pos - 1) - 2;
			boolean = 1;
		}
		else if (str[*pos] == '\n' && boolean)
			return ;
		else
			++len;
		ft_putchar(str[*pos]);
		++(*pos);
	}
}

void		ft_move_to_line(int ret, size_t *pos, char *str)
{
	if (!str)
		return ;
	if (ret == TOUCHE_OPT_UP)
		ft_up(pos, str);
	else if (ret == TOUCHE_OPT_DOWN)
		ft_down(pos, str);
}
