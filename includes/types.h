/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:11:48 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/19 21:52:47 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef long long		t_type;
typedef struct s_line	t_line;
typedef struct s_comp	t_comp;
typedef struct s_exec	t_exec;
typedef struct s_jobc	t_jobc;
typedef enum e_mode		t_mode;

typedef struct s_data	t_data;
typedef enum e_qstate	t_qstate;

typedef struct s_job		t_job;
typedef struct s_jobc		t_jobc;
typedef struct s_execmap	t_execmap;
typedef struct s_process	t_process;
typedef long long			t_type;
typedef long long			t_flag;
typedef int		(t_execf)(const char *path, char *const argv[], char *const envp[]);

t_data		*data_singleton();

#endif
