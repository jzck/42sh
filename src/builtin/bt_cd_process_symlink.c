/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_cd_process_symlink.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 15:14:55 by ariard            #+#    #+#             */
/*   Updated: 2017/03/25 17:05:24 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define CDERR_3	"cd : %s: Permission denied"
#define CDERR_4 "cd : %s: No such file or directory"
#define CDERR_5 "cd : %s: Symlink not resolved"

int			bt_cd_process_symlink(char *target)
{
	char		buffer[PATH_MAX + 1];

	ft_bzero(buffer, PATH_MAX + 1);
	if (!access(target, R_OK))
		return (SH_ERR(CDERR_3, target));
	if (chdir(target))
		return (SH_ERR(CDERR_4, target));
	setwd("PWD");
	if (readlink(target, buffer,  PATH_MAX + 1) < 0)
		return (SH_ERR(CDERR_5, target));
	else if (ft_strlen(buffer) > 0)
		builtin_setenv(NULL, (char*[]){"cd", "PWD", buffer, NULL}, NULL);
	return (0);
}
