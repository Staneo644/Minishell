/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_fonc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajossera <ajossera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 22:35:42 by ajossera          #+#    #+#             */
/*   Updated: 2022/02/22 18:41:24 by ajossera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit(char *str)
{
	write(1, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

char	*ft_strfree(char *a)
{
	if (a)
		free(a);
	a = NULL;
	return (a);
}

char	**ft_add_cmd(char *str, char **cmd)
{
	int		i;
	char	**ret;

	i = 0;
	if (cmd)
	{
		while (cmd[i])
			i++;
	}
	ret = ft_xmalloc(sizeof(char **) * (i + 2));
	if (!ret)
		return (NULL);
	i = 0;
	while (cmd && cmd[i])
	{
		ret[i] = cmd[i];
		i++;
	}
	ret[i] = str;
	ret[i + 1] = NULL;
	free(cmd);
	return (ret);
}
