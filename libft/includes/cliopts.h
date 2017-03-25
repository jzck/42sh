/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cliopts.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 20:22:56 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/25 21:31:28 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIOPTS_H
# define CLIOPTS_H

# include "libft.h"
# include "error.h"

typedef struct s_cliopts		t_cliopts;
typedef struct s_data_template	t_data_template;
typedef long long				t_flag;

struct		s_cliopts
{
	char	c;
	char	*str;
	t_flag	flag_on;
	t_flag	flag_off;
	int		(*get)();
	int		arg_required:1;
};

struct		s_data_template
{
	t_flag	flag;
	char	**av_data;
};

int			cliopts_get(char **av, t_cliopts opt_map[], void *data);
t_cliopts	*cliopts_getmap_long(t_cliopts opt_map[], char *arg);
t_cliopts	*cliopts_getmap_short(t_cliopts opt_map[], char arg);

#endif
