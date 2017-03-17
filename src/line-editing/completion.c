/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 14:15:55 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/17 10:45:06 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	ft_strleni_w(char *str, size_t pos, char c)
{
	size_t	len;

	len = 0;
	if (!STR)
		return (0);
	while (str[pos] && str[pos] != c)
	{
		++len;
		++pos;
	}
	return (len);
}

int				ft_completion(int ret)
{
	size_t	tmp;
	size_t	pos_tmp;
	size_t	right;
	char	boolean;

	boolean = 0;
	pos_tmp = POS;
	right = ft_strleni_w(STR, POS, '\n');
	if (((ret != TOUCHE_TAB && ret != 10)
	|| (ret == 10)) && !(data_singleton()->comp))
		return (0);
	if (data_singleton()->comp || ret == TOUCHE_TAB)
		boolean = completion(ret);
	if (boolean || ret == 10)
	{
		(pos_tmp) ? --pos_tmp : ft_puttermcaps("nd");
		ft_get_beggin_with_curs(STR, &pos_tmp);
		tmp = pos_tmp;
		ft_puttermcaps("cd");
		ft_current_str(STR, tmp);
		ft_get_next_str(STR, &tmp);
		ft_putnc('\b', right);
		POS = ft_strleni_w(STR, pos_tmp, '\n') - right;
	}
	return (0);
}
