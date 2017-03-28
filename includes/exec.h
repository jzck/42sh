/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 20:29:56 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/28 20:22:01 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "types.h"
# include "job_control.h"
# include <sys/stat.h>

# define IS_PIPESTART(p)	((p).fdin == STDIN)
# define IS_PIPEEND(p)		((p).fdout == STDOUT)
# define IS_PIPESINGLE(p)	(IS_PIPESTART(p) && IS_PIPEEND(p))

# define EXEC_AND_IF			(1 << 0)
# define EXEC_OR_IF				(1 << 1)
# define EXEC_IF_BRANCH			(1 << 2)
# define EXEC_CASE_BRANCH		(1 << 3)

# define EXEC_AOL_MASK			(EXEC_AND_IF | EXEC_OR_IF)

# define EXEC_IS_BG(j)			(j & EXEC_BG)
# define EXEC_IS_FG(j)			(!EXEC_IS_BG(j))
# define EXEC_IS_AND_IF(j)		(j & EXEC_AND_IF)
# define EXEC_IS_OR_IF(j)		(j & EXEC_OR_IF)
# define EXEC_IS_IF_BRANCH(j)	(j & EXEC_IF_BRANCH)
# define EXEC_IS_CASE_BRANCH(j)	(j & EXEC_CASE_BRANCH)

struct	s_data_cmd
{
	char		**av;
	char		*path;
	t_execf		*execf;
	struct stat	*stat;
};

struct	s_data_cond
{
	t_btree		*condition;
	t_btree		*content;
};

struct	s_data_list
{
	t_ld	*token;
	t_btree	*content;
};

struct	s_data_tree
{
	t_btree	*content;
};

union	u_process_data
{
	struct s_data_cmd		cmd;
	struct s_data_tree		subshell;
	struct s_data_tree		brace;
	struct s_data_tree		function;
	struct s_data_cond		d_while;
	struct s_data_cond		d_until;
	struct s_data_tree		d_if;
	struct s_data_list		d_for;
	struct s_data_list		d_case;
};

enum	e_process_state
{
	PROCESS_COMPLETED,
	PROCESS_SUSPENDED,
	PROCESS_RUNNING,
	PROCESS_CONTINUED,
};

enum	e_process_type
{
	PROCESS_FUNCTION,
	PROCESS_BUILTIN,
	PROCESS_FILE,
	PROCESS_SUBSHELL,
	PROCESS_BRACE,
	PROCESS_WHILE,
	PROCESS_UNTIL,
	PROCESS_IF,
	PROCESS_FOR,
	PROCESS_CASE,
	PROCESS_EMPTY,
	PROCESS_MAX
};

struct	s_process_map
{
	int		type;
	int		(*launch)();
	int		(*print)();
	int		(*free)();
};

struct	s_process
{
	t_process_type	type;
	t_process_data	data;
	t_process_map	map;
	t_process_state	state;
	pid_t			pid;
	int				fdin;
	int				fdout;
	int				to_close;
	t_list			*redirs;
	int				status;
};

struct	s_job
{
	int				id;
	pid_t			pgid;
	t_flag			attrs;
	t_list			*first_process;
	struct termios	tmodes;
};

struct	s_exec
{
	t_job		job;
	t_flag		attrs;
	int			fdin;
	t_list		*op_stack;
	char		**case_pattern;
};

int		exec_init(t_exec *exec);
int		exec_destroy(t_exec *exec);
int		process_fork(t_process *p);
int		process_setgroup(t_process *p, pid_t pid);
void	process_setsig(void);
void	process_reset(t_process *p);

int		fd_is_valid(int fd, int flag);
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
void	*node_copy(void *data);
void	*redir_copy(void *data);

void	redir_free(void *data, size_t content_size);

char	**token_to_argv(t_ld *ld, int do_match);
t_btree	*is_function(t_process *p);

/*
** Mapping pour free les process
*/
void	process_free(void *content, size_t content_size);
int		pfree_cmd(t_process *p);
int		pfree_cond(t_process *p);
int		pfree_list(t_process *p);
int		pfree_subshell(t_process *p);
int		pfree_func(t_process *p);

/*
** Mapping pour launch les process
*/
int		process_launch(t_process *p);
int		plaunch_if(t_process *p);
int		plaunch_while(t_process *p);
int		plaunch_until(t_process *p);
int		plaunch_for(t_process *p);
int		plaunch_case(t_process *p);
int		plaunch_file(t_process *p);
int		plaunch_builtin(t_process *p);
int		plaunch_subshell(t_process *p);
int		plaunch_brace(t_process *p);
int		plaunch_function(t_process *p);
int		plaunch_empty(t_process *p);

/*
** Mapping pour set les process
*/

int		process_set(t_process *p, t_btree *ast);
int		pset_map(t_process *p, t_btree *ast);
int		pset_cmd(t_process *p, t_btree *ast);
int		pset_while(t_process *p, t_btree *ast);
int		pset_until(t_process *p, t_btree *ast);
int		pset_if(t_process *p, t_btree *ast);
int		pset_for(t_process *p, t_btree *ast);
int		pset_case(t_process *p, t_btree *ast);
int		pset_subshell(t_process *p, t_btree *ast);
int		pset_brace(t_process *p, t_btree *ast);

/*
** Mapping pour exec les process
*/
int		ft_exec(t_btree **ast);
int		exec_leaf(t_btree **ast);
int		exec_semi(t_btree **ast);
int		exec_ampersand(t_btree **ast);
int		exec_or_if(t_btree **ast);
int		exec_and_if(t_btree **ast);
int		exec_pipe(t_btree **ast);
int		exec_elif(t_btree **ast);
int		exec_else(t_btree **ast);
int		exec_var(t_btree **ast);
int		exec_case_branch(t_btree **ast);
int		exec_math(t_btree **ast);
int		exec_bang(t_btree **ast);
int		exec_func(t_btree **ast);

#endif
