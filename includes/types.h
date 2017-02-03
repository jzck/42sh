/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:11:48 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/03 15:03:52 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct s_data		t_data;

typedef long long			t_type;
typedef long long			t_flag;
typedef struct s_line		t_line;
typedef struct s_comp		t_comp;
typedef struct s_exec		t_exec;
typedef struct s_jobc		t_jobc;
typedef enum e_mode			t_mode;

typedef struct s_parser		t_parser;
typedef struct s_ld			t_ld;
typedef struct s_astnode	t_astnode;
typedef struct s_redir		t_redir;
typedef union u_astdata		t_astdata;
typedef union u_word		t_word;

typedef struct s_job		t_job;
typedef struct s_execmap	t_execmap;
typedef struct s_process	t_process;
typedef int		(t_execf)(const char *path, char *const argv[], char *const envp[]);

t_data		*data_singleton();

#endif
