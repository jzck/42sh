/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:07:44 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/10 13:12:41 by jhalford         ###   ########.fr       */
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

# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <signal.h>
# include <fcntl.h>
# include <errno.h>

enum	e_mode
{
	MODE_INPUT,
	MODE_EXEC,
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

extern t_stof	g_builtins[];

void	shell_init(void);
void	shell_exit(void);
int		data_init(void);
void	data_exit(void);

void	ft_expand_dollar(char **av, char **env);
char	*ft_findexec(char *path, char *file);

char	*ft_putast(void *node);
void	ft_putast2(void *node);

#endif
