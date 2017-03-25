/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:07:44 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/25 01:41:33 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define SHELL_NAME		"minishell"

# include <dirent.h>
# include <sys/stat.h>
# include <signal.h>
# include <fcntl.h>
# include <errno.h>

# include "../libft/includes/libft.h"
# include "types.h"
# include "lexer.h"
# include "parser.h"
# include "ft_readline.h"
# include "job_control.h"
# include "exec.h"
# include "builtin.h"
# include "glob.h"
# include "completion.h"
# include "hash.h"

# define SH_MSG(s, ...)	"{red}%s: " s "{eoc}\n", g_argv[0], ##__VA_ARGS__
# define SH_ERR(s, ...)	ft_dprintf(STDERR, SH_MSG(s, ##__VA_ARGS__))

struct	s_data
{
	t_flag		opts;
	char		**av_data;
	char		*c_arg;
	int			fd;
	char		**env;
	int			argc;
	char		**argv;
	t_line		line;
	t_lexer		lexer;
	t_parser	parser;
	t_comp		*comp;
	t_exec		exec;
	t_jobc		jobc;
	char		**local_var;
	t_list		*lst_func;
	char		*binary;
};

t_data	*data_singleton();
int		shell_init(int ac, char **av, char **env);
void	shell_exit(void);
int		data_init(int ac, char **av, char **env);
void	data_exit(void);
int		get_c_arg(char *opt_arg, t_data *data);

void	shell_resetfds(void);
void	shell_resetsig(void);

char	*ft_putast(void *node);
void	ft_putast2(void *node);

#endif
