/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_post_tokenize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:11:11 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/11 17:07:39 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		ft_post_tokenize(t_list **alst, char *str)
{
	if (reduce_parens(alst, str))
		return (1);
	if (reduce_bquotes(alst, str))
		return (1);
	return (0);
}
