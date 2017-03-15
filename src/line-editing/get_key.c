/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 16:28:49 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/15 14:07:20 by gwojda           ###   ########.fr       */
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

static void	ft_is_str(void)
{
	if (STR)
	{
		ft_current_str(STR, POS);
		ft_get_next_str(STR, &POS);
		if (STR[POS])
			++(POS);
	}
}

char		*ft_read_stdin(void)
{
	int	ret;
	int	j;

	ft_is_str();
	if (data_singleton()->comp)
		c_clear(data_singleton());
	signal(SIGWINCH, sigwinch_resize);
	while (42)
	{
		ret = 0;
		j = 0;
		read(0, &ret, sizeof(int));
		DG("key hexa value = %X", ret);
		if (ft_completion(ret))
			continue ;
		while (g_key[j].value && g_key[j].value != ret)
			++j;
		if (g_key[j].value)
			g_key[j].f();
		else if (ft_isprint(ret))
			ft_print(ret);
		else if (ret == 10)
			return (STR);
		else if (ft_isascii(ret) == 0)
			ft_read_it(ret, &POS, &STR);
	}
}
