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
# include "lexer_parser.h"
# include "exec.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <signal.h>

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

int		ft_tokenize(t_list **alst, char *str);

#endif
