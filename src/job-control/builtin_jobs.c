/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_jobs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 17:43:01 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/31 15:05:34 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

static int	bt_jobs_parse(char **av, int *i)
{
	int		opts;
	int		j;

	opts = 0;
	*i = 1;
	while (av[*i])
	{
		j = 0;
		if (av[*i][j++] != '-')
			break ;
		while (av[*i][j])
		{
			if (av[*i][j] == 'l')
				opts |= JOBS_OPTS_L;
			else
			{
				ft_dprintf(2, "{red}%s: bad option: -%c{eoc}\n",
						SHELL_NAME, av[*i][j]);
				return (-1);
			}
			j++;
		}
		(*i)++;
	}
	return (opts);
}

static void	bt_jobs_all(int opts)
{
	t_jobc	*jobc;
	t_list	*jlist;
	t_list	*tmplist;

	jobc = &data_singleton()->jobc;
	jlist = jobc->first_job;
	tmplist = ft_lst_filter(jlist, NULL, NULL);
	ft_lstsort(&tmplist, job_cmp_id);
	jlist = tmplist;
	while (jlist)
	{
		job_format(jlist->content, opts);
		jlist = jlist->next;
	}
	ft_lstdel(&tmplist, ft_lst_cfree);
}

static int	bt_jobs_spec(char **av, int opts)
{
	t_jobc	*jobc;
	t_list	*jlist;
	t_list	*lst;
	int		id;

	jobc = &data_singleton()->jobc;
	jlist = jobc->first_job;
	while (*av)
	{
		id = ft_atoi(*av);
		if (!(lst = ft_lst_find(jlist, &id, job_cmp_id)))
		{
			ft_dprintf(2, "{red}jobs: %s: no such job{eoc}\n", *av);
			return (1);
		}
		job_format(lst->content, opts);
		av++;
	}
	return (0);
}

int			builtin_jobs(const char *path, char *const av[], char *const envp[])
{
	int		opts;
	int		i;

	(void)path;
	(void)envp;
	if (!SHELL_HAS_JOBC(data_singleton()->opts))
	{
		ft_dprintf(2, "{red}jobs: %s{eoc}\n", SHELL_MSG_NOJOBC);
		return (1);
	}
	if ((opts = bt_jobs_parse((char**)av, &i)) < 0)
		return (1);
	if (!av[i])
		bt_jobs_all(opts);
	else if (bt_jobs_spec((char **)av + i, opts))
		return (1);
	return (0);
}
