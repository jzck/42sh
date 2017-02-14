/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_script.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 23:06:34 by ariard            #+#    #+#             */
/*   Updated: 2017/02/14 18:29:49 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		shell_script()
{
	t_list		*token;
	t_btree		*ast;
	t_list		*list_ast;
	t_script	*script;

	token = NULL;
	ast = NULL;
	list_ast = NULL;
	script = &data_singleton()->script;
	while (script->size)
	{
		if (ft_lexer(&token, &data_singleton()->script.buffer) || !token)
			return (1);
		DG("after post_tokenize");
		token_print(token);
		if (ft_parse(&ast, &token))
			return (1);
//			btree_print(STDBUG, ast, &ft_putast);
//			if (ft_exec(&ast))
//				return (1);
//			ast = NULL;
		script->size = 0;
		get_script_content(script);	
	}
	close(script->fd);
	return (0);
}
