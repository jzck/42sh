/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_read.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 15:02:39 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/25 01:24:42 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_READ_H
# define BUILTIN_READ_H

# define BT_READ_LA		(1 << 0)
# define BT_READ_LD		(1 << 1)
# define BT_READ_LE		(1 << 2)
# define BT_READ_LI		(1 << 3)
# define BT_READ_LN		(1 << 4)
# define BT_READ_UN		(1 << 5)
# define BT_READ_LP		(1 << 6)
# define BT_READ_LR		(1 << 7)
# define BT_READ_LS		(1 << 8)
# define BT_READ_LT		(1 << 9)
# define BT_READ_LU		(1 << 10)
# define BT_READ_INTER	(1 << 11)

typedef	struct s_read		t_read;
typedef	struct s_readopt	t_readopt;

struct			s_read
{
	t_flag		opts;
	char		**names;
	char		delim;
	int			nchars;
	char		*prompt;
	int			timeout;
	int			fd;
	char		*input;
};

int				builtin_read(const char *path, char *const av[],
				char *const envp[]);

int				bt_read_init(t_read *data, char **av);

struct termios	bt_read_term(int init);
int				bt_read_terminit(t_read *data);
int				bt_read_exit(t_read *data);

int				bt_read_getdelim(char *opt_arg, t_read *data);
int				bt_read_getnchars(char *opt_arg, t_read *data);
int				bt_read_getprompt(char *opt_arg, t_read *data);
int				bt_read_gettimeout(char *opt_argv, t_read *data);
int				bt_read_getfd(char *opt_arg, t_read *data);

#endif
