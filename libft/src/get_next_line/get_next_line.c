/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 13:12:06 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/21 15:43:51 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_fdcmp(t_save *a, int *b)
{
	return (a->fd - *b);
}

static void		ft_gnlfree(void *a, size_t size)
{
	(void)size;
	ft_strdel(&((t_save*)a)->str);
	free(a);
}

static t_list	*ft_newfd(t_list **head, int fd)
{
	t_save		new;

	new.fd = fd;
	new.str = ft_memalloc((BUFF_SIZE > 0 ? BUFF_SIZE : 0) + 1);
	ft_lstadd(head, ft_lstnew(&new, sizeof(t_save)));
	return (*head);
}

static int		ft_loop_read(int fd, char **line, char *save)
{
	char	buf[BUFF_SIZE + 1];
	char	*pos;
	char	*tmp;
	int		ret;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = 0;
		tmp = *line;
		if ((pos = ft_strchr(buf, '\n')))
		{
			ft_strcpy(save, pos + 1);
			*pos = 0;
		}
		if (!(*line = ft_strjoin(*line, buf)))
			return (-1);
		ft_strdel(&tmp);
		if (pos)
			return (1);
	}
	if (ret < 0)
		return (-1);
	return (**line ? 1 : 0);
}

int				get_next_line(int const fd, char **line)
{
	static t_list	*head;
	t_list			*tmp;
	char			*pos;
	char			*save;
	int				ret;

	if (fd < 0 || !line)
		return (-1);
	if (!(tmp = ft_lst_find(head, (void *)&fd, &ft_fdcmp)))
		tmp = ft_newfd(&head, fd);
	save = ((t_save*)tmp->content)->str;
	if (!(*line = ft_strdup(save)))
		return (-1);
	ft_bzero(save, BUFF_SIZE + 1);
	if ((pos = ft_strchr(*line, '\n')))
	{
		ft_strcpy(save, pos + 1);
		*pos = 0;
		return (1);
	}
	if (!(ret = ft_loop_read(fd, line, save)))
		ft_lst_delif(&head, (int *)&fd, ft_fdcmp, &ft_gnlfree);
	return (ret);
}
