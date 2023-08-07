/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafay <tlafay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:35:12 by ajossera          #+#    #+#             */
/*   Updated: 2022/02/23 16:57:15 by tlafay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset3(char *var, t_list **env)
{
	t_list	*tmp;
	t_list	*current;
	char	*c1;
	char	*c2;

	current = *env;
	while (current->next)
	{
		c1 = ccut(current->next->content, '=');
		c2 = ccut(var, '=');
		if (ft_strncmp(c1, c2, ft_strlen(var)) == 0
			&& ft_strlen(c1) == ft_strlen(c2))
		{
			tmp = current->next;
			current->next = current->next->next;
			free(tmp->content);
			free(tmp);
			free(c1);
			free(c2);
			break ;
		}
		free(c1);
		free(c2);
		current = current->next;
	}
}

void	ft_unset2(char *var, t_list **env)
{
	t_list	*tmp;
	char	*c1;
	char	*c2;

	c1 = ccut((*env)->content, '=');
	c2 = ccut(var, '=');
	if (ft_strncmp(c1, c2, ft_strlen(var)) == 0
		&& ft_strlen(c1) == ft_strlen(c2))
	{
		tmp = *env;
		*env = (*env)->next;
		free(tmp->content);
		free(tmp);
	}
	else
		ft_unset3(var, env);
	free(c1);
	free(c2);
}

void	ft_unset(char **var, t_list **env)
{
	int		i;

	i = -1;
	while (var[++i])
	{
		if (export_invalid(ft_strdup(var[i])))
		{
			printf("minishell : unset: `%s': not a valid identifier\n", var[i]);
			g_exit_value = 1;
			continue ;
		}
		ft_unset2(var[i], env);
	}
}

int	export_invalid(char *var)
{
	int	i;

	i = 0;
	if (!ft_isalpha(var[0]) && var[0] != '_')
	{
		free(var);
		return (1);
	}
	while (var[i])
	{
		if (!ft_isalpha(var[i]) && !ft_isdigit(var[i]) && var[i] != '_')
		{
			free(var);
			return (1);
		}
		i++;
	}
	free(var);
	return (0);
}
