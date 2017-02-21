/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 20:29:56 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/21 21:41:18 by jhalford         ###   ########.fr       */
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

# define IS_PIPESTART(p)	(p->fdin == STDIN)
# define IS_PIPEEND(p)		(p->fdout == STDOUT)
# define IS_PIPESINGLE(p)	(IS_PIPESTART(p) && IS_PIPEEND(p))

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
	int		pipe_count;
	int		to_close;
	t_list	*redirs;
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
	int			fd0save;
	int			fd1save;
	int			fd2save;
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
int		exec_redir(t_btree **ast);
int		exec_command(t_btree **ast);

int		exec_while(t_btree **ast);
int		exec_if(t_btree **ast);
int		exec_elif(t_btree **ast);
int		exec_else(t_btree **ast);
int		exec_until(t_btree **ast);
int		exec_default(t_btree **ast);


int		launch_process(t_process *p);
int		process_setexec(t_type type, t_process *p);
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

int		loop_exec(t_list *list_ast);
int		loop_del(t_list *list_ast);

#endif
