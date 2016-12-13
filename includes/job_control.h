/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_control.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 16:55:09 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/13 17:50:50 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JOB_CONTROL_H
# define JOB_CONTROL_H

# include <sys/types.h>
# include <termios.h>
# include "libft.h"
# include "types.h"
# include "exec.h"

# define PROCESS_COMPLETED	1 << 0
# define PROCESS_STOPED		1 << 1
# define PROCESS_BUILTIN	1 << 2
# define PROCESS_BINARY		1 << 3
# define PROCESS_SCRIPT		1 << 4
# define PROCESS_UNKNOWN	1 << 5

struct	s_job
{
	int				id;
	pid_t			pgid;
	char			notified;
	int				foreground;
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

int		job_addprocess(t_process *p);
void	job_update_id(void);
void	job_print_change(t_job *job, int status);
void	job_update_rank(void);

void	job_new(char **av, pid_t pid);

void	job_free(void *content, size_t content_size);
int		job_cmp_pid(t_job *job, pid_t *pid);
int		job_cmp_id(t_job *job, int *id);

int		check_chlds(void);

void	sigchld_handler(int signo);
void	sigint_handler(int signo);
void	sigtstp_handler(int signo);

#endif
