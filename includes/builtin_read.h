/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_read.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 15:02:39 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/13 20:39:49 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_READ_H
# define BUILTIN_READ_H

/* # include "types.h" */
/* # include "builtin.h" */
/* # include "minishell.h" */

# define READ_OPT_LA	(1 << 0)
# define READ_OPT_LD	(1 << 1)
# define READ_OPT_LE	(1 << 2)
# define READ_OPT_LI	(1 << 3)
# define READ_OPT_LN	(1 << 4)
# define READ_OPT_UN	(1 << 5)
# define READ_OPT_LP	(1 << 6)
# define READ_OPT_LR	(1 << 7)
# define READ_OPT_LS	(1 << 8)
# define READ_OPT_LT	(1 << 9)
# define READ_OPT_LU	(1 << 10)

typedef	struct s_read		t_read;
typedef	struct s_readopt	t_readopt;

struct	s_read
{
	t_flag	opts;
	char	delim;
	int		nchars;
	char	*prompt;
	int		timeout;
	int		fd;
	char	**names;
	char	*input;
};

struct s_readopt
{
	char	letter;
	t_flag	flag;
	int		(*get)(t_read *data, char *arg);
};

extern t_readopt	g_readtab[];

int				builtin_read(const char *path, char *const av[], char *const envp[]);

int				bt_read_init(t_read *data, char **av);

struct termios	bt_read_term(int init);
int				bt_read_terminit(t_read *data);
int				bt_read_exit(t_read *data);

int				bt_read_getdelim(t_read *data, char *arg);
int				bt_read_getnchars(t_read *data, char *arg);
int				bt_read_getprompt(t_read *data, char *arg);
int				bt_read_gettimeout(t_read *data, char *arg);
int				bt_read_getfd(t_read *data, char *arg);

#endif
