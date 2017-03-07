/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_for.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:34:43 by wescande          #+#    #+#             */
/*   Updated: 2017/03/07 21:02:18 by wescande         ###   ########.fr       */
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
			builtin_setenv("setenv", (char*[]){var, av[i], 0},
					data_singleton()->local_var);
			ft_exec(&p->data.d_for.content);
			i++;
		}
		temp = temp->next;
	}
	return (ft_atoi(ft_getenv(data_singleton()->env, "?")));
}

int				launch_for(t_process *p)
{
	pid_t	pid;

	if (SH_IS_INTERACTIVE(data_singleton()->opts))
	{
		pid = fork();
		if (pid == 0)
		{
			data_singleton()->opts &= ~SH_INTERACTIVE;
			data_singleton()->opts &= ~SH_OPTS_JOBC;
			exit(do_for(p));
		}
		else if (pid > 0)
			return (pid);
	}
	else
		do_for(p);
	return (0);
}
/*
   int			exec_for(t_btree **ast)
   {
   t_astnode	*node;
   t_ld		*temp;
   char		**av;
   char		*var;
   int			i;

   node = (*ast)->item;
   temp = node->data.cmd.wordlist;
   var = ((char **)(temp->content))[0];
   if (ft_isdigit(var[0]))
   return (error_badidentifier(var));
   temp = temp->next;
   while (temp)
   {	
   i = 0;
   av = token_to_argv(temp, 1);
   while (av[i])
   {
   builtin_setenv("setenv", (char*[]){var, av[i], 0},
   data_singleton()->local_var);
   ft_exec(&(*ast)->right);
   i++;
   }
   temp = temp->next;
   }
   return (0);
   }*/
