/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:34:23 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/07 17:34:35 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_init_history(void)
{
	int		fd;
	char	*str;
	char	*home;
	char	*path;

	if (!(home = ft_getenv(data_singleton()->env, "HOME")))
		return ;
	path = ft_str3join(home, "/", ".42sh_history");
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return ;
	while (get_next_line(fd, &str) > 0)
	{
		ft_push_back_history(&data_singleton()->line.list_beg,
		ft_create_history_list(str));
		free(str);
	}
	free(path);
	free(str);
	close(fd);
}
