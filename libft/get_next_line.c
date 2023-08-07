/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafay <tlafay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:14:33 by tlafay            #+#    #+#             */
/*   Updated: 2022/02/02 11:48:23 by tlafay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

/***
	This function finds the first occurence of \n and returns the address.
	Else, it returns NULL.
***/

static char	*ft_strstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (&str[i + 1]);
		i++;
	}
	return (NULL);
}

/***
	Saving a few lines every time I free. 
	Checks if str exists, and also sets it NULL.
***/

void	ft_free2(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
}

/***
	Copies a string until \n included.
	Mallocs a new chain and frees the last one.
***/

static char	*ft_copy(char *str)
{
	char	*ret;
	int		i;

	ret = (char *)ft_xmalloc(ft_strlen(str) + 1);
	i = 0;
	while (str[i] != '\n')
	{
		ret[i] = str[i];
		i++;
	}
	if (str[i])
	{
		ret[i] = '\n';
		ret[i + 1] = '\0';
	}
	else
		ret[i] = '\0';
	ft_free2(str);
	return (ret);
}

/*** 
	 The reading function. Copying what's left from last use,
	 appending buffer at the line (ultimately returned in main)
	 while we don't find a newline, truncating everything before the \n 
 	 and putting everything after it in save. 
***/

static char	*ft_read(char *save, char **line, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		red;

	*line = ft_strdup(save);
	while (!ft_strstr(*line))
	{
		red = read(fd, buffer, BUFFER_SIZE);
		buffer[red] = '\0';
		if (red <= 0)
			return (NULL);
		*line = ft_strjoin2(*line, buffer);
	}
	ft_strcpy2(save, ft_strstr(*line));
	*line = ft_copy(*line);
	return (save);
}

/***
	The main function. Checks for potential errors, copies ft_read in save
	and returns line if it is filled, else returns NULL and frees line.
***/

char	*get_next_line(int fd)
{
	static char	save[BUFFER_SIZE + 1];
	char		*line;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_strcpy2(save, ft_read(save, &line, fd));
	if (line[0])
		return (line);
	else
	{
		ft_free2(line);
		return (NULL);
	}
}
