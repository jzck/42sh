/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cliopts_getmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 14:59:03 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/25 15:01:10 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cliopts.h"

t_cliopts	*cliopts_getmap_long(t_cliopts opt_map[], char *arg)
{
	int		i;

	i = -1;
	while (opt_map[++i].c)
		if (!ft_strcmp(opt_map[i].str, arg))
			return (&opt_map[i]);
	return (NULL);
}

t_cliopts	*cliopts_getmap_short(t_cliopts opt_map[], char arg)
{
	int		i;

	i = -1;
	while (opt_map[++i].c)
		if (opt_map[i].c == arg)
			return (&opt_map[i]);
	return (NULL);
}
