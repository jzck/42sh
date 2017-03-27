/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 15:32:13 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/27 18:02:46 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		shell_fds_init(void)
{
	t_data	*data;
	int		i;

	data = data_singleton();
	i = -1;
	while (++i < 10)
		data->fd_save[i] = NULL;
}

int			shell_fds_push(void)
{
	t_data	*data;
	int		i;
	int		fd;

	data = data_singleton();
	i = -1;
	while (++i < 10)
	{
		fd = fcntl(i, F_DUPFD_CLOEXEC, 10);
		push(&(data->fd_save[i]), fd);
	}
	return (0);
}

int			shell_fds_pop(void)
{
	t_data	*data;
	int		i;
	int		fd;

	data = data_singleton();
	i = -1;
	while (++i < 10)
	{
		fd = pop(&data->fd_save[i]);
		if (fd != -1)
			close(fd);
	}
	return (0);
}

void		shell_fds_reset(void)
{
	t_data	*data;
	int		i;
	int		fd;

	data = data_singleton();
	i = -1;
	while (++i < 10)
	{
		fd = top(data->fd_save[i]);
		if (fd != -1)
			dup2(fd, i);
	}
}

void		shell_fds_destroy(void)
{
	t_data	*data;
	int		i;

	data = data_singleton();
	i = -1;
	while (++i < 10)
		ft_lstdel(&data->fd_save[i], ft_lst_cfree);
}
