/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_set_ast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:19:13 by ariard            #+#    #+#             */
/*   Updated: 2017/02/03 15:29:43 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list		**shell_get_ast(char *command)
{
	t_list	*token;
	t_btree	*ast;
	t_list	**list_ast;

	token = NULL;
	ast = NULL;
	list_ast = ft_memalloc(sizeof(*list_ast));
	if (ft_tokenize(&token, command, DEFAULT))
		return (NULL);
	if (!token)
		return (NULL);
	if (ft_post_tokenize(&token, &command))
		return (NULL);
	DG("after post_tokenize");
	token_print(token);
	if (ft_parse(list_ast, &ast, &token))
		return (NULL);
	return (list_ast);
}
