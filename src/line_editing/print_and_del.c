/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_and_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:02:43 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/21 10:14:46 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_found_next_char(char *str, size_t i)
{
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		++i;
	}
	return (0);
}

int			ft_print(int ret, char **str, size_t *pos)
{
	int		j;

	j = 0;
	if (ft_strlen(*str) > SIZE_LINE)
		return (0);
	if (!(*str = ft_realloc_imput(*str, ret, *pos)))
		return (-1);
	while (*(*str + *pos + j) && *(*str + *pos + j) != '\n')
	{
		ft_putchar(*(*str + *pos + j));
		++j;
	}
	ft_check_end_of_line(*str, *pos + j);
	ft_putnc('\b', j - 1);
	++(*pos);
	return (0);
}

static void	ft_suppr_2(char **str, size_t *i, size_t tmp)
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

int			ft_suppr(char **str, size_t *pos)
{
	size_t	tmp;
	char	boolean;

	boolean = 0;
	if (*pos <= 0)
		return (0);
	if ((*str)[*pos - 1] != '\n')
		boolean = 1;
	--(*pos);
	tmp = *pos;
	if (boolean)
	{
		ft_get_beggin_with_curs(*str, pos);
		if (!(*str = ft_remove_imput(*str, tmp)))
			return (-1);
	}
	else
	{
		if (!(*str = ft_remove_imput(*str, tmp)))
			return (-1);
		ft_get_beggin(*str, pos);
	}
	ft_suppr_2(str, pos, tmp);
	return (0);
}

int			ft_del(char **str, size_t *pos)
{
	size_t	tmp;

	tmp = *pos;
	if (!(*str = ft_remove_imput(*str, tmp)))
		return (-1);
	if (!(*str && *pos < ft_strlen(*str) + 1))
		return (0);
	if (*pos)
	{
		--(*pos);
		ft_get_beggin_with_curs(*str, pos);
	}
	ft_puttermcaps("cd");
	ft_current_str(*str, *pos);
	ft_get_next_str(*str, pos);
	if ((*str)[*pos] && (*str)[*pos] != '\n')
		++(*pos);
	ft_putnc('\b', *pos - tmp);
	*pos = tmp;
	return (0);
}
