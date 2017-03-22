/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_cut_paste.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 12:45:06 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/22 20:52:24 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_v(char **str, size_t *pos)
{
	size_t	tmp_pos;
	int		i;
	char	*tmp;

	i = -1;
	tmp_pos = *pos;
	tmp = data_singleton()->line.copy_tmp;
	if (!*str || !tmp)
		return (0);
	while (tmp[++i])
	{
		if (ft_strlen(*str) > SIZE_LINE)
			break ;
		*str = ft_realloc_imput(*str, tmp[i], *pos + i);
	}
	if (*pos)
	{
		--(*pos);
		ft_get_beggin_with_curs(*str, pos);
	}
	ft_current_str(*str, *pos);
	ft_get_next_str(*str, pos);
	ft_putnc('\b', *pos - tmp_pos);
	*pos = tmp_pos;
	return (0);
}

static void	reset_term(char **str, size_t *pos)
{
	size_t pos_ref;

	pos_ref = *pos;
	if (*pos)
	{
		--(*pos);
		ft_get_beggin_with_curs(*str, pos);
	}
	ft_puttermcaps("cd");
	ft_current_str(*str, *pos);
	ft_get_next_str(*str, pos);
	ft_putnc('\b', *pos - pos_ref);
	(*pos) = pos_ref;
}

static void	underline_right(char **str, size_t *pos, size_t pos_ref)
{
	if (!(*pos < ft_strlen(*str)))
		return ;
	if (*pos >= pos_ref)
	{
		ft_puttermcaps("mr");
		data_singleton()->line.copy_tmp = ft_realloc_imput(data_singleton()->line.copy_tmp, (*str)[*pos], data_singleton()->line.pos_tmp);
		ft_putchar((*str)[*pos]);
		ft_puttermcaps("me");
		++(data_singleton()->line.pos_tmp);
		++(*pos);
	}
	else
	{
		data_singleton()->line.copy_tmp = ft_remove_imput(data_singleton()->line.copy_tmp, data_singleton()->line.pos_tmp);
		ft_putchar((*str)[*pos]);
		if (data_singleton()->line.pos_tmp)
			--(data_singleton()->line.pos_tmp);
		++(*pos);
	}
}

static void	underline_left(char **str, size_t *pos, size_t pos_ref)
{
	if (!*pos)
		return ;
	if (*pos > pos_ref)
	{
		--(*pos);
		ft_putchar('\b');
		ft_putchar((*str)[*pos]);
		ft_putchar('\b');
		data_singleton()->line.copy_tmp = ft_remove_imput(data_singleton()->line.copy_tmp, data_singleton()->line.pos_tmp);
		if (data_singleton()->line.pos_tmp)
			--(data_singleton()->line.pos_tmp);
	}
	else
	{
		data_singleton()->line.pos_tmp = 0;
		--(*pos);
		ft_putchar('\b');
		ft_puttermcaps("mr");
		data_singleton()->line.copy_tmp = ft_realloc_imput(data_singleton()->line.copy_tmp, (*str)[*pos], data_singleton()->line.pos_tmp);
		ft_putchar((*str)[*pos]);
		ft_puttermcaps("me");
		ft_putchar('\b');
	}
}

static void	reset_and_remove_term(char **str, size_t *pos, char *copy_tmp)
{
	size_t pos_ref;

	pos_ref = *pos;
	if (!data_singleton()->line.pos_tmp)
		pos_ref += ft_strlen(data_singleton()->line.copy_tmp);
	while (*copy_tmp)
	{
		--pos_ref;
		*str = ft_remove_imput(*str, pos_ref);
		++copy_tmp;
	}
	if (*pos)
	{
		--(*pos);
		ft_get_beggin_with_curs(*str, pos);
	}
	ft_puttermcaps("cd");
	ft_current_str(*str, *pos);
	ft_get_next_str(*str, pos);
	ft_putnc('\b', *pos - pos_ref);
 	(*pos) = pos_ref;
}

int			ft_x(char **str, size_t *pos)
{
	int		ret;
	size_t	pos_ref;

	pos_ref = *pos;
	ft_strdel(&data_singleton()->line.copy_tmp);
	data_singleton()->line.pos_tmp = 0;
	if (!*str)
		return (0);
	while (42)
	{
		ret = 0;
		if (read(STDIN, &ret, sizeof(int)) < 0)
			return (-1);
		if ((*str)[*pos] == '\n')
			return (0);
		if (ret == FLECHE_GAUCHE)
			underline_left(str, pos, pos_ref);
		else if (ret == FLECHE_DROITE)
			underline_right(str, pos, pos_ref);
		else
			break ;
	}
	if (data_singleton()->line.copy_tmp && *data_singleton()->line.copy_tmp)
		reset_and_remove_term(str, pos, data_singleton()->line.copy_tmp);
	return (0);
}

int			ft_c(char **str, size_t *pos)
{
	int		ret;
	size_t	pos_ref;

	pos_ref = *pos;
	ft_strdel(&data_singleton()->line.copy_tmp);
	data_singleton()->line.pos_tmp = 0;
	if (!*str)
		return (0);
	while (42)
	{
		ret = 0;
		if (read(STDIN, &ret, sizeof(int)) < 0)
			return (-1);
		if ((*str)[*pos] == '\n')
			return (0);
		if (ret == FLECHE_GAUCHE)
			underline_left(str, pos, pos_ref);
		else if (ret == FLECHE_DROITE)
			underline_right(str, pos, pos_ref);
		else
			break ;
	}
	reset_term(str, pos);
	return (0);
}
