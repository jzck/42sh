/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 18:03:48 by sbenning          #+#    #+#             */
/*   Updated: 2016/12/10 11:50:51 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static t_input			g_input[] = {\
	{RL_NL_CODE,				rl_nl_function},\
	{RL_INSERT_CODE,			rl_insert_function},\
	{RL_CLEAR_CODE,				rl_clear_function},\
	{RL_RETARR_CODE,			rl_retarr_function},\
	{RL_SUPPR_CODE,				rl_suppr_function},\
	{RL_ESC_CODE,				rl_esc_function},\
	{RL_QUOTE_CODE,				rl_quote_function},\
	{RL_DQUOTE_CODE,			rl_dquote_function},\
	{RL_LEFT_CODE,				rl_left_function},\
	{RL_SELECT_LEFT_CODE,		rl_select_left_function},\
	{RL_RIGHT_CODE,				rl_right_function},\
	{RL_SELECT_RIGHT_CODE,		rl_select_right_function},\
	{RL_WLEFT_CODE,				rl_wleft_function},\
	{RL_SELECT_WLEFT_CODE,		rl_select_wleft_function},\
	{RL_WRIGHT_CODE,			rl_wright_function},\
	{RL_SELECT_WRIGHT_CODE,		rl_select_wright_function},\
	{RL_HOME_CODE,				rl_home_function},\
	{RL_SELECT_HOME_CODE,		rl_select_home_function},\
	{RL_END_CODE,				rl_end_function},\
	{RL_SELECT_END_CODE,		rl_select_end_function},\
	{RL_PAGEUP_CODE,			rl_pageup_function},\
	{RL_SELECT_PAGEUP_CODE,		rl_select_pageup_function},\
	{RL_PAGEDOWN_CODE,			rl_pagedown_function},\
	{RL_SELECT_PAGEDOWN_CODE,	rl_select_pagedown_function},\
	{RL_COPY_CODE,				rl_copy_function},\
	{RL_CUT_CODE,				rl_cut_function},\
	{RL_PASTE_CODE,				rl_paste_function},\
	{0x0,						rl_default_function}\
};

static void				rl_toogle_bitset(t_line *line, int set)
{
	static int			esc;
	static int			select;

	if (!set)
	{
		esc = RL_IS(line->bitset, RL_ESC);
		select = RL_IS(line->bitset, RL_SELECT);
	}
	else
	{
		if (esc)
		{
			RL_UNSET(line->bitset, RL_ESC);
			esc = 0;
		}
		if ((select && RL_NOT(line->bitset, RL_SELECT)) || (!select && RL_IS(line->bitset, RL_SELECT)))
		{
			rl_reset_display(line);
		}
	}
}

static int				rl_finish(t_line *line)
{
	if (RL_IS(line->bitset, RL_STACK))
	{
		rl_end_function(line, 0);
		write(1, "\n", 1);
		if (rl_stack_line(line) < 0)
			return (-1);
		if (RL_NOT(line->bitset, RL_FINISH))
		{
			if (curs_coo_setup(&line->curs) < 0)
				return (-1);
			line->prompt = (RL_IS(line->bitset, RL_ESC) ? "> " : "quote> ");
			rl_put_prompt(line);
		}
		RL_UNSET(line->bitset, RL_STACK);
	}
	return (RL_IS(line->bitset, RL_FINISH));
}

static t_input_function	rl_get_function(long int input)
{
	int					i;

	i = -1;
	while (g_input[++i].code)
	{
		if (input == g_input[i].code)
			break ;
	}
	return (g_input[i].function);
}

static long int			rl_read(void)
{
	long int			input;

	ft_bzero(&input, sizeof(long int));
	if (read(0, &input, sizeof(long int)) < 0)
		return (0);
	return (input);
}

static int				rl_loop(t_line *line)
{
	long int			input;
	int					ret;

	rl_put_prompt(line);
	while (42)
	{
		input = rl_read();
		if (input == 0)
			continue ;
		rl_toogle_bitset(line, 0);
		if (rl_get_function(input)(line, input) < 0)
			return (-1);
		if ((ret = rl_finish(line)))
			break ;
		rl_toogle_bitset(line, 1);
	}
	return ((ret < 0 ? -1 : 0));
}

int							ft_readline(t_line *line)
{
	if (rl_setup(line) < 0)
		return (-1);
	if (rl_loop(line) < 0)
	{
		rl_teardown(line);
		return (-1);
	}
	if (rl_cleanup(line) < 0)
		return (-1);
	return (0);
}
