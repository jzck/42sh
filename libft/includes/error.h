/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 15:34:21 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/16 14:19:49 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "libft.h"
# include <stdarg.h>

# define DG_PROTO			"{inv}{ran}%5i{yel}%21s {bol}{blu}%-3d{eoc}"
# define DG_ARGS			getpid(), getpid(), ft_path_notdir(__FILE__), __LINE__
# define DG(s, ...)			ft_dprintf(STDBUG, DG_PROTO s "{eoc}\n", DG_ARGS, ##__VA_ARGS__)

# define ERR_PROTO(s, ...)	"{red}%s: " s "{eoc}\n", PROGNAME, ##__VA_ARGS__
# define ERR_SET(n, ...)	error_set(n, ##__VA_ARGS__)
# define ERRMSG_MAX_SIZE	150

enum e_errors
{
	E_NOERR,
	E_CO_INV,
	E_CO_INVL,
	E_CO_MULT,
	E_CO_MISS,
	E_CO_MISSL,
	E_MAX,
};

extern char	g_error_msg[E_MAX][ERRMSG_MAX_SIZE];
extern char	*g_errmsg;
extern int	g_errnum;
extern char	**g_argv;

int		error_set(int n, ...);
int		ft_perror(void);

#endif
