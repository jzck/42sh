/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_control.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 16:55:09 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/15 17:49:56 by jhalford         ###   ########.fr       */
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
	int				rank[2];
	struct termios	shell_tmodes;
};

# include "exec.h"

t_process	*job_getprocess(pid_t pid);
int			job_addprocess(t_process *p);
void		job_update_id(void);
void		job_update_rank(void);

int			do_job_notification(void);
void		job_notify_new(t_job *job);
void		job_notify_change(int id, int status);

int			job_wait(t_job *job);
void		job_update_status(void);
int			job_is_stopped(t_job *job);
int			job_is_completed(t_job *job);
void		job_remove(int id);
void		job_free(void *content, size_t content_size);
int			process_mark_status(pid_t pid, int status);

int			put_job_in_foreground(t_job *job, int cont);
int			put_job_in_background(t_job *job, int cont);

void		job_new(char **av, pid_t pid);

int		job_cmp_pid(t_job *job, pid_t *pid);
int		job_cmp_id(t_job *job, int *id);

int		check_chlds(void);

void	sigchld_handler(int signo);
void	sigint_handler(int signo);
void	sigtstp_handler(int signo);

int		process_cmp_pid(t_process *p, pid_t *pid);

#endif
