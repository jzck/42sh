/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 20:29:56 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/13 17:50:40 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# define PIPE_READ		0
# define PIPE_WRITE		1

# include "libft.h"
# include "types.h"
# include "job_control.h"

struct	s_process
{
	char	**argv;
	char	*path;
	t_execf	*execf;
	pid_t	pid;
	int		fdin;
	int		fdout;
	int		status;
	t_flag	attributes;
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

int		launch_process(t_process *p);
int		process_setexec(t_process *p);
int		process_setgroup(t_process *p);
int		process_redirect(t_process *p);
void	process_free(void *content, size_t content_size);

void	fd_redirect(void);
void	fd_reset(void);

char	*ft_findexec(char *path, char *file);

void	set_exitstatus(int status);

void	ast_free(void *data, size_t content_size);

#endif
