/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:21:41 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/13 17:58:14 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int		builtin_echo(const char *path, char *const av[], char *const envp[])
{
	(void)envp;
	(void)path;
	av++;
	while (*av)
	{
		ft_printf("%s", *av);
		av++;
		if (*av)
			ft_putchar(' ');
	}
	ft_putchar('\n');
	return (0);
}
