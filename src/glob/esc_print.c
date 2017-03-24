/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esc_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:38:14 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/24 18:39:17 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		esc_print(int fd, char *str, unsigned char *esc)
{
	char *cur;

	cur = str;
	while (*cur)
	{
		if (is_char_esc(esc, str, cur))
			ft_dprintf(fd, "\\%c", *cur);
		else
			ft_dprintf(fd, "%c", *cur);
		++cur;
	}
	ft_dprintf(fd, "\n");
}
