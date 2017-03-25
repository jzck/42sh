/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_cd_process_dotdot.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 03:54:22 by ariard            #+#    #+#             */
/*   Updated: 2017/03/25 19:44:50 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define CDERR_6	"cd : %s: Permission denied"
#define CDERR_7 "cd : %s: No such file or directory"

int			bt_cd_process_dotdot(char *target)
{
	if (!is_directory(target))
		return (SH_ERR(CDERR_7, target));
	if (access(target, R_OK) < 0)
		return (SH_ERR(CDERR_6, target));
	if (chdir(target))
		return (SH_ERR(CDERR_7, target));
	setwd("PWD");
	return (0);	
}
