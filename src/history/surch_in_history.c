/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surch_in_history.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 10:43:16 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/17 16:06:09 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_clear_prompt(size_t *pos, size_t srch_pos)
{
	if (*pos)
	{
		ft_putnc('\b', *pos);
		(*pos) = 0;
	}
	ft_putnc('\b', data_singleton()->line.prompt_size + srch_pos + 1);
	ft_puttermcaps("cd");
}

static int	ft_surch_and_realloc(char **str, char **str_srch,
			int ret, size_t *srch_pos)
{
	if (!(*str_srch = ft_realloc_imput(*str_srch, ret, *srch_pos)))
		return (-1);
	++(*srch_pos);
	*str = ft_strget_history(*str_srch);
	return (1);
}

static void	ft_give_new_prompt(char *str_srch, size_t srch_pos)
{
	ft_clear_prompt(&data_singleton()->line.pos, srch_pos);
	data_singleton()->line.prompt_size = 21;
	if (str_srch)
		ft_printf("\033[35m(reverse-i-search)`\033[32m%s\033[35m': \033[37m",
		str_srch);
	else
		ft_putstr("\033[35m(reverse-i-search)`': \033[37m");
	if (data_singleton()->line.input)
	{
		ft_current_str(data_singleton()->line.input,
												data_singleton()->line.pos);
		ft_get_next_str(data_singleton()->line.input,
												&data_singleton()->line.pos);
	}
}

static void	ft_modify_str(char *str_srch, size_t srch_pos, char **str,
			size_t *pos)
{
	ft_clear_prompt(pos, srch_pos);
	data_singleton()->line.is_prompt ? ft_prompt() : ft_putstr("> ");
	if (*str)
	{
		*str = ft_strdup(*str);
		ft_current_str(*str, *pos);
		ft_get_next_str(*str, pos);
	}
	free(str_srch);
}

int			ft_surch_in_history(char **str, size_t *pos)
{
	char	*str_srch;
	int		ret;
	size_t	srch_pos;

	srch_pos = 0;
	str_srch = NULL;
	(*str) ? ft_strdel(str) : 0;
	while (42)
	{
		ft_give_new_prompt(str_srch, srch_pos);
		ret = 0;
		read(0, &ret, sizeof(int));
		if (ft_isprint(ret))
		{
			if (ft_surch_and_realloc(str, &str_srch, ret, &srch_pos) < 0)
				return (-1);
		}
		else if (ret == 127 && srch_pos)
		{
			--srch_pos;
			str_srch = ft_remove_imput(str_srch, srch_pos);
			ft_puttermcaps("le");
			*str = (!*str_srch) ? NULL : ft_strget_history(str_srch);
		}
		else if (ret != 127)
			break ;
	}
	ft_modify_str(str_srch, srch_pos, str, pos);
	return (0);
}
