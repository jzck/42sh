/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_char_esc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 18:19:55 by wescande          #+#    #+#             */
/*   Updated: 2017/03/14 23:11:59 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				is_char_esc(const unsigned char *esc,
		const char *ini_str, const char *str_pos)
{
	int		pos;

	if (!esc || !ini_str || !str_pos)
		return (-1);
	pos = str_pos - ini_str;
	if (pos < 0)
		return (-1);
	if ((esc[pos >> 3] >> (7 - pos % 8)) & 1)
		return (1);
	return (0);
}

void			set_char_esc_mode(unsigned char *esc,
		const char *ini_str, const char *str_pos, int mode)
{
	int		pos;

	if (!esc || !ini_str || !str_pos || mode < 0 || mode > 1)
		return ;
	pos = str_pos - ini_str;
	esc[pos >> 3] |= mode << (7 - pos % 8);
}

void			set_char_esc(unsigned char *esc,
		const char *ini_str, const char *str_pos)
{
	int		pos;

	if (!esc || !ini_str || !str_pos)
		return ;
	pos = str_pos - ini_str;
	esc[pos >> 3] |= 1 << (7 - pos % 8);
}

void			set_char_no_esc(unsigned char *esc,
		const char *ini_str, const char *str_pos)
{
	int		pos;

	if (!esc || !ini_str || !str_pos)
		return ;
	pos = str_pos - ini_str;
	esc[pos >> 3] |= 0 << (7 - pos % 8);
}

unsigned char	*dup_char_esc(const unsigned char *esc, const int size)
{
	unsigned char	*new_esc;

	if (!(new_esc = (unsigned char *)ft_strnew(size)))
		return (NULL);
	new_esc = ft_memcpy(new_esc, esc, size);
	return (new_esc);
}
