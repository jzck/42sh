/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 20:29:56 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/30 18:57:16 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# define PIPE_READ		0
# define PIPE_WRITE		1

# define PROCESS_BUILTIN	(1 << 0)
# define PROCESS_BINARY		(1 << 1)
# define PROCESS_SCRIPT		(1 << 2)
# define PROCESS_SUBSHELL	(1 << 3)
# define PROCESS_UNKNOWN	(1 << 4)
# define PROCESS_PIPESTART	(1 << 5)
# define PROCESS_PIPEEND	(1 << 6)
# define PROCESS_COMPLETED	(1 << 7)
# define PROCESS_SUSPENDED	(1 << 8)
# define PROCESS_RUNNING	(1 << 9)
# define PROCESS_CONTINUED	(1 << 10)

# define PROCESS_TYPE_MASK	(1 << 0 | 1 << 1 | 1 << 2 | 1 << 3 | 1 << 4)
# define PROCESS_STATE_MASK	(1 << 7 | 1 << 8 | 1 << 9 | 1 << 10)

# define IS_PIPESTART(a)	(a & PROCESS_PIPESTART)
# define IS_PIPEEND(a)		(a & PROCESS_PIPEEND)

# define SCRIPT_LOOP		(1 << 0)

# include "libft.h"
# include "types.h"
# include "job_control.h"

struct	s_process
{
	char	**av;
	char	*path;
	t_execf	*execf;
	pid_t	pid;
	int		fdin;
	int		fdout;
	int		status;
	t_flag	attributes;
	t_flag	script;
};

struct	s_exec
{
	char		*aol_status;
	int			aol_search;
	t_job		job;
	t_process	process;
};

struct	s_execmap
{
	t_type	type;
	int		(*f)(t_btree **ast);
};

#include "minishell.h"

extern t_execmap	g_execmap[];

int		ft_exec(t_btree **ast);

int		exec_semi(t_btree **ast);
int		exec_ampersand(t_btree **ast);
int		exec_or_if(t_btree **ast);
int		exec_and_if(t_btree **ast);
int		exec_pipe(t_btree **ast);

int		exec_less(t_btree **ast);
int		exec_great(t_btree **ast);
int		exec_dgreat(t_btree **ast);
int		exec_command(t_btree **ast);

int		exec_while(t_btree **ast);		

int		launch_process(t_process *p);
int		process_setexec(t_type type, t_process *p);
int		process_setgroup(t_process *p);
int		process_redirect(t_process *p);
void	process_free(void *content, size_t content_size);
void	process_reset(void);

void	fd_redirect(void);
void	fd_reset(void);

char	*ft_findexec(char *path, char *file);

void	set_exitstatus(int status);

void	ast_free(void *data, size_t content_size);

#endif
