/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolz2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 11:00:28 by gwojda            #+#    #+#             */
/*   Updated: 2017/02/16 16:05:40 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_nbr_len(int nbr)
{
	if (nbr % 10 != nbr)
		return (ft_nbr_len(nbr / 10) + 1);
	else
		return (1);
}

void		ft_puttermcaps(char *str)
{
	char	*res;
	char	*env;

	env = ft_getenv(data_singleton()->env, "TERM");
	if ((res = tgetstr(str, &env)) == NULL)
		return ;
	tputs(res, 0, ft_put);
}

int			ft_size_term(void)
{
	struct winsize w;

	ioctl(0, TIOCGWINSZ, &w);
	return (w.ws_col);
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

char	*ft_strdupi_w(char const *s)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] && s[i] != ' ' && s[i] != '\t')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str)
	{
		str[i--] = '\0';
		while (i >= 0)
		{
			str[i] = s[i];
			i--;
		}
	}
	return (str);
}
