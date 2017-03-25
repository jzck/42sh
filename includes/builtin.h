/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 22:59:57 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/25 20:40:22 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "types.h"
# include "libft.h"
# include "builtin_read.h"

struct	s_env_data
{
	t_flag		flag;
	char		**av_data;
	char		**custom_env;
};

typedef struct s_env_data	t_env_data;

t_execf	*is_builtin(t_process *p);
int		builtin_return_status(int ret, int status);
int		builtin_export(const char *path, char *const av[], char *const envp[]);
int		builtin_unset(const char *path, char *const av[], char *const envp[]);
int		builtin_env(const char *path, char *const argv[], char *const envp[]);
int		bt_env_opt_u(char *opt_arg, t_env_data *data);
int		bt_env_opt_i(char *opt_arg, t_env_data *data);
int		builtin_echo(const char *path, char *const argv[], char *const envp[]);
int		builtin_cd(const char *path, char *const argv[], char *const envp[]);
int		builtin_exit(const char *path, char *const argv[], char *const envp[]);
int		builtin_setenv(
		const char *path, char *const argv[], char *const envp[]);
int		builtin_unsetenv(
		const char *path, char *const argv[], char *const envp[]);
int		builtin_jobs(const char *path, char *const av[], char *const envp[]);
int		builtin_fg(const char *path, char *const av[], char *const envp[]);
int		builtin_bg(const char *path, char *const av[], char *const envp[]);
int		builtin_history(const char *path, char *const av[], char *const envp[]);
int		builtin_hash(const char *path, char *const av[], char *const envp[]);
int		builtin_math(const char *path, char *const av[], char *const envp[]);
int		builtin_func(const char *path, char *const av[], char *const envp[]);

int		bt_env_geti(char ***av, t_env_data *data);

void	setwd(char *var);
char	*bt_cd_get_cdpath(char *arg);
int		bt_cd_process_dotdot(char *target);
int		bt_cd_process_symlink(char *target);

#endif
