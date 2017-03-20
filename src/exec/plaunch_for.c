/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plaunch_for.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 00:49:20 by wescande          #+#    #+#             */
/*   Updated: 2017/03/20 15:51:47 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				plaunch_for(t_process *p)
{
	t_ld		*temp;
	int			i;
	char		**av;
	char		*var;

	temp = p->data.d_for.token;
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
			builtin_setenv("setenv", (char*[]){"local", var, av[i], 0},
					NULL);
			ft_exec(&p->data.d_for.content);
		}
		temp = temp->next;
	}
	return (ft_atoi(ft_getenv(data_singleton()->env, "?")));
}
