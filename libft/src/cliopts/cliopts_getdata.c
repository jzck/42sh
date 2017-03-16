/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cliopts_getdata.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 20:35:15 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/14 21:35:19 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cliopts.h"

char	**cliopts_getdata(char **av)
{
	if (!av)
		return (NULL);
	av++;
	while (*av)	
	{
		if (ft_strcmp(*av, "--") == 0)
			return (av + 1);
		else if ((*av)[0] == '-' && (*av)[1] == '-')
			av++;
		else if ((*av)[0] == '-')
			av++;
		else
			return (av);
	}
	return (av);
}
