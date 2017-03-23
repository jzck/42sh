/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_cut_paste.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 12:45:06 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/23 16:28:01 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cpy			g_cpy[] =
{
	{FLECHE_GAUCHE	, &underline_left	},
	{FLECHE_DROITE	, &underline_right	},
	{FLECHE_HAUT	, &underline_up		},
	{FLECHE_BAS		, &underline_down	},
	{TOUCHE_HOME	, &underline_home	},
	{TOUCHE_END		, &underline_end	},
	{0				, 0					},
};

int			ft_x(char **str, size_t *pos)
{
	size_t	pos_ref;
	int		ret;
	int		i;

	pos_ref = *pos;
	ft_strdel(&data_singleton()->line.copy_tmp);
	data_singleton()->line.pos_tmp = 0;
	if (!*str)
		return (0);
	while (42)
	{
		ret = 0;
		i = 0;
		if (read(STDIN, &ret, sizeof(int)) < 0)
			return (-1);
		while (g_cpy[i].value && g_cpy[i].value != ret)
			++i;
		if (g_cpy[i].value && (ret = g_cpy[i].f(str, pos, pos_ref)))
			return (ret);
		else
			break ;
	}
	if (data_singleton()->line.copy_tmp && *data_singleton()->line.copy_tmp)
		reset_and_remove_term(str, pos, data_singleton()->line.copy_tmp);
	return (0);
}

int			ft_c(char **str, size_t *pos)
{
	size_t	pos_ref;
	int		ret;
	int		i;

	pos_ref = *pos;
	ft_strdel(&data_singleton()->line.copy_tmp);
	data_singleton()->line.pos_tmp = 0;
	if (!*str)
		return (0);
	while (42)
	{
		ret = 0;
		i = 0;
		if (read(STDIN, &ret, sizeof(int)) < 0)
			return (-1);
		while (g_cpy[i].value && g_cpy[i].value != ret)
			++i;
		if (g_cpy[i].value && (ret = g_cpy[i].f(str, pos, pos_ref)))
			return (ret);
		else if (!g_cpy[i].value)
			break ;
	}
	reset_term(str, pos);
	return (0);
}

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
