/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 20:29:56 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/13 12:56:42 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# define PIPE_READ		0
# define PIPE_WRITE		1

# include "libft.h"

typedef struct s_execfunc	t_execfunc;
typedef long long			t_type;

struct	s_exec
{
	int		fdin;
	int		fdout;
	int		amp;
	char	*aol_status;
	int		aol_search;
};

struct	s_execfunc
{
	t_type	type;
	int		(*f)(t_btree **ast);
};

# include "minishell.h"

extern t_execfunc	g_execfunc[];

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

void	fd_redirect(void);
void	fd_reset(void);

int		ft_cmd_process(char **argv);
int		ft_cmd_exec(char *execpath, char **argv);
char	*ft_findexec(char *path, char *file);

void	ast_free(void *data, size_t content_size);

void	set_exitstatus(int status);

#endif
