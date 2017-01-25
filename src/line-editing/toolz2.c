/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolz2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 11:00:28 by gwojda            #+#    #+#             */
/*   Updated: 2017/01/24 15:00:16 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_nbr_len(int nbr)
{
	if (nbr % 10 != nbr)
		return (ft_nbr_len(nbr / 10) + 1);
	else
		return (1);
}

void	ft_puttermcaps(char *str)
{
	char	*res;
	char	*env;

	env = getenv("TERM");
	if ((res = tgetstr(str, &env)) == NULL)
		return ;
	tputs(res, 0, ft_put);
}

int		ft_size_term(void)
{
	return (tgetnum("co"));
}

long long	ft_pow(int nbr, int power)
{
	int			i;
	long long	ret;

	i = 0;
	ret = 1;
	while (i < power)
	{
		ret *= nbr;
		i++;
	}
	return (ret);
}