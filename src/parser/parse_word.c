/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 12:49:45 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/07 16:06:24 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	**gen_tab(t_token *token)
{
	char	**the_tab;

	if (!(the_tab = (char **)malloc(sizeof(char *) * 4)))
		return (NULL);
	the_tab[0] = ft_strdup(token->data);
	the_tab[1] = (char *)dup_char_esc(token->esc, token->size >> 3);
	the_tab[2] = (char *)dup_char_esc(token->esc2, token->size >> 3);
//	ft_memcpy(the_tab[1], token->esc, token->size >> 3);
//	the_tab[2] = ft_strnew((token->size >> 3) + 1);
//	ft_memcpy(the_tab[2], token->esc2, token->size >> 3);
	the_tab[3] = NULL;
	return (the_tab);
}
int		parse_word(t_btree **ast, t_list **start, t_list **lst)
{
	t_astnode	*node;
	t_token		*token;
	char		**my_tab;

	(void)start;
	my_tab = NULL;
	token = (*lst)->content;
	node = (*ast)->item;
	node->type = TK_COMMAND;
	my_tab = gen_tab(token);
	ft_ld_pushback(&node->data.token, my_tab);
	ft_parse(ast, &(*lst)->next);
	ft_lst_delif(start, (*lst)->content, &ft_addrcmp, &token_free);
	return (0);
}
