/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolz_parseur.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 16:14:46 by gwojda            #+#    #+#             */
/*   Updated: 2017/01/19 16:43:19 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_realloc_imput(char *str, int a, size_t pos)
{
	int		i;
	char	tmp[2];
	char	*str_tmp;
	char	*new_str;

	i = 0;
	tmp[0] = (char)a;
	tmp[1] = '\0';
	if (!str)
	{
		new_str = ft_strdup(tmp);
		return (new_str);
	}
	str_tmp = ft_strndup(str, pos);
	new_str = ft_strjoin(str_tmp, tmp);
	free(str_tmp);
	str_tmp = ft_strjoin(new_str, str + pos);
	free(new_str);
	free(str);
	return (str_tmp);
}

char	*ft_remove_imput(char *str, size_t pos)
{
	int		i;
	char	*new_str;
	char	*new_str2;

	i = 0;
	if (!str)
		return (str);
	new_str = ft_strndup(str, pos);
	new_str2 = ft_strjoin(new_str, &str[pos + 1]);
	free(str);
	free(new_str);
	return (new_str2);
}

static int	ft_found_prev_word_pos(char *str, size_t *pos)
{
	size_t	tmp;

	tmp = *pos;
	while ((tmp) && (str[tmp] == ' ' || str[tmp] == '\n'))
		--tmp;
	while ((tmp) && str[tmp] != ' ' && str[tmp] != '\n')
		--tmp;
	return (tmp);
}

void	ft_found_prev_word(char *str, size_t *pos)
{
	size_t	tmp;

	tmp = *pos;
	ft_move_to_beggin(str, pos);
	*pos = tmp;
	tmp = ft_found_prev_word_pos(str, pos);
	write(1, str, tmp);
	*pos = tmp;
}

void	ft_found_next_word(char *str, size_t *pos)
{
	while (str[(*pos)] == ' ' || str[(*pos)] == '\n')
	{
		ft_putchar(str[(*pos)]);
		++(*pos);
	}
	while (str[(*pos)] && str[(*pos)] != ' ' && str[(*pos)] != '\n')
	{
		ft_putchar(str[(*pos)]);
		++(*pos);
	}
}
