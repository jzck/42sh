/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_fmt_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:33:38 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/07 17:22:41 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fmt_error_conv(char conv)
{
	ft_putstr("Warning: invalid or unsupported conversion specifier '");
	ft_putchar(conv);
	ft_putendl("'");
}

void	ft_fmt_error_mod_conv(char *mod, char conv)
{
	ft_putstr("warning: length modifier '");
	ft_putstr(mod);
	ft_putstr("' results in undefined behaviour or no effect with '");
	ft_putchar(conv);
	ft_putendl("' conversion specifier");
}

void	ft_fmt_error_flag_conv(char flag, char conv)
{
	ft_putstr("warning: flag '");
	ft_putchar(flag);
	ft_putstr("' results in undefined behaviour with '");
	ft_putchar(conv);
	ft_putendl("' conversion specifier");
}

void	ft_fmt_error_flag_flag(char flag1, char flag2)
{
	ft_putstr("warning: flag '");
	ft_putchar(flag1);
	ft_putstr("' is ignored when flag '");
	ft_putchar(flag2);
	ft_putendl("' is present");
}
