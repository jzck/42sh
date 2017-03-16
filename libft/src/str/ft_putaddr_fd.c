/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 18:47:04 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/18 18:48:58 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putaddr_fd(void *a, int fd)
{
	char				out[19];
	unsigned long long	addr;
	int					i;

	ft_putnbr((long)a);
	ft_putchar('\n');
	addr = (unsigned long long)a;
	out[18] = 0;
	i = 17;
	while (addr)
	{
		ft_putnbr(addr);
		ft_putchar('\n');
		out[i--] = "0123456789ABCDEF"[addr % 16];
		addr /= 16;
	}
	out[i--] = 'x';
	out[i] = '0';
	ft_putstr_fd(out + i, fd);
}
