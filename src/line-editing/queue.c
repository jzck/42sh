/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 16:52:57 by gwojda            #+#    #+#             */
/*   Updated: 2017/02/18 13:58:29 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_read_it_3(char **str, char t[5], size_t *pos, int *j)
{
	int		i;

	i = 0;
	while (i < 4 && t[i] == '\0')
		++i;
	while (i < 4)
	{
		if (t[i] && ft_isprint(t[i]))
		{
			*str = ft_realloc_imput(*str, t[i], *pos);
			++(*pos);
			++(*j);
		}
		++i;
	}
}

static void	ft_read_it_2(int input, char t[5])
{
	t[3] = (input / ft_pow(256, 3)) ? (input / ft_pow(256, 3)) : '\0';
	if (t[3])
		input = input % ft_pow(256, 3);
	t[2] = (input / ft_pow(256, 2)) ? (input / ft_pow(256, 2)) : '\0';
	if (t[2])
		input = input % ft_pow(256, 2);
	t[1] = (input / ft_pow(256, 1)) ? (input / ft_pow(256, 1)) : '\0';
	if (t[1])
		input = input % ft_pow(256, 1);
	t[0] = (input / ft_pow(256, 0)) ? (input / ft_pow(256, 0)) : '\0';
	if (t[0])
		input = input % ft_pow(256, 0);
	t[4] = '\0';
}

void		ft_read_it(int input, size_t *pos, char **str)
{
	int		j;
	char	t[5];
	size_t	pos_tmp;

	j = 0;
	pos_tmp = *pos;
	if (input == TOUCHE_DELETE || input < 0 || input == 892427035 ||
	input == 126 || input == 993090331 || input == 925981467 ||
	input == 21298 || input == 892427035 || input == 8270395 || input ==
	942758683 || input == 993090331 || input == 18489 || input == 17977)
		return ;
	ft_read_it_2(input, t);
	ft_read_it_3(str, t, pos, &j);
	if (!*str)
		return ;
	*pos = pos_tmp;
	ft_current_str((*str), *pos);
	ft_get_next_str((*str), pos);
	ft_putnc('\b', *pos - (pos_tmp + j));
	*pos = (pos_tmp + j);
}
