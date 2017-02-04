/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolz2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 11:00:28 by gwojda            #+#    #+#             */
/*   Updated: 2017/02/04 16:20:11 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_add_in_history_file(char *str)
{
	int		fd;

	fd = open(".42sh_history",
	O_CREAT | O_WRONLY | O_APPEND, S_IWUSR | S_IRUSR);
	if (fd == -1)
		return ;
	write(fd, str, ft_strlen(str));
	write(fd, "\n", 1);
	close(fd);
}

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

	env = getenv("TERM");
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
