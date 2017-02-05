/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_backslash.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 13:32:52 by gwojda            #+#    #+#             */
/*   Updated: 2017/02/05 12:40:21 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_prompt_type	g_prompt_tab[] =
{
	{IS_QUOTES		, SIZE_PROMPT_QUOTES	, PROMPT_QUOTES		},
	{IS_BQUOTES		, SIZE_PROMPT_BQUOTES	, PROMPT_BQUOTES	},
	{IS_DQUOTES		, SIZE_PROMPT_DQUOTES	, PROMPT_DQUOTES	},
	{IS_ACCOLADE	, SIZE_PROMPT_ACCOLADE	, PROMPT_ACCOLADE	},
	{IS_BRACKET		, SIZE_PROMPT_BRACKET	, PROMPT_BRACKET	},
	{IS_BSLASH		, SIZE_PROMPT_BSLASH	, PROMPT_BSLASH		},
	{0				, 0						, 0					},
};

t_brackets		g_brackets = {0	, {0}};

void		ft_read_more(short c)
{
	char	*str_tmp;
	char	*str_tmp2;
	int		i;

	i = 0;
	str_tmp2 = data_singleton()->line.input;
	str_tmp = ft_strjoin(str_tmp2, "\n");
	free(str_tmp2);
	STR = NULL;
	POS = 0;
	while (g_prompt_tab[i].key && !(g_prompt_tab[i].key & c))
		++i;
	data_singleton()->line.prompt_size = g_prompt_tab[i].value;
	ft_printf("\n%s", g_prompt_tab[i].new_prompt);
	str_tmp2 = ft_read_stdin();
	str_tmp2 = ft_strjoin(str_tmp, STR);
	free(str_tmp);
	free(STR);
	STR = str_tmp2;
	ft_check_line();
}

static void	ft_check_this_char_quotes(char c, short *status)
{
	int		i;
	char	*stats;

	i = 0;
	stats = "\'`\"\\";
	while (stats[i] && stats[i] != c)
		++i;
	if (!stats[i])
		return ;
	if ((1 << i) & ~(*status))
	{
		if (((1 << i) > *status && (*status == 0 && !(IS_QUOTES & *status)
		&& (!(IS_DQUOTES & *status))))
		|| (((1 << i) == IS_BQUOTES) && !(IS_QUOTES & *status)))
			(*status) = (*status) | (1 << i);
	}
	else
		(*status) = (*status) ^ (1 << i);
}

static int	ft_brackets(char c)
{
	if (c == '(')
	{
		g_brackets.tabl[g_brackets.pos] = '(';
		++g_brackets.pos;
	}
	else if (c == '{')
	{
		g_brackets.tabl[g_brackets.pos] = '{';
		++g_brackets.pos;
	}
	else if (c == '}')
	{
		if (!g_brackets.pos || g_brackets.tabl[g_brackets.pos - 1] != '{')
			return (1);
		g_brackets.tabl[--g_brackets.pos] = '\0';
	}
	else if (c == ')')
	{
		if (!g_brackets.pos || g_brackets.tabl[g_brackets.pos - 1] != '(')
			return (1);
		g_brackets.tabl[--g_brackets.pos] = '\0';
	}
	return (0);
}

void		ft_check_line(void)
{
	int		i;
	short	status;

	i = -1;
	status = 0;
	ft_reset_tab((char *)g_brackets.tabl);
	g_brackets.pos = 0;
	if (!STR)
		return ;
	while (STR[++i])
	{
		if (IS_BSLASH & status)
			status = status ^ IS_BSLASH;
		else
		{
			ft_check_this_char_quotes(STR[i], &status);
			if (!status && ft_brackets(STR[i]))
				return ;
		}
	}
	if (g_brackets.pos && g_brackets.tabl[0] == '(')
		status = status | IS_BRACKET;
	else if (g_brackets.pos && g_brackets.tabl[0] == '{')
		status = status | IS_ACCOLADE;
	(status) ? ft_read_more(status) : 0;
}
