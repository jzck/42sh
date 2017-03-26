/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_str_in_history.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 11:27:03 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/26 21:59:21 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_add_in_history_file(char *str)
{
	int		fd;
	int		i;
	char	*home;
	char	*path;
	char	**hist;

	i = 0;
	if (!(home = ft_getenv(data_singleton()->env, "HOME")))
		return ;
	hist = ft_strsplit(str, '\n');
	path = ft_str3join(home, "/", ".42sh_history");
	fd = open(path, O_CREAT | O_WRONLY | O_APPEND, S_IWUSR | S_IRUSR);
	if (fd > 0)
	{
		while (hist[i])
		{
			write(fd, hist[i], ft_strlen(hist[i]));
			write(fd, "\n", 1);
			++i;
		}
		close(fd);
	}
	ft_sstrfree(hist);
	free(path);
}

void	ft_add_str_in_history(char *str)
{
	if (str && *str && (!data_singleton()->line.list_beg ||
				ft_strcmp(data_singleton()->line.list_beg->prev->str, str)))
	{
		ft_push_back_history(&data_singleton()->line.list_beg,
				ft_create_history_list(str));
		ft_add_in_history_file(str);
	}
}
