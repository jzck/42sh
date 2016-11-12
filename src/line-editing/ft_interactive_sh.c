/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interactive_sh.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:44:21 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/11 14:39:10 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

t_stof g_keys[] = {
	{FT_KEY_C_K,		NULL},
	{FT_KEY_TAB,		NULL},
	{FT_KEY_C_H,		&ft_line_start},
	{FT_KEY_C_L,		&ft_line_end},
	{FT_KEY_C_U,		&ft_clear_line},
	{FT_KEY_ESC,		NULL},

	/* {FT_KEY_UP,			&ft_history_up}, */
	/* {FT_KEY_DOWN,		&ft_history_down}, */
	{FT_KEY_UP,			NULL},
	{FT_KEY_DOWN,		NULL},
	/* {FT_KEY_C_UP,		&ft_line_up}, */
	/* {FT_KEY_C_DOWN,		&ft_line_down}, */
	{FT_KEY_C_UP,		NULL},
	{FT_KEY_C_DOWN,		NULL},

	{FT_KEY_RIGHT,		&ft_cursor_right},
	{FT_KEY_LEFT,		&ft_cursor_left},
	{FT_KEY_C_RIGHT,	&ft_word_right},
	{FT_KEY_C_LEFT,		&ft_word_left},

	{FT_KEY_ENTER,		&ft_key_enter},
	{FT_KEY_DEL,		&ft_key_del},
	{FT_KEY_C_D,		&ft_key_ctrl_d},
	{FT_KEY_C_C,		&ft_key_ctrl_c},
	{FT_KEY_C_Z,		NULL},
	{NULL,				&ft_key_basic},
};

int		ft_interactive_sh(t_data *data)
{
	char	buf[20];
	t_dlist	*input_chain;
	char	null;
	int		ret;
	int		i;

	null = '\0';
	if (!data->history)
		data->history = ft_dlstnew(NULL, 0);
	input_chain = ft_dlstnew(&null, sizeof(char));
	ft_set_termios(data, 1);
	ft_prompt();
	while (1)
	{
		ft_bzero(buf, 20);
		ret = read(0, buf, 20);
		/* ft_printf("read=%i: %#x,%#x,%#x\n", ret, buf[0], buf[1], buf[2]); */
		/* continue ; */
		i = 0;
		while (g_keys[i].name && ft_strcmp(buf, g_keys[i].name))
			i++;
		if (!g_keys[i].f)
			continue ;
		ret = (*g_keys[i].f)(data, &input_chain, buf);
		if (ret < 0)
			return (-1);
		else if (ret == 2)
		{
			ft_set_termios(data, 0);
			return (0);
		}
	}
}
