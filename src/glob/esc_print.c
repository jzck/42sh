/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esc_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:38:14 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/24 22:05:04 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob.h"

void		esc_print(char *str, unsigned char *esc)
{
	char *cur;

	cur = str;
	while (*cur)
	{
		if (is_char_esc(esc, str, cur))
			printf("\\%c", *cur);
		else
			printf("%c", *cur);
		++cur;
	}
	printf("\n");
}
