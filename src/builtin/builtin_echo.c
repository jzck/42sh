/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:21:41 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/28 14:22:02 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		builtin_echo(char **av, t_data *data)
{
	(void)data;
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
