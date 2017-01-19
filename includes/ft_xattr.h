/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftxattr.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:24:05 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/07 13:24:05 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_XATTR_H
# define FT_XATTR_H
# define FT_XATTR_SIZE 10000
# include <sys/types.h>
# include <sys/xattr.h>

int		ft_xattr_print(char *path);
int		ft_xattr_count(char *path);
#endif
