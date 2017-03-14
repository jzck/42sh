/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plaunch_for.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:34:43 by wescande          #+#    #+#             */
/*   Updated: 2017/03/15 00:03:12 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		do_for(t_process *p)
{
	t_ld		*temp;
	int			i;
	char		**av;
	char		*var;

	temp = p->data.d_for.list_word;
	var = ((char **)temp->content)[0];
	if (!word_is_assignment(temp->content))
		return (error_badidentifier(var));
	temp = temp->next;
	while (temp)
	{
		i = -1;
		av = token_to_argv(temp, 1);
		while (av[++i])
		{
			builtin_setenv("setenv", (char*[]){"local" ,var, av[i], 0},
					NULL);
			ft_exec(&p->data.d_for.content);
		}
		temp = temp->next;
	}
	return (ft_atoi(ft_getenv(data_singleton()->env, "?")));
}

int				plaunch_for(t_process *p)
{
	pid_t	pid;

	if (SH_IS_INTERACTIVE(data_singleton()->opts))
	{
		pid = fork();
		if (pid == 0)
		{
			data_singleton()->opts &= ~SH_INTERACTIVE;
			data_singleton()->opts &= ~SH_OPTS_JOBC;
			process_setgroup(p, 0);
			process_setsig();
			if (process_redirect(p))
				exit (1);
			exec_reset();
			exit(do_for(p));
		}
		else if (pid > 0)
			return (pid);
	}
	else
		do_for(p);
	return (0);
}
