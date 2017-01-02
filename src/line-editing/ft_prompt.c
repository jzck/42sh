/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:22:34 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/02 18:19:24 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

int		ft_prompt(void)
{
	DG("do_job_notification() before prompt");
	do_job_notification();
	DG("new prompt now");
	ft_putstr(SHELL_PROMPT);
	return (0);
}
