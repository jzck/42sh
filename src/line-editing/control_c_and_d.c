/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_c_and_d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:17:28 by gwojda            #+#    #+#             */
/*   Updated: 2017/02/03 18:27:23 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_buff_f6(void)
{
	int ret;

	ret = 0;
	read(0, &ret, sizeof(int));
}

void	ft_control_d(void)
{
	char	**str;
	size_t	*pos;

	str = &data_singleton()->line.input;
	pos = &data_singleton()->line.pos;
	if (!(*str) || (*str)[0] == '\0')
	{
		ft_putstr("exit\n");
		builtin_exit(NULL, (char*[]){"exit", NULL}, NULL);
	}
	else if (*pos < ft_strlen(*str))
		ft_del();
	else
		ft_puttermcaps("bl");
}

void	ft_control_c(void)
{
	char	**str;
	size_t	*pos;

	str = &data_singleton()->line.input;
	pos = &data_singleton()->line.pos;
	ft_putchar('\n');
	ft_prompt();
	ft_strdel(str);
	*pos = 0;
}
