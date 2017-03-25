/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_dgreat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 22:07:37 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/25 01:54:05 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		redirect_dgreat(t_redir *redir)
{
	int		fdold;
	int		fdnew;

	fdnew = redir->n;
	if ((fdold = open_access(redir->word, R_OK,
					O_WRONLY | O_CREAT | O_APPEND, 0644)) < 0)
		return (ft_perror(NULL));
	dup2(fdold, fdnew);
	return (0);
}
