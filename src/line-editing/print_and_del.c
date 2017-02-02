/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_and_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:02:43 by gwojda            #+#    #+#             */
/*   Updated: 2017/02/02 15:10:50 by gwojda           ###   ########.fr       */
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
	char	**str;
	size_t	*i;

	j = 0;
	str = &data_singleton()->line.input;
	i = &data_singleton()->line.pos;
	*str = ft_realloc_imput(*str, ret, *i);
	while (*((*str) + *i + j) && *((*str) + *i + j) != '\n')
	{
		ft_putchar(*((*str) + *i + j));
		++j;
	}
	ft_check_end_of_line(*str, *i + j);
	ft_putnc('\b', j - 1);
	++(*i);
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
	char	**str;
	size_t	*i;

	str = &data_singleton()->line.input;
	i = &data_singleton()->line.pos;
	boolean = 0;
	if (*i <= 0)
		return ;
	if ((*str)[*i - 1] != '\n')
		boolean = 1;
	--(*i);
	tmp = *i;
	if (boolean)
	{
		ft_get_beggin_with_curs(*str, i);
		*str = ft_remove_imput((*str), tmp);
	}
	else
	{
		*str = ft_remove_imput((*str), tmp);
		ft_get_beggin(*str, i);
	}
	ft_suppr_2(str, i, tmp);
}

void	ft_del(void)
{
	size_t	tmp;
	char	**str;
	size_t	*i;

	str = &data_singleton()->line.input;
	i = &data_singleton()->line.pos;
	tmp = *i;
	*str = ft_remove_imput((*str), tmp);
	if (!((*str) && (*i) < ft_strlen((*str))))
		return ;
	if (*i)
	{
		--(*i);
		ft_get_beggin_with_curs(*str, i);
	}
	ft_puttermcaps("cd");
	ft_current_str(*str, *i);
	ft_get_next_str(*str, i);
	if ((*str)[*i])
		++(*i);
	ft_putnc('\b', *i - tmp);
	(*i) = tmp;
}
