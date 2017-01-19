/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 12:21:36 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/15 13:07:58 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32

# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>

typedef struct s_save	t_save;

struct	s_save
{
	int		fd;
	char	*str;
};

int		get_next_line(int const fd, char **line);

#endif
