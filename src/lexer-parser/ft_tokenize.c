/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:37:11 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/11 20:37:49 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_parser.h"

int		ft_tokenize(t_list **alst, char *str)
{
	t_token	*token;
	char	*cmd;
	int		pos;

	pos = 0;
	cmd = ft_strdup(str);
	while ((token = token_getnext(&pos, cmd)))
	{
		*alst = ft_lstnew(token, sizeof(*token));
		alst = &(*alst)->next;
		free(token);
	}
	ft_strdel(&cmd);
	return (0);
}
