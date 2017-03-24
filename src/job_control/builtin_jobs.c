/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_jobs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 17:43:01 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/24 18:17:02 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cliopts	g_jobs_opts[] =
{
	{'l', NULL, JOBS_OPT_L, 0, NULL},
	{0, 0, 0, 0, 0},
};

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
			SH_ERR("jobs: %s: no such job", *av);
			return (1);
		}
		job_format(lst->content, opts);
		av++;
	}
	return (0);
}

int			builtin_jobs(const char *path, char *const av[], char *const envp[])
{
	t_data_template		data;

	(void)path;
	(void)envp;
	if (!SH_HAS_JOBC(data_singleton()->opts))
		return (SH_ERR("jobs: %s", SH_MSG_NOJOBC));
	do_job_notification();
	ft_bzero(&data, sizeof(t_data_template));
	if (cliopts_get((char**)av, g_jobs_opts, &data))
		return (ft_perror("jobs"));
	if (!*data.av_data)
		bt_jobs_all(data.flag);
	else if (bt_jobs_spec(data.av_data, data.flag))
		return (1);
	return (0);
}
