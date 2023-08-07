/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafay <tlafay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:41:17 by tlafay            #+#    #+#             */
/*   Updated: 2022/02/02 11:48:02 by tlafay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

char	*ft_strjoin2(char *s1, char *s2);
char	*ft_strdup(char *src);
int		ft_strlen(const char *str);
void	ft_free2(char *str);
char	*get_next_line(int fd);
void	ft_strcpy2(char *s1, char *s2);

#endif
