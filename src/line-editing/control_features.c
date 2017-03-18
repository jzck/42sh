/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_features.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:17:28 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/18 15:13:46 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_buff_f6(char **str, size_t *pos)
{
	int ret;

	ret = 0;
	(void)str;
	(void)pos;
	if (read(0, &ret, sizeof(int)) < 0)
		return (-1);
	return (0);
}

int		ft_control_d(char **str, size_t *pos)
{
	if (!*str || (*str)[0] == '\0')
	{
		ft_putstr("exit\n");
		builtin_exit(NULL, (char*[]){"exit", NULL}, NULL);
		data_singleton()->line.is_prompt ? ft_prompt() : ft_putstr("> ");
	}
	else if (*pos < ft_strlen(*str))
		ft_del(str, pos);
	else
		ft_puttermcaps("bl");
	return (0);
}

int		ft_control_c(char **str, size_t *pos)
{
	set_exitstatus(1, 1);
	if (*str)
		ft_current_str(*str, *pos);
	ft_strdel(str);
	*pos = 0;
	return (42);
}

int		ft_control_l(char **str, size_t *pos)
{
	ft_clear_window();
	ft_prompt();
	ft_strdel(str);
	*pos = 0;
	return (0);
}
