/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 17:24:23 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/21 16:33:01 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYS_H
# define SYS_H

# define FT_XATTR_SIZE	10000
# define STDIN			STDIN_FILENO
# define STDOUT			STDOUT_FILENO
# define STDERR			STDERR_FILENO
# define STDBUG			3

# define PIPE_READ		0
# define PIPE_WRITE		1

# include <sys/types.h>
# include <sys/xattr.h>

int		ft_xattr_print(char *path);
int		ft_xattr_count(char *path);
char	*ft_getenv(char **env, char *key);
int		dup2_close(int fd1, int fd2);
int		fd_replace(int fd1, int fd2);

#endif
