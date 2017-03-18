/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:49:04 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/18 19:08:44 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <sys/xattr.h>
# include <sys/acl.h>

# include "error.h"
# include "color.h"
# include "cliopts.h"

# include "lst.h"
# include "dlst.h"
# include "btree.h"

# include "str.h"
# include "sstr.h"
# include "math.h"
# include "mytime.h"
# include "get_next_line.h"
# include "sys.h"

typedef struct s_stos	t_stos;
typedef struct s_stof	t_stof;
typedef struct s_itof	t_itof;

struct	s_stos
{
	char	*key;
	char	*val;
};

struct	s_stof
{
	char	*name;
	int		(*f)();
};

struct	s_itof
{
	int			id;
	int			(*f)();
};

int		ft_printf(const char *format, ...);
int		ft_dprintf(int fd, const char *format, ...);
int		ft_vdprintf(int fd, const char *format, va_list ap);
int		ft_asprintf(char **ret, const char *format, ...);
int		ft_vasprintf(char **ret, const char *format, va_list ap);

void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);

int		ft_putchar(int c);
void	ft_putstr(char const *s);
void	ft_putendl(char const *s);
void	ft_putnbr(long n);
void	ft_putnbr_hex(long n);

int		ft_error_message(char *message);

int		ft_putchar_fd(int c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr_fd(long n, int fd);
void	ft_putnbr_hex_fd(long n, int fd);

void	*ft_realloc(void *data, int size);

#endif
