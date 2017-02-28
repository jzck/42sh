/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:21:56 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/27 20:28:37 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "types.h"
# include "libft.h"
# include "builtin_read.h"

t_execf	*is_builtin(t_process *p);
int		builtin_export(const char *path, char *const av[], char *const envp[]);
int		builtin_unset(const char *path, char *const av[], char *const envp[]);
int		builtin_env(const char *path, char *const argv[], char *const envp[]);
int		builtin_echo(const char *path, char *const argv[], char *const envp[]);
int		builtin_cd(const char *path, char *const argv[], char *const envp[]);
int		builtin_exit(const char *path, char *const argv[], char *const envp[]);
int		builtin_setenv(const char *path, char *const argv[], char *const envp[]);
int		builtin_unsetenv(const char *path, char *const argv[], char *const envp[]);
int		builtin_jobs(const char *path, char *const av[], char *const envp[]);
int		builtin_fg(const char *path, char *const av[], char *const envp[]);
int		builtin_bg(const char *path, char *const av[], char *const envp[]);
int		builtin_history(const char *path, char *const av[], char *const envp[]);
int		builtin_hash(const char *path, char *const av[], char *const envp[]);

#endif
