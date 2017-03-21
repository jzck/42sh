/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 18:54:00 by ariard            #+#    #+#             */
/*   Updated: 2017/03/20 23:21:16 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define MATHERR_0	"math : invalid number of arguments\n"
#define MATHERR_1	"math : invalid variable name\n"
#define MATHERR_2	"math : invalid operator\n"
#define MATHERR_3	"math : invalid operand\n"
#define MATHERR_4	"math : division by 0\n"

static int	init_math(char **var, char **value, char **operator,
		char **operand)
{
	*var = NULL;
	*value = NULL;
	*operator = NULL;
	*operand = NULL;
	return (0);
}

static int	get_value(char *var, char **value)
{
	char	*temp;
	char	*esc;
	int		ret;

	esc = ft_strnew((ft_strlen(var) >> 3) + 1);
	ret = word_is_assignment((char *[]) {var, (esc + 1)});
	ft_strdel(&esc);
	if (!ret)
		return (error_msg(MATHERR_1));
	temp = ft_sstrstr(data_singleton()->local_var, var);
	if (temp)
	{
		temp += ft_strlenchr(temp, '=') + 1;
		*value = ft_strdup(temp);
		if (!(ft_stris(*value, &ft_isdigit)))
		{
			ft_strdel(value);
			*value = ft_itoa(0);
		}
	}
	else
		*value = ft_itoa(0);
	return (0);
}

static int	do_math(char **value, char *operator, char *operand)
{
	long	ope1;
	long	ope2;

	ope1 = ft_atoi(*value);
	if (operand)
		ope2 = ft_atoi(operand);
	else
		ope2 = 0;
	if ((operator[0] == '/' || operator[0] == '%') && ope2 == 0)
		return (error_msg(MATHERR_4));
	else
	{
		ope1 = (operator[0] == '+') ? ope1 + ope2 : ope1;
		ope1 = (operator[0] == '-') ? ope1 - ope2 : ope1;
		ope1 = (operator[0] == '/') ? ope1 / ope2 : ope1;
		ope1 = (operator[0] == '*') ? ope1 * ope2 : ope1;
		ope1 = (operator[0] == '%') ? ope1 % ope2 : ope1;
	}
	ft_strdel(value);
	*value = ft_itoa(ope1);
	return (0);
}

int			builtin_math(const char *path, char *const av[], char *const envp[])
{
	char		*var;
	char		*value;
	char		*operator;
	char		*operand;

	(void)path;
	(void)envp;
	if (!av || !av[1] || !av[2] || !av[3] || av[4])
		return (builtin_return_status(0, error_msg(MATHERR_0)));
	init_math(&var, &value, &operator, &operand);
	var = av[1];
	if (get_value(var, &value))
		return (builtin_return_status(0, 1));
	operator = av[2];
	if (ft_strlen(operator) != 1 || !(ft_strchr("+-/*%", operator[0])))
		return (builtin_return_status(0, error_msg(MATHERR_2)));
	operand = av[3];
	if (!ft_stris(operand, &ft_isdigit))
		return (builtin_return_status(0, error_msg(MATHERR_3)));
	if (do_math(&value, operator, operand))
		return (builtin_return_status(0, 1));
	builtin_setenv("setenv", (char *[]){"local", var, value, 0}, NULL);
	return (builtin_return_status(0, 0));
}
