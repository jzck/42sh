/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 22:59:57 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/15 21:55:22 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "types.h"
# include "libft.h"
# include "builtin_read.h"

# define BT_EXPORT_LP	(1 << 0)

# define MATHERR_0	"{red}math : invalid number of arguments{eoc}\n"	
# define MATHERR_1	"{red}math : invalid variable name{eoc}\n"
# define MATHERR_2	"{red}math : invalid operator{eoc}\n"
# define MATHERR_3	"{red}math : invalid operand{eoc}\n"
# define MATHERR_4	"{red}math : division by 0{eoc}\n"  

t_execf	*is_builtin(t_process *p);
int		builtin_export(const char *path, char *const av[], char *const envp[]);
int		builtin_unset(const char *path, char *const av[], char *const envp[]);
int		builtin_env(const char *path, char *const argv[], char *const envp[]);
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

#endif
