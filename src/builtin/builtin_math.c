/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 10:58:49 by ariard            #+#    #+#             */
/*   Updated: 2017/03/14 22:45:23 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	init_math(char **var, char **value, char **operator, char **operand)
{
	*var = NULL;
	*value = NULL;
	*operator = NULL;
	*operand = NULL;
	return (0);
}

static int	get_value(char **var, char **value)
{
	char	*temp;

	temp = ft_sstrstr(data_singleton()->local_var, *var);
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
	if (ft_strlen(operator) > 1)
		return (0);
	if ((operator[0] == '/' || operator[0] == '%') && ope2 == 0)
		ope1 = 0;
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
	init_math(&var, &value, &operator, &operand);
	var = av[1];
	get_value(&var, &value);
	operator = av[2];
	operand = av[3];	
//	DG("math %s %s %s", var, operator, operand);
	do_math(&value, operator, operand);
	builtin_setenv("setenv", (char *[]){"local", var, value, 0}, data_singleton()->local_var);
	return (0);
}
