/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_and_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:02:43 by gwojda            #+#    #+#             */
/*   Updated: 2017/01/19 18:08:54 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
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
*/
void	ft_print(char **str, int ret, size_t *i)
{
	size_t len;
	size_t tmp_len;
	char	boolean;
	char	boolean2;

	len = 0;
	boolean = 0;
	boolean2 = 0;
	*str = ft_realloc_imput(*str, ret, *i);
	tmp_len = ft_strlen(*str);
	ft_puttermcaps("cd");
	write(1, *str + *i, 1);
	if ((ft_nb_last_line(*str, *i + 1)
	+ (len % ft_size_term()) == ft_size_term() - 1) && (*str)[*i + 1] == '\n')
	{
		ft_putchar(' ');
		boolean2 = 1;
	}
	if ((*str)[*i + 1] == '\n' && (*str)[*i + 2] && ft_strlen(*str) > *i + 2)
		write(1, *str + *i + 1, ft_strlen(*str + *i + 2));
	else
		write(1, *str + *i + 1, ft_strlen(*str + *i + 1));
	++(*i);
	while ((*str)[*i + len] && (*str)[*i + len] != '\n')
		++len;
	if ((*i && !(ft_nb_last_line(*str, *i)
	+ (len % ft_size_term()))) || ft_nb_last_line(*str, *i)
	+ (len % ft_size_term()) == ft_size_term() - 1)
	{
		--(tmp_len);
		ft_move_to_beggin(*str, &tmp_len);
		boolean = 1;
	}
	else
		ft_move_to_beggin(*str, &tmp_len);
	if (boolean2)
		ft_puttermcaps("up");
	write(1, *str, *i);
	if (boolean)
		ft_putstr(" \b");
}

void	ft_suppr_1(char **str, size_t *i)
{
	int j;

	j = 0;
	write(1, "\b", 1);
	while (*((*str) + *i + j) && *((*str) + *i + j) != '\n')
	{
		ft_putchar(*((*str) + *i + j));
		++j;
	}
	--(*i);
	write(1, " ", 1);
	if (ft_nb_last_line(*str, *i) + j == ft_size_term() - 2)
	{
		ft_puttermcaps("nd");
		ft_putnc('\b', j);
	}
	else
		ft_putnc('\b', j + 1);
	*str = ft_remove_imput((*str), (*i));
}

void	ft_suppr_2(char **str, size_t *i)
{
	int		j;

	j = 0;
	ft_puttermcaps("up");
	ft_move_left(*i - 1, *str);
	ft_puttermcaps("cd");
	ft_putstr(*str + *i);
	ft_move_suppr(*str, *i);
	--(*i);
	*str = ft_remove_imput((*str), (*i));
}

void	ft_del_1(char **str, size_t *i)
{
	int j;

	j = 0;
	while (*((*str) + *i + j + 1) && *((*str) + *i + j + 1) != '\n')
	{
		ft_putchar(*((*str) + *i + j + 1));
		++j;
	}
	write(1, " ", 1);
	if (ft_nb_last_line(*str, *i) + j == ft_size_term() - 2)
		ft_putnc('\b', j);
	else
		ft_putnc('\b', j + 1);
	(*str) = ft_remove_imput((*str), (*i));
}

void	ft_del_2(char **str, size_t *i)
{
	int		j;

	j = 1;
	ft_puttermcaps("cd");
	ft_putstr(*str + *i + 1);
	ft_move_dell(*str, *i);
	*str = ft_remove_imput((*str), (*i));
}
