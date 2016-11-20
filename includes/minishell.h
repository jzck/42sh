/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:07:44 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/14 11:26:24 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"

# include "line_editing.h"
# include "lexer.h"
# include "parser.h"
# include "exec.h"

# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <signal.h>

typedef enum e_qstate	t_qstate;
typedef struct s_data	t_data;

enum	e_qstate
{
	Q_NONE,
	Q_QUOTE,
	Q_DQUOTE,
	Q_BACKSLASH,
};

struct	s_data
{
	char	**env;
	t_dlist	*history;

	char		*input;
	int			input_pos;
	t_qstate	state_now;
	t_qstate	state_last;
};

extern t_stof	g_builtins[];
extern pid_t	g_pid;

void	sig_handler(int signo);
int		data_init(t_data *data);


int		ft_cmd_process(char **argv, char ***env_p);
int		ft_cmd_exec(char *execpath, char **argv, char ***env_p);
char	**ft_cmd_getav(char *cmd);

int		ft_builtin(char **av, char ***env);
int		builtin_echo(char **av, char ***env);
int		builtin_cd(char **av, char ***env);
int		builtin_exit(char **av, char ***env);
int		builtin_setenv(char **av, char ***env);
int		builtin_unsetenv(char **av, char ***env);
int		builtin_env(char **av, char ***env);

void	ft_expand_dollar(char **av, char **env);
char	*ft_findexec(char **path, char *file);

char	*ft_putast(void *node);
void	ft_putast2(void *node);

#endif
