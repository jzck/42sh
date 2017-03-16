/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:36:48 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/18 20:01:33 by jhalford         ###   ########.fr       */
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

# define FG_DEFAULT		"\e[0m"
# define ON_BOLD		"\e[1m"

# define ON_UNDERLINED	"\e[4m"
# define ON_INVERTED	"\e[7m"

# define FG_BLACK		"\e[30m"
# define FG_RED			"\e[31m"
# define FG_GREEN		"\e[32m"
# define FG_YELLOW		"\e[33m"
# define FG_BLUE		"\e[34m"
# define FG_MAGENTA		"\e[35m"
# define FG_CYAN		"\e[36m"

# define BG_BLACK		"\e[40m"
# define BG_RED			"\e[41m"
# define BG_GREEN		"\e[42m"
# define BG_YELLOW		"\e[43m"
# define BG_BLUE		"\e[44m"
# define BG_MAGENTA		"\e[45m"
# define BG_CYAN		"\e[46m"
# define BG_DEFAULT		"\e[49m"

# define FBG_DEFAULT	FG_DEFAULT BG_DEFAULT

void	ft_color_reset(void);
void	ft_color_set(t_color color);

void	ft_color_mk(t_color *color, char fg[7], char bg[7]);
void	ft_color_mkif(t_color *color, int cond, char fg[7], char bg[7]);

#endif
