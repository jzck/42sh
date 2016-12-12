/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_control.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 16:55:09 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/12 17:51:54 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JOB_CONTROL_H
# define JOB_CONTROL_H

# include <sys/types.h>
# include <termios.h>
# include "libft.h"

typedef struct s_job	t_job;
typedef struct s_jobc	t_jobc;

struct	s_job
{
	int		id;
	pid_t	pid;
	char	*command;
};

struct	s_jobc
{
	t_list			*list;
	pid_t			shell_pgid;
	int				current_id;
	int				rank[2];
	struct termios	shell_tmodes;
};

# include "minishell.h"

extern t_data	*g_data;

void	job_new(char **av, pid_t pid);
void	job_announce(t_job *job);
void	job_free(void *content, size_t content_size);
int		job_cmp_pid(t_job *job, pid_t *pid);
int		job_cmp_id(t_job *job, int *id);
void	job_update_id(void);
void	job_print_change(t_job *job, int status);
void	job_update_rank(void);

int		check_chlds(void);

void	sigchld_handler(int signo);
void	sigint_handler(int signo);
void	sigtstp_handler(int signo);

#endif
