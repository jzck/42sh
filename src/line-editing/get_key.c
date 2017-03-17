/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 16:28:49 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/17 15:11:10 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_key	g_key[] =
{
	{FLECHE_HAUT		, &ft_history_up		},
	{FLECHE_BAS			, &ft_history_down		},
	{FLECHE_GAUCHE		, &ft_move_left			},
	{FLECHE_DROITE		, &ft_move_right		},
	{TOUCHE_DELETE		, &ft_del				},
	{TOUCHE_CTRL_L		, &ft_control_l			},
	{TOUCHE_CTRL_C		, &ft_control_c			},
	{TOUCHE_CTRL_D		, &ft_control_d			},
	{TOUCHE_CTRL_R		, &ft_surch_in_history	},
	{TOUCHE_SUPPR		, &ft_suppr				},
	{TOUCHE_HOME		, &ft_home				},
	{TOUCHE_END			, &ft_end				},
	{TOUCHE_OPT_UP		, &ft_up				},
	{TOUCHE_OPT_DOWN	, &ft_down				},
	{TOUCHE_OPT_LEFT	, &ft_found_prev_word	},
	{TOUCHE_OPT_RIGHT	, &ft_found_next_word	},
	{TOUCHE_OPT_C		, &ft_c					},
	{TOUCHE_OPT_V		, &ft_v					},
	{TOUCHE_OPT_X		, &ft_x					},
	{TOUCHE_F5			, &ft_printall			},
	{TOUCHE_F6			, &ft_buff_f6			},
	{0					, 0						},
};

static void	init_read_stdin(char ***str, size_t **pos)
{
	*pos = &data_singleton()->line.pos;
	*str = &data_singleton()->line.input;
	if (**str)
	{
		ft_current_str(**str, **pos);
		ft_get_next_str(**str, *pos);
		if ((**str)[**pos])
			++(**pos);
	}
	if (data_singleton()->comp)
		c_clear(data_singleton());
	signal(SIGWINCH, sigwinch_resize);
}

static int	read_stdin(int *ret, int *j)
{
	*j = 0;
	*ret = 0;
	if (read(0, ret, sizeof(int)) < 0)
		return (-1);
	return (1);
}

static int	press_enter(char **input, char **str)
{
	*input = *str;
	return (0);
}

int			ft_read_stdin(char **input)
{
	int		ret;
	int		j;
	char	**str;
	size_t	*pos;

	init_read_stdin(&str, &pos);
	while (42)
	{
		if (read_stdin(&ret, &j) < 0)
			return (-1);
		if (ft_completion(ret, str, pos))
			continue ;
		while (g_key[j].value && g_key[j].value != ret)
			++j;
		if (g_key[j].value && (ret = g_key[j].f(str, pos)))
			return (ret);
		else if (!g_key[j].value && ft_isprint(ret))
			ft_print(ret, str, pos);
		else if (!g_key[j].value && ret == 10)
			return (press_enter(input, str));
		else if (!g_key[j].value && ft_isascii(ret) == 0)
			ft_read_it(ret, pos, str);
	}
}
