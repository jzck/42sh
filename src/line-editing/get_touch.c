/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_touch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 16:28:49 by gwojda            #+#    #+#             */
/*   Updated: 2017/01/19 16:42:49 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_lecture_3(int ret, char **str, size_t *i)
{
	if (ret == 127 && (*i) > 0)
	{
		if ((*str)[*i - 1] != '\n')
			ft_suppr_1(str, i);
		else
			ft_suppr_2(str, i);
	}
	else if (ret == TOUCHE_DELETE && (*str) && (*i) < ft_strlen((*str)))
	{
		if ((*str)[*i] != '\n')
			ft_del_1(str, i);
		else
			ft_del_2(str, i);
	}
	else
		return (0);
	return (1);
}

static int		ft_lecture_2(int ret, char **str, size_t *i)
{
	if (ret == TOUCHE_OPT_LEFT || ret == TOUCHE_OPT_RIGHT)
		ft_move_to_word(ret, i, *str);
	else if (ret == TOUCHE_OPT_X || ret == TOUCHE_OPT_C
	|| ret == TOUCHE_OPT_V)
		ft_cxv(ret, i, str);
	else if (ret == FLECHE_DROITE || ret == FLECHE_GAUCHE)
		ft_move_term(ret, i, *str);
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
	i = 0;
	while (42)
	{
		ret = 0;
		read(0, &ret, sizeof(int));
//		if (ret == TOUCHE_TAB)
//			ret = ft_completion(&str, &i);
		if (ft_lecture_2(ret, &str, &i))
			continue ;
		else if (ret == FLECHE_BAS || ret == FLECHE_HAUT)
		{
			if (str)
				ft_putstr(str + i);
			ft_history(&str, ret, &head);
			if (str)
				i = ft_strlen(str);
			else
				i = 0;
		}
		else if (ret == TOUCHE_HOME || ret == TOUCHE_END)
			ft_home_end(str, ret, &i);
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
