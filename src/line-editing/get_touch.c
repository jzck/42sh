/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_touch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 16:28:49 by gwojda            #+#    #+#             */
/*   Updated: 2017/02/01 16:50:57 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_lecture_3(int ret, char **str, size_t *i)
{
	if (ret == 127 && (*i) > 0)
		ft_suppr(str, i);
	else if (ret == TOUCHE_DELETE && (*str) && (*i) < ft_strlen((*str)))
		ft_del(str, i);
	else if (ret == TOUCHE_HOME && *str)
		ft_home(*str, i);
	else if (ret == TOUCHE_END && *str)
		ft_end(*str, i);
	else
		return (0);
	return (1);
}

static int		ft_lecture_2(int ret, char **str, size_t *i)
{
	if (ret == TOUCHE_F5)
		ft_printall(*str, i);
	else if (ret == TOUCHE_OPT_LEFT || ret == TOUCHE_OPT_RIGHT)
		ft_move_to_word(ret, i, *str);
	else if (ret == TOUCHE_OPT_X || ret == TOUCHE_OPT_C
	|| ret == TOUCHE_OPT_V)
		ft_cxv(ret, i, str);
	else if (ret == FLECHE_DROITE)
		ft_move_right(i, *str);
	else if (ret == FLECHE_GAUCHE)
		ft_move_left(i, *str);
	else if (ret == TOUCHE_OPT_UP || ret == TOUCHE_OPT_DOWN)
		ft_move_to_line(ret, i, *str);
	else if (ft_isprint(ret))
		ft_print(str, ret, i);
	else
		return (0);
	return (1);
}

char			*ft_lecture(t_list_history *head)
{
	char		*str;
	int			ret;
	size_t		i;

	str = NULL;
	if (data_singleton()->line.opt & HIST)
		str = data_singleton()->line.input;
	i = 0;
	if (str)
	{
		ft_current_str(str, i);
		ft_get_next_str(str, &i);
		if (str[i])
			++i;
	}
	while (42)
	{
		ret = 0;
		read(0, &ret, sizeof(int));
		if (ret == TOUCHE_F6 && read(0, &ret, sizeof(int)) > 0)
			continue ;
		if (ret == TOUCHE_CTRL_R)
		{
			ft_surch_in_history(&str, &i);
			continue ;
		}
/*
**		if (ret == TOUCHE_TAB)
**			ret = ft_completion(&str, &i);
*/
		if (ret == TOUCHE_CTRL_D)
		{
			if (!str || str[0] == '\0')
				exit(0);
			else if (i < ft_strlen(str))
				ft_del(&str, &i);
			else
				ft_puttermcaps("bl");
		}
		if (ret == TOUCHE_CTRL_C)
		{
			ft_putchar('\n');
			ft_prompt();
			ft_strdel(&str);
			i = 0;
		}
		if (ft_lecture_2(ret, &str, &i))
			continue ;
		else if (ret == FLECHE_BAS || ret == FLECHE_HAUT)
		{
			if (!head)
				continue ;
			ft_history(&str, ret, &head, &i);
			if (str)
				i = ft_strlen_next(str, i);
			else
				i = 0;
		}
		else if (ft_lecture_3(ret, &str, &i))
			continue ;
		else if (ret == 10)
			break ;
		else if (ft_isascii(ret) == 0)
			ft_read_it(ret, &i, &str);
	}
	if (str)
		ft_putstr(str + i);
	return (str);
}
