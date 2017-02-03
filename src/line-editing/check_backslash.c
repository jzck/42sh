/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_backslash.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 13:32:52 by gwojda            #+#    #+#             */
/*   Updated: 2017/02/03 14:09:20 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_prompt_type	g_prompt_tab[] =
{
	{IS_QUOTES		,SIZE_PROMPT_QUOTES		,PROMPT_QUOTES},
	{IS_BQUOTES		,SIZE_PROMPT_BQUOTES	,PROMPT_BQUOTES},
	{IS_DQUOTES		,SIZE_PROMPT_DQUOTES	,PROMPT_DQUOTES},
	{IS_ACCOLADE	,SIZE_PROMPT_ACCOLADE	,PROMPT_ACCOLADE},
	{IS_BRACKET		,SIZE_PROMPT_BRACKET	,PROMPT_BRACKET},
	{IS_BSLASH		,SIZE_PROMPT_BSLASH		,PROMPT_BSLASH},
	{0				,0						,0},
};

void	ft_read_more(short c)
{
	char	*str_tmp;
	char	*str_tmp2;
	int		i;

	i = 0;
	str_tmp2 = data_singleton()->line.input;
	str_tmp = ft_strjoin(str_tmp2, "\n");
	free(str_tmp2);
	data_singleton()->line.input = NULL;
	data_singleton()->line.pos = 0;
	while (g_prompt_tab[i].key && !(g_prompt_tab[i].key & c))
		++i;
	data_singleton()->line.prompt_size = g_prompt_tab[i].value;
	ft_printf("\n%s", g_prompt_tab[i].new_prompt);
	str_tmp2 = ft_read_stdin();
	str_tmp2 = ft_strjoin(str_tmp, data_singleton()->line.input);
	free(str_tmp);
	free(data_singleton()->line.input);
	data_singleton()->line.input = str_tmp2;
	ft_check_line();
}

void	ft_check_this_char(char c, short *status)
{
	int		i;
	char	stats[] = {'\'', '`', '\"', '{', '(', '\\', '\0'};

	i = 0;
	while (stats[i] && stats[i] != c)
		++i;
	if (!stats[i])
		return ;
	if (((1 << i) & ~(*status)))
	{
		if (((1 << i) > *status &&
		(*status == 0 && !(IS_QUOTES & *status) && (!(IS_DQUOTES & *status))))
		|| (((1 << i) == IS_BQUOTES) && !(IS_QUOTES & *status)))
			(*status) = (*status) | (1 << i);
	}
	else
		(*status) = (*status) ^ (1 << i);
}

void	ft_check_line(void)
{
	int		i;
	char	*str;
	short	status;

	i = 0;
	status = 0;
	str = data_singleton()->line.input;
	while (str[i])
	{
		if (IS_BSLASH & status)
			status = status ^ IS_BSLASH;
		else
			ft_check_this_char(str[i], &status);
		++i;
	}
	if (status)
		ft_read_more(status);
}
