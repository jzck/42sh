/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cliopts.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 20:22:56 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/15 19:00:17 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLI_OPTS_H
# define CLI_OPTS_H

# include "libft.h"
# include "error.h"

typedef struct s_cliopts		t_cliopts;
typedef struct s_data_template	t_data_template;
typedef long long				t_flag;

struct	s_cliopts
{
	char	c;
	char	*str;
	t_flag	flag_on;
	t_flag	flag_off;
	int		(*get)();
};

struct	s_data_template
{
	t_flag	flag;
};

int		cliopts_get(char **av, t_cliopts opt_map[], void *data);
char	**cliopts_getdata(char **av);
int		cliopts_has(char **av, char c);

#endif
