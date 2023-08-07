/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafay <tlafay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:52:35 by tlafay            #+#    #+#             */
/*   Updated: 2022/02/22 14:28:40 by tlafay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstadd_back(t_list **alst, t_list *new);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **alst, t_list *new);
int				ft_lstsize(t_list *lst);
int				ft_isalnum(int c);
int				ft_strlen(const char *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
int				ft_atoi(const char *str);
void			ft_bzero(void *s, int n);
void			*ft_calloc(int count, int size);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
char			*ft_itoa(int n);
void			*ft_memchr(void *str, int c, int size);
int				ft_memcmp(void *p1, void *p2, size_t size);
void			*ft_memcpy(void *dest, const void *src, size_t size);
void			*ft_memmove(void *dest, void *src, int size);
void			*ft_memset(void *pointer, int value, int count);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			*ft_strchr(const char *str, int search);
char			*ft_strdup(char *src);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
size_t			ft_strlcat(char *dest, const char *src, size_t size);
unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size);
int				ft_strncmp(const char *s1, const char *s2, unsigned int n);
char			*ft_strnstr(const char *str, const char *search, size_t len);
char			*ft_strrchr(char *str, int search);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			*ft_xmalloc(int size);
#endif
