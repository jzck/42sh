/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:11:48 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/13 17:51:11 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct s_job		t_job;
typedef struct s_jobc		t_jobc;
typedef struct s_execmap	t_execmap;
typedef struct s_process	t_process;
typedef long long			t_type;
typedef long long			t_flag;
typedef int		(t_execf)(const char *path, char *const argv[], char *const envp[]);

#endif
