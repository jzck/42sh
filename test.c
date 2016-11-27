/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 21:15:49 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/27 23:50:57 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"

extern char	**environ;

#define PIPE_READ	0
#define PIPE_WRITE	1
#define STDIN		0
#define STDOUT		1

int		main(void)
{
	pid_t	pid;
	int		fds[2];

	pipe(fds);
	if ((pid = fork()) == 0)
	{
		/* child */
		dup2(fds[PIPE_WRITE], STDOUT);
		/* close(fds[PIPE_READ]); */
		/* close(fds[PIPE_WRITE]); */
		execv("/bin/ls", (char*[2]){"/bin/ls"});
	}
	else
		wait(NULL);
	close(fds[PIPE_WRITE]);
	if ((pid = fork()) == 0)
	{
		/* parent */
		dup2(fds[PIPE_READ], STDIN);
		/* close(fds[PIPE_READ]); */
		execv("/usr/bin/wc", (char*[2]){"/usr/bin/wc", "-l"});
	}
	else
		wait(NULL);
	close(fds[PIPE_WRITE]);
	close(fds[PIPE_READ]);
}
