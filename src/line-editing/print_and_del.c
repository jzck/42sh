/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_and_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:02:43 by gwojda            #+#    #+#             */
/*   Updated: 2017/02/07 15:27:48 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_found_next_char(char *str, size_t i)
{
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		++i;
	}
	return (0);
}

void	ft_print(int ret)
{
	int		j;

	j = 0;
	STR = ft_realloc_imput(STR, ret, POS);
	while (*(STR + POS + j) && *(STR + POS + j) != '\n')
	{
		ft_putchar(*(STR + POS + j));
		++j;
	}
	ft_check_end_of_line(STR, POS + j);
	ft_putnc('\b', j - 1);
	++POS;
}

void	ft_suppr_2(char **str, size_t *i, size_t tmp)
{
	ft_puttermcaps("cd");
	ft_current_str(*str, *i);
	ft_get_next_str(*str, i);
	if (*i && (*str)[*i] && ft_found_next_char(*str, *i))
		++(*i);
	ft_putnc('\b', *i - tmp);
	(*i) = tmp;
	if (ft_strlen(*str) == 0)
		ft_strdel(str);
}

void	ft_suppr(void)
{
	size_t	tmp;
	char	boolean;

	boolean = 0;
	if (POS <= 0)
		return ;
	if (STR[POS - 1] != '\n')
		boolean = 1;
	--POS;
	tmp = POS;
	if (boolean)
	{
		ft_get_beggin_with_curs(STR, &POS);
		STR = ft_remove_imput(STR, tmp);
	}
	else
	{
		STR = ft_remove_imput(STR, tmp);
		ft_get_beggin(STR, &POS);
	}
	ft_suppr_2(&STR, &POS, tmp);
}

void	ft_del(void)
{
	size_t	tmp;

	tmp = POS;
	STR = ft_remove_imput(STR, tmp);
	if (!(STR && POS < ft_strlen(STR) + 1))
		return ;
	if (POS)
	{
		--POS;
		ft_get_beggin_with_curs(STR, &POS);
	}
	ft_puttermcaps("cd");
	ft_current_str(STR, POS);
	ft_get_next_str(STR, &POS);
	if (STR[POS] && STR[POS] != '\n')
		++POS;
	ft_putnc('\b', POS - tmp);
	POS = tmp;
}
