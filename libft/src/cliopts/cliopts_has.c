/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cliopts_has.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 20:03:18 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/14 20:24:39 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cliopts.h"

int		cliopts_has(char **av, char c)
{
	if (!av)
		return (0);
	while (*av)	
	{
		if (ft_strcmp(*av, "--") == 0)
			return (0);
		else if ((*av)[0] == '-' && (*av)[1] == '-')
			av++;
		else if ((*av)[0] == '-')
		{
			if (ft_strchr(*av + 1, c))
				return (1);
			av++;
		}
		else
			return (0);
	}
	return (0);
}
