/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 20:29:56 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/03 20:28:08 by wescande         ###   ########.fr       */
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
# define PROCESS_COMPLETED	(1 << 5)
# define PROCESS_SUSPENDED	(1 << 6)
# define PROCESS_RUNNING	(1 << 7)
# define PROCESS_CONTINUED	(1 << 8)

# define PROCESS_TYPE_MASK	(1 << 0 | 1 << 1 | 1 << 2 | 1 << 3 | 1 << 4)
# define PROCESS_STATE_MASK	(1 << 5 | 1 << 6 | 1 << 7 | 1 << 8)

# define IS_PIPESTART(p)	((p).fdin == STDIN)
# define IS_PIPEEND(p)		((p).fdout == STDOUT)
# define IS_PIPESINGLE(p)	(IS_PIPESTART(p) && IS_PIPEEND(p))

# define EXEC_BG				(1 << 1)
# define EXEC_AND_IF			(1 << 2)
# define EXEC_OR_IF				(1 << 3)
# define EXEC_IF_BRANCH			(1 << 4)
# define EXEC_CASE_BRANCH		(1 << 5)
# define EXEC_IS_BG(j)			(j & EXEC_BG)
# define EXEC_IS_FG(j)			(!EXEC_IS_BG(j))
# define EXEC_IS_AND_IF(j)		(j & EXEC_AND_IF)
# define EXEC_IS_OR_IF(j)		(j & EXEC_JOB_OR_IF)
# define EXEC_AOL_MASK			(EXEC_AND_IF | EXEC_OR_IF)

# define EXEC_IS_IF_BRANCH(j)	(j & EXEC_IF_BRANCH)
# define EXEC_IS_CASE_BRANCH(j)	(j & EXEC_CASE_BRANCH)

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
	int		to_close;
	t_list	*redirs;
	int		status;
	t_flag	attributes;
};

struct	s_exec
{
	/* char		*aol_status; */
	/* int			aol_search; */
	t_job		job;
	/* t_process	process; */
	int			fd_save[3];
	t_flag		attrs;
	int			fdin;
	t_list		*op_stack;
	char		*case_pattern;
};

struct	s_execmap
{
	t_type	type;
	int		(*f)(t_btree **ast);
};

struct	s_redirmap
{
	t_flag	type;
	int		(*f)(t_redir *redir);
};

#include "minishell.h"

extern t_execmap	g_execmap[];
extern t_redirmap	g_redirmap[];

int		ft_exec(t_btree **ast);

int		exec_default(t_btree **ast);

int		exec_semi(t_btree **ast);
int		exec_ampersand(t_btree **ast);
int		exec_or_if(t_btree **ast);
int		exec_and_if(t_btree **ast);
int		exec_pipe(t_btree **ast);
/* int		exec_redir(t_btree **ast); */
int		exec_cmd(t_btree **ast);

int		exec_while(t_btree **ast);
int		exec_if(t_btree **ast);
int		exec_elif(t_btree **ast);
int		exec_else(t_btree **ast);
int		exec_until(t_btree **ast);
int		exec_default(t_btree **ast);
int		exec_var(t_btree **ast);
int		exec_for(t_btree **ast);
int		exec_case(t_btree **ast);
int		exec_case_branch(t_btree **ast);

int		launch_process(t_process *p);
int		process_setexec(t_process *p);
int		process_setgroup(t_process *p, pid_t pid);
void	process_setsig(void);
void	process_free(void *content, size_t content_size);
void	process_reset(t_process *p);
void	process_resetfds(void);

int		fd_is_valid(int fd);
int		bad_fd(int fd);
int		process_redirect(t_process *p);
int		redirect_great(t_redir *redir);
int		redirect_less(t_redir *redir);
int		redirect_dgreat(t_redir *redir);
int		redirect_dless(t_redir *redir);
int		redirect_greatand(t_redir *redir);
int		redirect_lessand(t_redir *redir);

char	*ft_findexec(char *path, char *file);

void	set_exitstatus(int status, int override);

void	ast_free(void *data, size_t content_size);
void	redir_free(void *data, size_t content_size);

char	**token_to_argv(t_ld *ld, int do_match);

int		add_new_job(t_job *job);

#endif
