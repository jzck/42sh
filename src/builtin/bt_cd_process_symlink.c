/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_cd_process_symlink.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 15:14:55 by ariard            #+#    #+#             */
/*   Updated: 2017/03/25 19:51:03 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define CDERR_0		"cd : %s: No such file or directory"
#define CDERR_1		"cd : %s: Permission denied"
#define CDERR_2		"cd : %s: Not a directory"
#define CDERR_3		"cd : unable to proceed: %s"
#define CDERR_4		"cd : %s: Symlink not resolved"

int			bt_cd_process_symlink(char *target)
{
	char		buffer[PATH_MAX + 1];

	ft_bzero(buffer, PATH_MAX + 1);
	if (access(target, F_OK))
		return (SH_ERR(CDERR_0, target));
	if (access(target, X_OK))
		return (SH_ERR(CDERR_1, target));
	if (!is_directory(target))
		return (SH_ERR(CDERR_2, target));
	if (chdir(target))
		return (SH_ERR(CDERR_3, target));
	setwd("PWD");
	if (readlink(target, buffer,  PATH_MAX + 1) < 0)
		return (SH_ERR(CDERR_4, target));
	else if (ft_strlen(buffer) > 0)
		builtin_setenv(NULL, (char*[]){"cd", "PWD", buffer, NULL}, NULL);
	return (0);
}
