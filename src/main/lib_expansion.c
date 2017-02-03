/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_expansion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 13:37:41 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/03 13:37:41 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_expand_dollar(char **av, char **env)
{
	char	*dollar;

	while (*av)
	{
		if ((dollar = ft_strchr(*av, '$')))
		{
			*dollar = '\0';
			*av = ft_strjoin(*av, ft_getenv(env, dollar + 1));
		}
		av++;
	}
}
