/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_cd_process_dotdot.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 03:54:22 by ariard            #+#    #+#             */
/*   Updated: 2017/03/25 17:03:26 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define CDERR_6	"cd : %s: Permission denied"
#define CDERR_7 "cd : %s: No such file or directory"

static int			getsup(char *buf)
{
	int				len;

	len = ft_strlen(buf);
	while (len)
	{
		if (buf[len] == '/')
		{
			while (buf[len] == '/')
				len--;
			ft_strcat(buf, ft_strrchr(&buf[len], '/'));
			break;
		}
		len--;
	}
	return (0);
}

int			bt_cd_process_dotdot(char *target)
{
	char	*pwd;
	char	*buf;

	pwd = getcwd(NULL, 0);
	buf = ft_strnew(PATH_MAX + 1);
	if (target[0] == '.' && target[1] == '/')
		ft_strcat(buf, ft_strrchr(pwd, '/'));
	if (target[0] == '.' && target[1] == '.' && target[2] == '/')
		getsup(buf);
	target += ft_strlenchr(target, '/');
	while (target)
	{
		if (*target == '/' && *target++)
			ft_strcat(buf, "/");
		while (*target == '/')
			target++;
		if (target[0] == '.' && target[1] != '.')
			ft_strcat(buf, ft_strrchr(target, '/'));
		else if (target[0] == '.' && target[1] == '.')
			getsup(buf);
		else
			ft_strncat(buf, target, ft_strlenchr(target, '/'));
		target += ft_strlenchr(target, '/');
	}
	if (!access(target, R_OK))
		return (SH_ERR(CDERR_6, target));
	if (chdir(target))
		return (SH_ERR(CDERR_7, target));
	return (0);	
}
