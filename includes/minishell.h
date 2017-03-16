/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:07:44 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/16 15:41:33 by jhalford         ###   ########.fr       */
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
	t_flag	opts;
	int		fd;
	char	**env;
	char	**local_var;
	int		argc;
	char	**argv;
	t_line	line;
	t_comp	*comp;
	t_exec	exec;
	t_jobc	jobc;
	t_list	*heredoc_queue;
	t_list	*lst_func;
};

int		shell_init(int ac, char **av);
void	shell_exit(void);
int		data_init(int ac, char **av);
void	data_exit(void);
int		error_msg(char *msg);

int		instruction_free(
		t_list **token, t_btree **ast, t_lexer *lexer, t_parser *parser);
/* void		content_free(void *data, size_t content_size); */

char	*ft_putast(void *node);
void	ft_putast2(void *node);

#endif
