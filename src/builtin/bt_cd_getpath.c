/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_cd_getpath.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 03:52:52 by ariard            #+#    #+#             */
/*   Updated: 2017/03/25 20:15:18 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*bt_cd_get_cdpath(char *arg)
{
	char	*cdpath;
	char	*target;

	if (!(cdpath = ft_getenv(data_singleton()->env, "CDPATH"))
		|| ft_strlen(cdpath) == 0)
	{
		if (!is_directory(target = ft_str3join(".", "/", arg)))
			ft_strdel(&target);
	}
	else
		target = create_directory(arg, cdpath);
	return (target);
}
