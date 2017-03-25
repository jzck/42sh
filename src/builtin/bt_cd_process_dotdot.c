/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_cd_process_dotdot.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 03:54:22 by ariard            #+#    #+#             */
/*   Updated: 2017/03/25 20:03:28 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define CDERR_0		"cd : %s: No such file or directory"
#define CDERR_1		"cd : %s: Permission denied"
#define CDERR_2		"cd : %s: Not a directory"
#define CDERR_3		"cd : unable to proceed: %s"

int			bt_cd_process_dotdot(char *target)
{
	DG();
	if (access(target, F_OK))
		return (SH_ERR(CDERR_0, target));
	if (access(target, X_OK))
		return (SH_ERR(CDERR_1, target));
	if (!is_directory(target))
		return (SH_ERR(CDERR_2, target));
	if (chdir(target))
		return (SH_ERR(CDERR_3, target));
	setwd("PWD");
	return (0);	
}
