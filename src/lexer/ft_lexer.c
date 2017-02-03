/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:30:59 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/03 15:40:34 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		ft_lexer(t_list **alst, char **command)
{
	int		ret;

	if (!*command)
		return (1);
	ret = 0;
	if (ft_tokenize(alst, *command, DEFAULT))
		ret = 1;
	else if (ft_post_tokenize(alst, command))
		ret = 1;
	ft_strdel(command);
	return (ret);
}
