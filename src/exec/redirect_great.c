/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_great.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 22:03:53 by jhalford          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2017/03/24 16:58:17 by jhalford         ###   ########.fr       */
=======
/*   Updated: 2017/03/24 17:22:28 by gwojda           ###   ########.fr       */
>>>>>>> db98f2f1bcbfc8738908b02fd327e30e18e37f88
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		redirect_great(t_redir *redir)
{
	int		fdold;
	int		fdnew;

	fdnew = redir->n;
	if ((fdold = open(redir->word,
					O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0)
		exit(1);
	dup2_close(fdold, fdnew);
	return (0);
}
