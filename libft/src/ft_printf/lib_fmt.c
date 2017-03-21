/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_fmt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:33:35 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/21 15:42:19 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_fmt	*ft_fmt_init(void)
{
	t_fmt	*fmt;

	fmt = (t_fmt *)ft_malloc(sizeof(t_fmt) + 1);
	ft_bzero(fmt->flags, 6);
	ft_bzero(fmt->modifier, 3);
	fmt->conversion = '\0';
	fmt->width = 0;
	fmt->precision = 0;
	fmt->valid = 0;
	return (fmt);
}

void	ft_fmt_print(t_fmt *fmt)
{
	ft_putendl("\n---");
	ft_putstr("valid: ");
	ft_putnbr(fmt->valid);
	ft_putendl("");
	ft_putstr("conv.: ");
	ft_putchar(fmt->conversion);
	ft_putendl("");
	ft_putstr("flags: ");
	ft_putendl(fmt->flags);
	ft_putstr("width: ");
	ft_putnbr(fmt->width);
	ft_putendl("");
	ft_putstr("prec.: ");
	ft_putnbr(fmt->precision);
	ft_putendl("");
	ft_putstr("modifier: ");
	ft_putendl(fmt->modifier);
	ft_putendl("---");
}
