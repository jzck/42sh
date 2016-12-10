/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_control.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 16:55:09 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/10 17:36:55 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JOB_CONTROL_H
# define JOB_CONTROL_H

# include "minishell.h"

typedef struct s_job	t_job;

struct	s_job
{
	int		id;
	pid_t	pid;
	char	*command;
};

void	job_new(t_data *data, char **av, pid_t pid);
void	job_announce(t_job *job);

#endif
