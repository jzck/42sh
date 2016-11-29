/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:07:44 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/29 20:30:49 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define SHELL_NAME		"minishell"

# include "libft.h"

# include "line_editing.h"
# include "lexer.h"
# include "parser.h"
# include "exec.h"

# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <signal.h>
# include <fcntl.h>


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
	char		**env;
	t_dlist		*history;
	char		*input;
	int			input_pos;
	t_list		*qstack;
	int			fdin;
	int			fdout;
	int			save_in;
	int			save_out;
};

extern t_stof	g_builtins[];
extern pid_t	g_pid;

void	sig_handler(int signo);
int		data_init(t_data *data);

int		ft_builtin(char **av, t_data *data);
int		builtin_echo(char **av, t_data *data);
int		builtin_cd(char **av, t_data *data);
int		builtin_exit(char **av, t_data *data);
int		builtin_setenv(char **av, t_data *data);
int		builtin_unsetenv(char **av, t_data *data);
int		builtin_env(char **av, t_data *data);

void	ft_expand_dollar(char **av, char **env);
char	*ft_findexec(char **path, char *file);

char	*ft_putast(void *node);
void	ft_putast2(void *node);

#endif
