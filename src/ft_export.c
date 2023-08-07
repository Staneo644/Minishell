/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafay <tlafay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:43:51 by ajossera          #+#    #+#             */
/*   Updated: 2022/02/23 16:57:08 by tlafay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	export_no_args(t_list **env)
{
	t_list	*tmp;
	char	**splitted;

	tmp = *env;
	while (tmp)
	{
		if (ft_strchr(tmp->content, '='))
		{
			splitted = ft_split(tmp->content, '=');
			if (!splitted[1])
				splitted[1] = ft_strdup("");
			printf("declare -x %s=\"%s\"\n", splitted[0], splitted[1]);
			free(splitted[0]);
			free(splitted[1]);
			free(splitted);
		}
		else
			printf("declare -x %s\n", tmp->content);
		tmp = tmp->next;
	}
}

int	is_an_env(char *str, t_list *env)
{
	t_list	*tmp;
	char	*cut;

	tmp = env;
	while (tmp)
	{
		cut = ccut(tmp->content, '=');
		if (ft_strncmp(cut, str, ft_strlen(str)) == 0
			&& ft_strlen(cut) == ft_strlen(str))
		{
			free(str);
			free(cut);
			return (1);
		}
		free(cut);
		tmp = tmp->next;
	}
	free(str);
	return (0);
}

t_list	*ft_export3(char *var, t_list **env, t_list *new)
{
	char	*cut1;
	char	*cut2;

	new = *env;
	while (new)
	{
		cut1 = ccut(var, '=');
		cut2 = ccut(new->content, '=');
		if (!ft_strncmp(cut1, cut2, ft_strlen(var)))
		{
			free(cut1);
			free(cut2);
			break ;
		}
		free(cut1);
		free(cut2);
		new = new->next;
	}
	return (new);
}

void	ft_export2(char *var, t_list **env)
{
	t_list	*new;

	if (export_invalid(ccut(var, '=')))
	{
		printf("minishell : export: `%s': not a valid identifier\n", var);
		g_exit_value = 1;
		return ;
	}
	if (is_an_env(ccut(var, '='), *env))
	{
		new = *env;
		new = ft_export3(var, env, new);
		if (new && ft_strchr(var, '='))
		{
			free(new->content);
			new->content = ft_strdup(var);
		}
	}
	else
	{
		new = ft_lstnew(ft_strdup(var));
		ft_lstadd_back(env, new);
	}
}

void	ft_export(char **var, t_list **env)
{
	int		i;

	if (!var[0])
	{
		export_no_args(env);
		return ;
	}
	i = -1;
	while (var[++i])
		ft_export2(var[i], env);
}
