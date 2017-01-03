/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_jobs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 17:43:01 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/03 18:13:47 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

int		builtin_jobs(const char *path, char *const av[], char *const envp[])
{
	t_jobc		*jobc;
	t_list		*jlist;
	t_job		*job;
	t_list		*plist;
	t_process	*p;
	char		rank;
	int			lg;
	int			firstp;

	jobc = &data_singleton()->jobc;
	jlist = jobc->first_job;
	(void)path;
	(void)envp;
	(void)av;
	lg = 0;
	if (ft_strcmp(av[1], "-l") == 0)
		lg = 1;
	rank = '+';
	while (jlist)
	{
		firstp = 1;
		job = jlist->content;
		ft_printf("{mag}[%i]  %c ", job->id, rank);
		if (lg)
			ft_printf("%i ", p->pid);
		ft_printf("attr=%#b ", job->attributes);
		plist = job->first_process;
		while (plist)
		{
			p = plist->content;
			if (lg)
			{
				if (!firstp)
					ft_printf("\n        ");
				ft_printf("%i ", p->pid);
			}
			else
				ft_putchar(' ');
			ft_sstrprint(p->av, ' ');
			if (plist->next)
				ft_printf(" |");
			plist = plist->next;
			firstp = 0;
		}
		jlist = jlist->next;
		rank = (rank == '+') ? '-' : ' ';
		ft_printf("{eoc}\n");
	}
	return (0);
}
