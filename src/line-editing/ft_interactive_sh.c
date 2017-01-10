/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interactive_sh.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:14:12 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/10 12:31:35 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_stof g_keys[] = {
	{FT_KEY_C_K, NULL},
	{FT_KEY_TAB, &ft_key_default},
	{FT_KEY_C_H, &ft_line_start},
	{FT_KEY_C_L, &ft_line_end},
	{FT_KEY_C_U, &ft_clear_line},
	{FT_KEY_ESC, NULL},
	/* {FT_KEY_UP, &ft_history_up}, */
	/* {FT_KEY_DOWN, &ft_history_down}, */
	{FT_KEY_UP, NULL},
	{FT_KEY_DOWN, NULL},
	/* {FT_KEY_C_UP, &ft_line_up}, */
	/* {FT_KEY_C_DOWN, &ft_line_down}, */
	{FT_KEY_C_UP, NULL},
	{FT_KEY_C_DOWN, NULL},
	{FT_KEY_RIGHT, &ft_cursor_right},
	{FT_KEY_LEFT, &ft_cursor_left},
	{FT_KEY_C_RIGHT, &ft_word_right},
	{FT_KEY_C_LEFT, &ft_word_left},
	{FT_KEY_ENTER, &ft_key_enter},
	{FT_KEY_DEL, &ft_key_del},
	{FT_KEY_C_D, &ft_key_ctrl_d},
	{FT_KEY_C_C, &ft_key_ctrl_c},
	{FT_KEY_C_Z, NULL},
	{NULL, &ft_key_default},
};

int		ft_interactive_sh(t_data *data)
{
	char	buf[4];
	int		ret;
	int		i;

	if ((input_init(data)))
		return (-1);
	DG("interactive_sh loop");
	while (1)
	{
		ft_bzero(buf, 4);
		ret = read(0, buf, 4);
		i = 0;
		while (g_keys[i].name && ft_strcmp(buf, g_keys[i].name))
			i++;
		if (!g_keys[i].f)
			continue ;
		if ((ret = (*g_keys[i].f)(data, buf)) < 0)
			return (-1);
		else if (ret == 2)
		{
			data->mode = MODE_EXEC;
			ft_lstdel(&data->line.qstack, &ft_lst_cfree);
			ft_set_termios(data, 0);
			return (0);
		}
	}
}
