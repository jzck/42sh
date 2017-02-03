/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surch_in_history.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 10:43:16 by gwojda            #+#    #+#             */
/*   Updated: 2017/02/02 15:16:42 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_clear_prompt(char *str, size_t *pos, size_t srch_pos)
{
	if (str)
		ft_get_beggin_with_curs(str, pos);
	else if (*pos)
	{
		ft_putnc('\b', *pos);
		(*pos) = 0;
	}
	ft_putnc('\b', data_singleton()->line.prompt_size + srch_pos + 1);
	ft_puttermcaps("cd");
}

void	ft_surch_and_realloc(char **str, char **str_srch, int ret, size_t *srch_pos)
{
	*str_srch = ft_realloc_imput(*str_srch, ret, *srch_pos);
	++(*srch_pos);
	*str = ft_strget_history(*str_srch);
}

void	ft_surch_in_history(void)
{
	char	*str_srch;
	int		ret;
	size_t	srch_pos;
	char	**str;
	size_t	*pos;

	str = &data_singleton()->line.input;
	pos = &data_singleton()->line.pos;
	srch_pos = 0;
	str_srch = NULL;
	if (*str)
		ft_strdel(str);
	while (42)
	{
		ft_clear_prompt(*str, pos, srch_pos);
		data_singleton()->line.prompt_size = 21;
		if (str_srch)
			ft_printf("\033[35m(reverse-i-search)`\033[32m%s\033[35m': \033[37m", str_srch);
		else
			ft_putstr("\033[35m(reverse-i-search)`': \033[37m");
		if (*str)
		{
			ft_current_str(*str, *pos);
			ft_get_next_str(*str, pos);
		}
		ret = 0;
		read(0, &ret, sizeof(int));
		if (ft_isprint(ret))
			ft_surch_and_realloc(str, &str_srch, ret, &srch_pos);
		else if (ret == 127)
		{
			if (srch_pos)
			{
				--srch_pos;
				str_srch = ft_remove_imput(str_srch, srch_pos);
				ft_puttermcaps("le");
			}
		}
		else
			break ;
	}
	ft_clear_prompt(*str, pos, srch_pos);
	ft_prompt();
	if (*str)
	{
		*str = ft_strdup(*str);
		ft_current_str(*str, *pos);
		ft_get_next_str(*str, pos);
	}
	free(str_srch);
}
