/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_line_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 19:07:52 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/17 12:17:07 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_clear_window(void)
{
	ft_puttermcaps("cl");
}

static void	ft_read_tmp(void)
{
	int		ret;

	while (42)
	{
		ret = 0;
		read(0, &ret, sizeof(int));
		if (ret == TOUCHE_F6)
		{
			ret = 0;
			if (read(0, &ret, sizeof(int)) && ret == 126)
				break ;
		}
	}
}

void		ft_change_affichage(void)
{
	ft_putstr("\033[31m");
	ft_puttermcaps("cd");
	ft_puttermcaps("sc");
	ft_putstr(data_singleton()->line.input);
	ft_read_tmp();
	ft_puttermcaps("rc");
	ft_puttermcaps("cd");
	ft_putstr("\033[37m");
}

int			ft_printall(char **str, size_t *pos)
{
	size_t	pos_tmp;
	int		ret;

	ret = 0;
	if (read(0, &ret, sizeof(int)) == -1 || ret != 126 || !*str)
		return (0);
	ft_clear_window();
	ft_prompt();
	pos_tmp = *pos;
	ft_change_affichage();
	if (*pos)
		--(*pos);
	ft_get_beggin(*str, pos);
	ft_current_str(*str, *pos);
	ft_get_next_str(*str, pos);
	if (*pos && !(*str)[*pos])
		--(*pos);
	if (*pos)
		ft_putnc('\b', *pos - pos_tmp + 1);
	*pos = pos_tmp;
	return (0);
}

void		ft_get_beggin_with_curs(char *str, size_t *pos)
{
	while ((*pos) && str[(*pos)] != '\n')
	{
		--(*pos);
		ft_puttermcaps("le");
	}
	if (!*pos && str[(*pos)] != '\n')
		ft_puttermcaps("le");
	if (str[(*pos)] == '\n')
		++(*pos);
}
