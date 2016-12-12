/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:07:44 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/12 17:56:30 by jhalford         ###   ########.fr       */
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
# include "job_control.h"

# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <signal.h>
# include <fcntl.h>

typedef long long		t_type;
typedef struct s_line	t_line;
typedef struct s_comp	t_comp;
typedef struct s_exec	t_exec;
typedef struct s_jobc	t_jobc;
typedef enum e_mode		t_mode;

enum	e_mode
{
	MODE_INPUT,
	MODE_EXEC,
};

struct	s_line
{
	t_dlist	*history;
	int		input_pos;
	t_list	*qstack;
	char	*input;
};

struct	s_comp
{
	int		a;
};

struct	s_data
{
	char	**env;
	t_mode	mode;
	t_line	line;
	t_comp	comp;
	t_exec	exec;
	t_jobc	jobc;
};

typedef struct s_data	t_data;
typedef enum e_qstate	t_qstate;

extern t_stof	g_builtins[];
extern pid_t	g_pid;

t_data		*data_singleton();

void	shell_init(void);
void	shell_exit(void);
int		data_init(void);
void	data_exit(void);

int		ft_builtin(char **av);
int		builtin_echo(char **av, t_data *data);
int		builtin_cd(char **av, t_data *data);
int		builtin_exit(char **av, t_data *data);
int		builtin_setenv(char **av, t_data *data);
int		builtin_unsetenv(char **av, t_data *data);
int		builtin_env(char **av, t_data *data);

void	ft_expand_dollar(char **av, char **env);
char	*ft_findexec(char *path, char *file);

char	*ft_putast(void *node);
void	ft_putast2(void *node);

#endif
