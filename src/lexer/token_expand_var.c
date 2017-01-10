/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_expand_var.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:57:53 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/10 16:37:33 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	token_expand_var(t_token *token)
{
	char	*dollar;
	char	*val;

	dollar = ft_strchr(token->data, '$');
	if (!dollar[1])
		return ;
	val = ft_getenv(data_singleton()->env, dollar + 1);
	*dollar = 0;
	if (val)
		while (*val)
			token_append(token, *val++);
}
