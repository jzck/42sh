/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chlds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 12:28:40 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/12 17:23:14 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_chlds()
{
	/* int		status; */
	/* pid_t	pid; */
	/* t_job	*job; */
	/* t_list	**start; */
	/* t_list	*list; */

	/* DG("gonna check childs"); */
	/* start = &data_singleton()->jobc.list; */
	/* pid = waitpid(-1, &status, WNOHANG); */
	/* DG("waitpid = %i", pid); */
	/* list = *start ? ft_lst_find(*start, &pid, job_cmp_pid) : NULL; */
	/* if (list) */
	/* { */
	/* 	job = list->content; */
	/* 	if (job->id < data_singleton()->jobc.current_id) */
	/* 		data_singleton()->jobc.current_id = job->id; */
	/* 	job_print_change(job, status); */
	/* 	ft_lst_delif(start, list->content, ft_addrcmp, job_free); */
	/* 	job_update_rank(); */
	/* 	return (1); */
	/* } */
	return (0);
}
