/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 18:54:00 by ariard            #+#    #+#             */
/*   Updated: 2017/03/23 17:16:43 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define MATHERR_0	"usage: math variable operator(add/sub/mul/div/mod) operand"
#define MATHERR_2	"math: %c: invalid operator"
#define MATHERR_3	"math: %s: operand must be digits only"
#define MATHERR_4	"math: division by 0"
#define MATHERR_5	"math: modulo by 0"

static char	*do_math(char *value, char operator, char *operand)
{
	long	ope1;
	long	ope2;

	ope1 = ft_atoi(value);
	ope2 = ft_atoi(operand);
	if ((operator == '/') && ope2 == 0)
		return (SH_ERR(MATHERR_4) ? NULL : NULL);
	if ((operator == '%') && ope2 == 0)
		return (SH_ERR(MATHERR_5) ? NULL : NULL);
	ope1 = (operator == '+') ? ope1 + ope2 : ope1;
	ope1 = (operator == '-') ? ope1 - ope2 : ope1;
	ope1 = (operator == '/') ? ope1 / ope2 : ope1;
	ope1 = (operator == '*') ? ope1 * ope2 : ope1;
	ope1 = (operator == '%') ? ope1 % ope2 : ope1;
	return (ft_itoa(ope1));
}

int			builtin_math(const char *path, char *const av[], char *const envp[])
{
	char		*value;
	char		operator;
	char		*operand;

	(void)path;
	(void)envp;
	if (!av || !av[0] || !av[1] || !av[2] || !av[3] || av[4])
		return (SH_ERR(MATHERR_0));
	value = ft_getenv(data_singleton()->local_var, av[1]);
	operator = av[2][0];
	if (!(ft_strchr("+-/*%", operator)))
		return (SH_ERR(MATHERR_2, operator));
	operand = av[3];
	if (!ft_stris(operand, &ft_isdigit))
		return (SH_ERR(MATHERR_3, operand));
	if (!(value = do_math(value, operator, operand)))
		return (1);
	builtin_setenv("setenv", (char *[]){"local", av[1], value, 0}, NULL);
	ft_strdel(&value);
	return (0);
}
