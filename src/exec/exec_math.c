/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 10:58:49 by ariard            #+#    #+#             */
/*   Updated: 2017/03/07 13:33:49 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	get_math(char *stream, char **var, char **value, char **operator)
{
	char	*temp;

	*var = ft_strduptr(stream, &ft_isalpha);
	temp = ft_sstrstr(data_singleton()->env, *var);
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
	stream += ft_strlen(*var);
	*operator = ft_strdup(stream);
	return (0);
}

static int	do_math(char **value, char *operator)
{
	long	ope1;
	long	ope2;

	ope1 = ft_atoi(*value);
	if (operator[2])
		ope2 = ft_atoi(&operator[2]);
	else
		ope2 = 0;
	if (operator[0] == '/' && ope2 == 0)
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

int			exec_math(t_btree **ast)
{
	t_astnode	*node;
	char		**av;
	char		*var;
	char		*value;
	char		*operator;

	node = (*ast)->item;
	av = token_to_argv(node->data.cmd.wordlist, 1);
	get_math(av[0], &var, &value, &operator);
	do_math(&value, operator);
	builtin_setenv("setenv", (char *[]){var, value, 0}, data_singleton()->local_var);
	return (0);
}
