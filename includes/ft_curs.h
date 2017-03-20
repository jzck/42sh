/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_curs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:34:51 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/20 12:33:06 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CURS_H
# define FT_CURS_H

# include "libft.h"

# include <sys/ioctl.h>
# include <signal.h>
# include <termios.h>
# include <term.h>
# include <curses.h>

typedef struct s_curs	t_curs;

/*
** Cursor data : cursor's coordonate and windows size
*/

struct	s_curs
{
	int					co;
	int					li;
	int					win_co;
	int					win_li;
};

/*
** Cursor reference singleton
*/

t_curs					*curs_single(t_curs *curs, int set);

/*
** Cursor setup
*/

int						curs_li_ask(void);
int						curs_co_ask(void);

int						curs_term_setup(void);
void					curs_win_setup(t_curs *curs);
int						curs_coo_setup(t_curs *curs);
int						curs_setup(t_curs *curs);

/*
** Cursor cleanup
*/

int						curs_term_cleanup(void);
int						curs_cleanup(t_curs *curs);

/*
** Cursor's data reset
*/

void					curs_reset(int sig);

/*
** Cursor manipulation function
*/

void					curs_clear(t_curs *curs);
void					curs_clear_post(t_curs *curs);
void					curs_goto(t_curs *curs, int li, int co);
void					curs_forward(t_curs *curs, int offset);
void					curs_backward(t_curs *curs, int offset);
void					curs_write(t_curs *curs, char *str, size_t len);
void					curs_write_static(t_curs *curs, char *str, size_t len);
void					curs_video_write(t_curs *curs, char *str, size_t len);
void					curs_video_write_static(
						t_curs *curs, char *str, size_t len);

#endif
