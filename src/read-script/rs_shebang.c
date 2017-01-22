/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_shebang.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 21:42:27 by ariard            #+#    #+#             */
/*   Updated: 2017/01/22 23:11:57 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*rs_shebang_parse_interpreter(char *shebang)
{
	int		i;

	i = ft_strlen(shebang) - 1;
	while (shebang[i])
	{
		if (shebang[i] == '/')
			return (&shebang[++i]);
		i--;
	}
	return (NULL);
}	

static int	rs_valid_interpreter(char *interpreter)
{
	if (ft_strncmp(interpreter, "bash", ft_strlen("bash")) == 0)
		return (1);
	if (ft_strncmp(interpreter, "csh", ft_strlen("csh")) == 0)
		return (1);
	if (ft_strncmp(interpreter, "ksh", ft_strlen("bash")) == 0)
		return (1);
	if (ft_strncmp(interpreter, "sh", ft_strlen("bash")) == 0)
		return (1);
	if (ft_strncmp(interpreter, "tcsh", ft_strlen("bash")) == 0)
		return (1);
	if (ft_strncmp(interpreter, "tcsh", ft_strlen("bash")) == 0)
		return (1);
	if (ft_strncmp(interpreter, "minishell", ft_strlen("minishell")) == 0)
		return (1);
	return (0);
}

static void	rs_set_line_input(char *interpreter, char *file)
{
	char	*buffer;

	buffer = ft_strnew(1024);
	ft_strncpy(buffer, interpreter, ft_strlen(interpreter));
	ft_strncat(buffer, " ", 1);
	ft_strncat(buffer, file, ft_strlen(file));
	data_singleton()->line.input = buffer;
	data_singleton()->opts &= ~SHELL_MODE_MASK;
	data_singleton()->opts |= SHELL_MODE_INPUT;
}

int			rs_shebang_check(char *file, t_script *script)
{
	char	*interpreter;

	if (!script || !script->queue || !script->queue->next) 
		return (0);
	interpreter = rs_shebang_parse_interpreter(script->queue->next->content);
	if (interpreter == NULL || rs_valid_interpreter(interpreter) == 0)
		rs_set_line_input("sh", file);
	else if (ft_strncmp(interpreter, "minishell", ft_strlen("minishell")) != 0)	
		rs_set_line_input(interpreter, file);
	else if (ft_strncmp(interpreter, "minishell", ft_strlen("minishell")) == 0)
	{
		data_singleton()->opts &= ~SHELL_MODE_MASK;
		data_singleton()->opts |= SHELL_MODE_SCRIPT;
	}
	return (0);
}
