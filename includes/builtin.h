/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:21:56 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/08 14:34:40 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "types.h"
# include "libft.h"

t_execf	*is_builtin(t_process *p);
int		builtin_env(const char *path, char *const argv[], char *const envp[]);
int		builtin_echo(const char *path, char *const argv[], char *const envp[]);
int		builtin_cd(const char *path, char *const argv[], char *const envp[]);
int		builtin_exit(const char *path, char *const argv[], char *const envp[]);
int		builtin_setenv(const char *path, char *const argv[], char *const envp[]);
int		builtin_unsetenv(const char *path, char *const argv[], char *const envp[]);
int		builtin_jobs(const char *path, char *const av[], char *const envp[]);
int		builtin_fg(const char *path, char *const av[], char *const envp[]);

#endif
