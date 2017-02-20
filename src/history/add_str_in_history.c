/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_str_in_history.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 11:27:03 by gwojda            #+#    #+#             */
/*   Updated: 2017/02/16 12:37:35 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_add_in_history_file(char *str)
{
	int		fd;
	char	*home;
	char	*path;

	if (!(home = ft_getenv(data_singleton()->env, "HOME")))
		return ;
	path = ft_str3join(home, "/", ".42sh_history");
	fd = open(path, O_CREAT | O_WRONLY | O_APPEND, S_IWUSR | S_IRUSR);
	if (fd == -1)
		return ;
	write(fd, str, ft_strlen(str));
	write(fd, "\n", 1);
	free(path);
	close(fd);
}

void	ft_add_str_in_history(char *str)
{
	if (str && (!data_singleton()->line.list_beg ||
	ft_strcmp(data_singleton()->line.list_beg->prev->str, str)))
	{
		ft_push_back_history(&data_singleton()->line.list_beg,
			ft_create_history_list(str));
		ft_add_in_history_file(str);
	}
}
