/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_until.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 20:42:20 by ariard            #+#    #+#             */
/*   Updated: 2017/03/05 15:22:49 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int			exec_for(t_btree **ast)
{
	t_astnode	*node;
	t_list		*temp;
//	char		**av = NULL;
	char		*var;
		
	node = (*ast)->item;
	temp = node->data.cmd.wordlist;
	var = temp->content;
	temp = temp->next;
//	declare error bad identifier
	while (temp)
	{		
		builtin_setenv("setenv", (char*[]){var, temp->content, 0},
		data_singleton()->local_var);
		ft_exec(&(*ast)->right);
		temp = temp->next;
	}
	return (0);
}
