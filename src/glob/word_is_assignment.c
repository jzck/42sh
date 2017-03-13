/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_is_assignment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 18:59:11 by wescande          #+#    #+#             */
/*   Updated: 2017/03/11 20:47:05 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				word_is_assignment(char **content)
{
	const int				len = ft_strlen(content[0]);
	int						pos;
	char					c;
	const unsigned char		*esc = (const unsigned char *)content[1];

	pos = -1;
	if (ft_isdigit(content[0][0]))
		return (0);
	while (++pos < len)
	{
		if (is_char_esc(esc, content[0], content[0] + pos))
			return (0);
		c = content[0][pos];
		if (!ft_isalnum(c) && c != '_')
			return (0);
	}
	return (1);
}
