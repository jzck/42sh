/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_and_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:02:43 by gwojda            #+#    #+#             */
/*   Updated: 2017/01/23 15:13:57 by gwojda           ###   ########.fr       */
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
	char	boolean;

	boolean = 0;
	if ((*str)[*i - 1] != '\n')
		boolean = 1;
	--(*i);
	tmp = *i;
	if (boolean)
		ft_get_beggin_with_curs(*str, i);
	else
		ft_get_beggin(*str, i);
	*str = ft_remove_imput((*str), tmp);
	ft_puttermcaps("cd");
	ft_current_str(*str, *i);
	ft_get_next_str(*str, i);
	if (str[*i] && ft_found_next_char(*str, *i))
		++(*i);
	ft_putnc('\b', *i - tmp);
	(*i) = tmp;
	if (ft_strlen(*str) == 0)
		*str = NULL;
}

void	ft_del(char **str, size_t *i)
{
	size_t	tmp;

	tmp = *i;
	*str = ft_remove_imput((*str), tmp);
	if (*i)
		--(*i);
	ft_get_beggin_with_curs(*str, i);
	ft_puttermcaps("cd");
	ft_current_str(*str, *i);
	ft_get_next_str(*str, i);
	if (str[*i])
		++(*i);
	ft_putnc('\b', *i - tmp);
	(*i) = tmp;
}
