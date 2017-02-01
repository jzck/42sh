/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 18:20:23 by gwojda            #+#    #+#             */
/*   Updated: 2017/02/01 15:27:31 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_get_beggin(char *str, size_t *pos)
{
	while ((*pos) && str[(*pos)] != '\n')
		--(*pos);
	if (*pos && str[(*pos)] == '\n')
		++(*pos);
}

void	ft_get_next_str(char *str, size_t *pos)
{
	while (str[(*pos)] && str[(*pos)] != '\n')
		++(*pos);
	if (*pos && str[(*pos)] == '\n')
		--(*pos);
}

void	ft_putall_current_str(char *str, size_t *pos)
{
	int	len;

	len = 0;
	ft_get_beggin(str, pos);
	while (str[(*pos) + len] && str[(*pos) + len] != '\n')
		++len;
	write(1, str + *pos, len);
}

void	ft_current_str(char *str, size_t pos)
{
	int	len;

	len = 0;
	while (str[pos + len] && str[pos + len] != '\n')
		++len;
	write(1, str + pos, len);
	ft_check_end_of_line(str, pos + len);
}

int		ft_strlen_next(char *str, size_t pos)
{
	int	len;

	len = 0;
	while (str[pos + len] && str[pos + len] != '\n')
		++len;
	return (len);
}
