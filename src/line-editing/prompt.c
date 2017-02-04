/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 13:51:33 by gwojda            #+#    #+#             */
/*   Updated: 2017/02/04 14:56:51 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**ft_printf de la lib bug avec unicode
*/

static void	ft_get_date(void)
{
	time_t		t;
	struct tm	tm;

	t = time(NULL);
	tm = *localtime(&t);
	ft_putstr("\033[22;32m");
	printf("%.2d:%.2d:%.2d ", tm.tm_hour, tm.tm_min, tm.tm_sec);
	fflush(NULL);
	if (tm.tm_hour >= 8 && tm.tm_hour < 20)
		printf("\033[22;33m%C ", L'☀');
	else
		printf("\033[22;33m%C ", L'★');
	fflush(NULL);
}

static int	ft_currend_dir(void)
{
	int		i;
	int		j;
	char	**env;

	i = 0;
	env = data_singleton()->env;
	while (ft_strncmp(env[i], "PWD=", 4))
		++i;
	j = ft_strlen(env[i]);
	while (j && env[i][j] != '/')
		--j;
	ft_putstr(env[i] + j + 1);
	return (ft_strlen(env[i] + j + 1));
}

void		ft_prompt(void)
{
	int ret;

	do_job_notification();
	ft_get_date();
	ft_putstr("\033[22;36m");
	ret = ft_currend_dir();
	ft_putstr("\033[22;33m");
	printf(" %C", L'›');
	fflush(NULL);
	ft_putstr("\033[22;37m");
	data_singleton()->line.prompt_size = ret + 12;
}
