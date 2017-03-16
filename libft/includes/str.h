/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 13:05:53 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/07 11:36:58 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

size_t	ft_strlen(const char *s);
size_t	ft_strlenchr(const char *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_strdupchr(const char *str, char c);
char	*ft_strduptr(char *str, int (*is)(int c));
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strchrcpy(char *dst, const char *str, char c);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strncat(char *s1, const char *s2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *big, const char *little);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);

char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
void	ft_strclr(char *s);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s);
char	**ft_strsplit(char const *s, char c);

char	*ft_strrev(char *str);
char	**ft_strsplit(char const *s, char c);
char	*ft_str3join(char const *s1, char const *s2, char const *s3);
char	*ft_strcut(char *str, char *cut);
char	**ft_split_whitespaces(char const *str);
char	*ft_convert_base(
		char *str, char *base_from, char *base_to, char *flags);
char	*ft_strcatf(char *s1, const char *s2);
char	*ft_strinsert(char *str, char c, int n);
int		ft_strappend(char **dst, char *src);
char	*ft_strbetween(char *start, char *end);
char	*ft_strreplace(char **str, char *start, char *end, char *new);
char	*ft_strtok(char *s, const char *delim);
size_t	ft_strcspn(char *s, const char *delim);

char	*ft_path_notdir(char *path);
int		ft_stris(char *str, int (*f)());

#endif
