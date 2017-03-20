/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_exitstatus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:25:17 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/20 18:15:50 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_exitstatus(int status, int override)
{
	char	*astatus;
	int		exitval;

	if (override)
		exitval = status;
	else
	{
		if (WIFEXITED(status))
			exitval = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			exitval = 128 + WTERMSIG(status);
		else
			return ;
	}
	astatus = ft_itoa(exitval);
	builtin_setenv("setenv", (char*[]){"setenv", "?", astatus, 0}, NULL);
	ft_strdel(&astatus);
}
