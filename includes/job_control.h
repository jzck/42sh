/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_control.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 16:55:09 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/10 18:20:40 by jhalford         ###   ########.fr       */
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

extern t_data	*g_data;

void	job_new(t_data *data, char **av, pid_t pid);
void	job_announce(t_job *job);

int		ft_cmppid(t_job *job, pid_t *pid);

void	sigchld_handler(int signo);
void	sigint_handler(int signo);
void	sigtstp_handler(int signo);

#endif
