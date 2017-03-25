/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_new_cd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 02:00:40 by ariard            #+#    #+#             */
/*   Updated: 2017/03/25 02:04:47 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define CD_OPT_L	(1 << 0)
#define CD_OPT_P	(1 << 1)
#define HAS_CDOPT_P(x) (x & CD_OPT_P)
#define HAS_CDOPT_L(x) (x & CD_OPT_L)

static t_cliopts	g_cdopts[] =
{
	{'P', NULL, CD_OPT_P, CD_OPT_L, NULL},
	{'L', NULL, CD_OPT_L, CD_OPT_P, NULL},
	{0, NULL, 0, 0, NULL},
};

int					builtin_cd(const char *path, char *const av[],
					char *const av[], char *const envp[])
{
	char			*target;
	t_data_template	data;

	(void)envp;
	(void)path;
	data.flag = CD_OPT_L;
	if (cliopts_get((char **av, g_cdopts, &data))
		return (1);
		
