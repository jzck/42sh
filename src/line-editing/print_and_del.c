/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_and_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:02:43 by gwojda            #+#    #+#             */
/*   Updated: 2017/01/22 15:02:02 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print(char **str, int ret, size_t *i)
{
	int j;

	j = 0;
	*str = ft_realloc_imput(*str, ret, *i);
	while (*((*str) + *i + j) && *((*str) + *i + j) != '\n')
	{
		ft_putchar(*((*str) + *i + j));
		++j;
	}
	ft_putnc('\b', j - 1);
	++(*i);
}

void	ft_suppr(char **str, size_t *i)
{
	size_t	tmp;

	--(*i);
	tmp = *i;
	*str = ft_remove_imput((*str), tmp);
	ft_get_beggin_with_curs(*str, i);
	ft_puttermcaps("cd");
	ft_current_str(*str, *i);
	ft_get_next_str(*str, i);
/*	if (ft_nb_last_line(*str, *i) == ft_size_term() - 2)
	{
		ft_puttermcaps("nd");
		ft_putnc('\b', *i - tmp);
	}
	else
		ft_putnc('\b', *i - tmp + 1);*/
	ft_putnc('\b', *i - tmp);
	(*i) = tmp;
}

void	ft_del(char **str, size_t *i)
{
	size_t	tmp;

	tmp = *i;
	*str = ft_remove_imput((*str), tmp);
	--(*i);
	ft_get_beggin_with_curs(*str, i);
	ft_puttermcaps("cd");
	ft_current_str(*str, *i);
	ft_get_next_str(*str, i);
/*	if (ft_nb_last_line(*str, *i) == ft_size_term() - 2)
	{
		ft_puttermcaps("nd");
		ft_putnc('\b', *i - tmp);
	}
	else
		ft_putnc('\b', *i - tmp + 1);*/
	ft_putnc('\b', *i - tmp);
	(*i) = tmp;
}
