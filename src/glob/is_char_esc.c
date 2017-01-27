/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_char_esc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 18:19:55 by wescande          #+#    #+#             */
/*   Updated: 2017/01/27 18:23:22 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob.h"

int		is_char_esc(const char *esc, const char *ini_str, const char *str_pos)
{
	int		pos;

	pos = str_pos - ini_str;
	if ((esc[pos / 8] >> pos % 8) & 1)
		return (1);
	return (0);
}
