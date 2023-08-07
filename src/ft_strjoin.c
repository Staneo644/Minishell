/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajossera <ajossera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 22:25:52 by ajossera          #+#    #+#             */
/*   Updated: 2022/02/22 18:40:31 by ajossera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_complete(char *a, char *b, char *rend)
{
	int	i;
	int	j;

	i = 0;
	while (a && a[i])
	{
		rend[i] = a[i];
		i++;
	}
	j = 0;
	while (b && b[j])
	{
		rend[i + j] = b[j];
		j++;
	}
	rend[i + j] = '\0';
	return (rend);
}

char	*ft_str(char *a)
{
	char	*rend;
	int		i;

	i = 0;
	while (a && a[i])
		i++;
	rend = ft_xmalloc(sizeof(char) * (i + 1));
	i = 0;
	while (a && a[i])
	{
		rend[i] = a[i];
		i++;
	}
	rend[i] = 0;
	return (rend);
}

char	*ft_strfjoin(char *s1, char *s2)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup((char *)s2));
	if (!s2)
		return (ft_strdup((char *)s1));
	ret = (char *)ft_xmalloc((ft_strlen(s1)
				+ ft_strlen(s2) + 1) * sizeof(char));
	ft_complete(s1, s2, ret);
	ft_strfree(s1);
	return (ret);
}

char	*ft_strjoinf(char *s1, char *s2)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup((char *)s2));
	if (!s2)
		return (ft_strdup((char *)s1));
	ret = (char *)ft_xmalloc((ft_strlen(s1)
				+ ft_strlen(s2) + 1) * sizeof(char));
	ft_complete(s1, s2, ret);
	free(s2);
	return (ret);
}

char	*ft_strffjoin(char *s1, char *s2)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup((char *)s2));
	if (!s2)
		return (ft_strdup((char *)s1));
	ret = (char *)ft_xmalloc((ft_strlen(s1)
				+ ft_strlen(s2) + 1) * sizeof(char));
	if (!ret)
	{
		ft_strfree(s2);
		return (ft_strfree(s1));
	}
	ft_complete(s1, s2, ret);
	ft_strfree(s1);
	ft_strfree(s2);
	return (ret);
}
