/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 20:29:56 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/30 21:07:40 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"
# define PIPE_READ		0
# define PIPE_WRITE		1

typedef struct s_exec	t_exec;

struct s_exec
{
	t_type	type;
	int		(*f)(t_btree *ast, t_data *data);
};

extern t_exec	g_exec[];

int		ft_exec(t_btree *ast, t_data *data);

int		exec_semi(t_btree *ast, t_data *data);
int		exec_or_if(t_btree *ast, t_data *data);
int		exec_and_if(t_btree *ast, t_data *data);
int		exec_pipe(t_btree *ast, t_data *data);

int		exec_less(t_btree *ast, t_data *data);
int		exec_great(t_btree *ast, t_data *data);
int		exec_dgreat(t_btree *ast, t_data *data);
int		exec_command(t_btree *ast, t_data *data);

void	fd_redirect(t_data *data);
void	fd_reset(t_data	*data);

int		ft_cmd_process(char **argv, t_data *data);
int		ft_cmd_exec(char *execpath, char **argv, t_data *data);

#endif
