/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_misc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 22:17:10 by alao              #+#    #+#             */
/*   Updated: 2017/02/16 22:18:43 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "completion.h"

/*
** Support: Return the size of a char**.
*/

int			ft_sstrlen(char **s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*
** Support: Tranform a char** as char* with char*sep in between.
*/

char		*ft_sstrtostr(char **s, char *sep)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	tmp = NULL;
	tmp2 = NULL;
	tmp = ft_strjoin(s[0], sep);
	i = 1;
	while (s[i])
	{
		tmp2 = ft_strjoin(tmp, s[i]);
		ft_memdel((void *)&tmp);
		tmp = ft_strjoin(tmp2, sep);
		ft_memdel((void *)&tmp2);
		i++;
	}
	return (tmp);
}
