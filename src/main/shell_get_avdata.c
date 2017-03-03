/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_get_avdata.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 17:14:52 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/03 17:33:33 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*shell_get_avdata()
{
	t_data	*data;
	char	**av;
	int		i;

	data = data_singleton();
	av = data->argv;
	i = 1;
	while (av[i] && av[i][0] == '-')
	{
		if (ft_strcmp(av[i], "--") == 0)
		{
			i++;
			break ;
		}
		i++;
	}
	return(av[i]);
}
