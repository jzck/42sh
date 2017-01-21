/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_post_tokenize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:11:11 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/20 16:37:25 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		ft_post_tokenize(t_list **alst, char *str)
{
	int		ret;

	while ((ret = reduce_parens(alst, str)))
		if (ret == -1)
			return (-1);
	while ((ret = reduce_bquotes(alst, &str)))
		if (ret == -1)
			return (-1);
	DG("new command from bquotes: '%s'", str);
	return (0);
}
