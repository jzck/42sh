/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_control.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 16:55:09 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/09 16:56:18 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JOB_CONTROL_H
# define JOB_CONTROL_H

# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include "libft.h"
# include "types.h"

# define JOB_NOTIFIED		(1 << 0)
# define JOB_BG				(1 << 1)
# define JOB_IS_BG(j)		(j & JOB_BG)
# define JOB_IS_FG(j)		!(j & JOB_BG)

#define JOBS_OPTS_L			(1 << 0)

struct	s_job
{
	int				id;
	pid_t			pgid;
	t_flag			attributes;
	t_list			*first_process;
	struct termios	tmodes;
};

struct	s_jobc
{
	t_list			*first_job;
	pid_t			shell_pgid;
	int				current_id;
	struct termios	shell_tmodes;
};

# include "exec.h"

t_process	*job_getprocess(pid_t pid);
int			job_addprocess(t_process *p);
void		job_update_id(void);
void		job_update_rank(void);

int			do_job_notification(void);
void		job_notify_new(t_job *job);
void		job_notify_change(int id);
void		job_format(t_job *j, int rank[2], int opts);
void		job_format_head(t_job *j, int rank[2]);

void		job_update_status(void);
void		mark_job_as_running (t_job *j);
int			process_mark_status(pid_t pid, int status);
int			job_is_stopped(int id);
int			job_is_completed(int id);

void		job_new(char **av, pid_t pid);
int			job_wait(int id);
void		job_remove(int id);
void		job_free(void *content, size_t content_size);
void		job_kill_all(void);

int			put_job_in_foreground(t_job *job, int cont);
int			put_job_in_background(t_job *job, int cont);

int			job_cmp_pid(t_job *job, pid_t *pid);
int			job_cmp_id(t_job *job, int *id);
void		job_getrank(int (*rank)[2]);

void		sigchld_handler(int signo);
void		sigint_handler(int signo);
void		sigtstp_handler(int signo);
void		sigttin_handler(int signo);
void		sigttou_handler(int signo);

int			process_cmp_pid(t_process *p, pid_t *pid);
void		process_format(t_list **p, int firstp, int opts);

#endif