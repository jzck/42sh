/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_until.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 20:42:20 by ariard            #+#    #+#             */
/*   Updated: 2017/03/06 19:37:02 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

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
}
