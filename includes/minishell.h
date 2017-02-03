/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:07:44 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/03 12:16:52 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define SHELL_NAME		"minishell"

# include "libft.h"

# include "types.h"
# include "lexer.h"
# include "parser.h"
# include "ft_readline.h"
# include "exec.h"
# include "builtin.h"
# include "job_control.h"
# include "glob.h"
# include "completion.h"

# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <signal.h>
# include <fcntl.h>
# include <errno.h>

# define SHELL_OPTS_JOBC	(1 << 0)
# define SHELL_OPTS_LC		(1 << 1)
# define SHELL_MODE_INPUT	(1 << 2)
# define SHELL_MODE_EXEC	(1 << 3)

# define SHELL_MODE_MASK	(SHELL_MODE_INPUT | SHELL_MODE_EXEC)
# define SHELL_HAS_JOBC(b)	(b & SHELL_OPTS_JOBC)

# define SHELL_MSG_NOJOBC	"no job-control"

struct	s_data
{
	char	**env;
	int		argc;
	char	**argv;
	t_flag	opts;
	t_line	line;
	t_comp	*comp;
	t_exec	exec;
	t_jobc	jobc;
};

extern t_stof	g_builtins[];

void	shell_get_opts(int ac, char **av);
char	*shell_get_avdata();
void	shell_init(int ac, char **av);
void	shell_exit(void);
int		data_init(void);
void	data_exit(void);

int		shell_single_command(char *command);

void	ft_expand_dollar(char **av, char **env);
char	*ft_findexec(char *path, char *file);

char	*ft_putast(void *node);
void	ft_putast2(void *node);

#endif
