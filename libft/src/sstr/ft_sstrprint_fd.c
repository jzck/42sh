/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstrprint_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:17:29 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/18 03:37:16 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sstrprint_fd(int fd, char **list, char sep)
{
	int		i;

	i = 0;
	if (!list || !*list)
		return ;
	while (list[i])
	{
		ft_putstr_fd(list[i++], fd);
		if (list[i])
			ft_putchar_fd(sep, fd);
	}
}
