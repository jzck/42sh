/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:36:48 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/09 22:09:24 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H
# include "libft.h"

struct	s_color
{
	char	fg[7];
	char	bg[7];
};

typedef struct s_color	t_color;

# define FG_DEFAULT		"\x1b[0m"
# define ON_BOLD		"\x1b[1m"

# define ON_UNDERLINED	"\x1b[4m"
# define ON_INVERTED	"\x1b[7m"

# define FG_BLACK		"\x1b[30m"
# define FG_RED			"\x1b[31m"
# define FG_GREEN		"\x1b[32m"
# define FG_YELLOW		"\x1b[33m"
# define FG_BLUE		"\x1b[34m"
# define FG_MAGENTA		"\x1b[35m"
# define FG_CYAN		"\x1b[36m"

# define BG_BLACK		"\x1b[40m"
# define BG_RED			"\x1b[41m"
# define BG_GREEN		"\x1b[42m"
# define BG_YELLOW		"\x1b[43m"
# define BG_BLUE		"\x1b[44m"
# define BG_MAGENTA		"\x1b[45m"
# define BG_CYAN		"\x1b[46m"
# define BG_DEFAULT		"\x1b[49m"

# define FBG_DEFAULT	"\x1b[49m\x1b[20m"

void	ft_color_reset(void);
void	ft_color_set(t_color color);

void	ft_color_mk(t_color *color, char fg[7], char bg[7]);
void	ft_color_mkif(t_color *color, int cond, char fg[7], char bg[7]);

#endif
