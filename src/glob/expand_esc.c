/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_esc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 23:18:56 by wescande          #+#    #+#             */
/*   Updated: 2017/01/31 23:19:45 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob.h"

unsigned char				*calc_expand_esc(const unsigned char *esc,
							int nb_start, int nb_middle, int *nb_end)
{
	unsigned char	*new_esc;
	int				index;
	int				pos;

	if (!(new_esc = (unsigned char *)ft_strnew(((nb_start + nb_middle
							+ nb_end[1]) / 8) + 1)))
		return (NULL);
	index = -1;
	while (++index < nb_start)
		new_esc[index / 8] |=
			((esc[index / 8] >> (7 - index % 8)) & 1) << (7 - index % 8);
	pos = -1;
	while (++pos < nb_middle)
	{
		new_esc[index / 8] |= 0 << (7 - index % 8);
		++index;
	}
	pos = nb_end[0];
	while (++pos <= nb_end[0] + nb_end[1])
	{
		new_esc[index / 8] |=
			((esc[pos / 8] >> (7 - pos % 8)) & 1) << (7 - index % 8);
		++index;
	}
	return (new_esc);
}

void						modify_esc_split(unsigned char *esc_dest,
							unsigned char *esc_src, int start, int len)
{
	int		index;
	int		wk;

	index = -1;
	while (++index < len)
	{
		wk = index + start - 1;
		esc_dest[wk / 8] |=
			((esc_src[index / 8] >> (7 - index % 8)) & 1) << (7 - wk % 8);
	}
}

unsigned char				*ft_sub_esc(const unsigned char *esc,
										int start, int len)
{
	unsigned char	*new_esc;
	int				index;

	if (!(new_esc = (unsigned char *)ft_strnew(((len) / 8) + 1)))
		return (NULL);
	index = -1;
	while (++index < len)
	{
		new_esc[index / 8] |=
			((esc[start / 8] >> (7 - start % 8)) & 1) << (7 - index % 8);
		++start;
	}
	return (new_esc);
}
