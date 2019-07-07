/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 20:19:31 by wtorwold          #+#    #+#             */
/*   Updated: 2019/07/03 16:14:18 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;

}				t_list;

void			ft_bzero(void *s, size_t n);
void			*ft_memccpy
				(void *dest, const void *src, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memset (void *b, int c, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t len);
char			*ft_strncpy(char *dest, const char *src, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strcat(char *dst, const char *src);
char			*ft_strncat(char *dst, const char *src, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
int				ft_memcmp(const void *a, const void *b, size_t n);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr
				(const char *haystack, const char *needle, size_t len);
int				ft_atoi(const char *str);
int				ft_strcmp(const char *a, const char *b);
int				ft_strncmp(const char *a, const char *b, size_t n);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			*ft_memalloc(size_t size);
char			*ft_strnew(size_t size);
void			ft_strclr(char *arr);
void			ft_striter(char *str, void (*f)(char *));
void			ft_striteri(char *str, void (*f)(unsigned int, char *));
char			*ft_strmap(const char *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strtrim(char const *s);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putnbr(long long n);
char			*ft_itoa(int n);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_countword(char const *str, char c);
char			**ft_strsplit(char const *str, char c);
char			**ft_arrsplit(char const *str, int count, char **arr, char c);
char			*ft_arrmem(char const *str, int index, char c);
void			ft_memdel(void **ap);
void			ft_strdel(char **as);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
int				ft_countdigit(long long dig);
int				ft_strindex(const char *str, int c);

#endif
