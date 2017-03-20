/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 15:41:59 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/20 15:42:13 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H

# define FT_WS(x) (x == ' ' || x == '\t' || x == '\n')
# define FT_ABS(x) (((x) < 0) ? -(x) : (x))
# define FT_NEG(x) ((x) < 0)
# define FT_POS(x) ((x) > 0)
# define FT_MIN(a, b) ((a) < (b) ? (a) : (b))
# define FT_MAX(a, b) ((a) > (b) ? (a) : (b))
# define FT_DIST(a, b) FT_ABS((a) - (b))

char	*ft_itoa(int n);
char	*ft_itoa_base(int nbr, char *base, char *flags);
char	*ft_lltoa_base(long long nbr, char *base, char *flags);
char	*ft_ulltoa_base(unsigned long long nbr, char *base);
char	*ft_uitoa_base(unsigned int nbr, char *base);
size_t	ft_ilen(int n);
size_t	ft_ilen_base(int n, int base);
size_t	ft_uilen(unsigned int n);
size_t	ft_lllen(long long n);
size_t	ft_lllen_base(long long n, int base);

int		ft_addrcmp(void *a, void *b);
void	*id(void *data);

#endif
