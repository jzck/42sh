/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 21:25:03 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/18 17:47:04 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_loop(long n, int base, int fd)
{
	if (n >= base)
		ft_putnbr_loop(n / base, base, fd);
	ft_putchar_fd("0123456789abcdef"[n % base], fd);
}

void	ft_putnbr_hex_fd(long n, int fd)
{
	ft_putstr_fd("0x", fd);
	ft_putnbr_loop(n, 16, fd);
}

void	ft_putnbr_fd(long n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	n = FT_ABS(n);
	ft_putnbr_loop(n, 10, fd);
}

void	ft_putnbr_hex(long n)
{
	ft_putnbr_hex_fd(n, 1);
}

void	ft_putnbr(long n)
{
	ft_putnbr_fd(n, 1);
}
