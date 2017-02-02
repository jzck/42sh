/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_post_tokenize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:11:11 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/02 15:29:57 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		ft_post_tokenize(t_list **alst, char **str)
{
	int		ret;
	t_flag	tk;

	while ((ret = reduce_parens(alst, *str)))
		if (ret == -1)
		{
			ft_dprintf(2, "{red}%s: parse error near '('{eoc}\n", SHELL_NAME);
			return (-1);
		}
	tk = TK_PAREN_CLOSE;
	if (ft_lst_find(*alst, &tk, token_cmp_type))
		{
			ft_dprintf(2, "{red}%s: parse error near ')'{eoc}\n", SHELL_NAME);
			return (-1);
		}
	while ((ret = reduce_bquotes(alst, str)))
		if (ret == -1)
		{
			ft_dprintf(2, "{red}%s: parse error near '`'{eoc}\n", SHELL_NAME);
			return (-1);
		}
	DG("new command from bquotes: '%s'", *str);
	return (0);
}
