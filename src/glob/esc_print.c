/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esc_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:38:14 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/15 18:12:49 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		esc_print(char *str, unsigned char *esc)
{
	char *cur;

	cur = str;
	while (*cur)
	{
		if (is_char_esc(esc, str, cur))
			ft_printf("\\%c", *cur);
		else
			ft_printf("%c", *cur);
		++cur;
	}
	ft_printf("\n");
}
