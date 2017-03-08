/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:07:44 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/08 20:53:04 by ariard           ###   ########.fr       */
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
	t_list	*heredoc_queue;
	char	**local_var;
	t_list	*lst_func;
};

void	shell_get_opts(int ac, char **av);
char	*shell_get_avdata();
void	shell_init(int ac, char **av);
void	shell_exit(void);
int		data_init(void);
void	data_exit(void);

int	instruction_free(t_list **token, t_parser *parser,
	t_btree **ast);

char	*ft_putast(void *node);
void	ft_putast2(void *node);

#endif
