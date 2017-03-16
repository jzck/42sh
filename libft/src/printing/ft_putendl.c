/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:57:40 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/20 18:17:01 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	char	nl;

	nl = '\n';
	write(fd, s, ft_strlen(s));
	write(fd, &nl, 1);
}

void	ft_putendl(char const *s)
{
	ft_putendl_fd(s, 1);
}
