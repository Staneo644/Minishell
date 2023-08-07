/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafay <tlafay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:38:05 by ajossera          #+#    #+#             */
/*   Updated: 2022/02/22 14:07:02 by tlafay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*ft_shlvl2(char *envp)
{
	t_list	*tmp;
	char	*stritoa;

	if (atoi_error(envp + 6))
		tmp = ft_lstnew(ft_strdup("SHLVL=1"));
	else if (ft_atoi(envp + 6) < 0)
		tmp = ft_lstnew(ft_strdup("SHLVL=0"));
	else if (ft_atoi(envp + 6) >= 1000)
	{
		tmp = ft_lstnew(ft_strdup("SHLVL=1"));
		printf("minishell: warning: shell level ");
		printf("(%d)", ft_atoi(envp + 6) + 1);
		printf(" too high, resetting to 1\n");
	}
	else
	{
		stritoa = ft_itoa(ft_atoi(&envp[6]) + 1);
		tmp = ft_lstnew(ft_strjoin("SHLVL=", stritoa));
		free(stritoa);
	}
	return (tmp);
}

void	ft_shlvl(t_list **env, char **envp)
{
	int		i;
	t_list	*tmp;

	i = -1;
	while (envp[++i])
	{
		if (!ft_strncmp("SHLVL=", envp[i], 6))
		{
			tmp = ft_shlvl2(envp[i]);
			break ;
		}
	}
	if (!envp[i])
		tmp = ft_lstnew(ft_strdup("SHLVL=1"));
	tmp->next = *env;
	*env = tmp;
}

void	ft_static_env(t_list **env, char **envp)
{
	t_list	*tmp;
	char	cwd[256];

	if (!getcwd(cwd, sizeof(cwd)))
		perror("minishell: getcwd");
	tmp = ft_lstnew(ft_strjoin("PWD=", cwd));
	tmp->next = *env;
	*env = tmp;
	tmp = ft_lstnew(ft_strdup("OLDPWD"));
	tmp->next = *env;
	*env = tmp;
	ft_shlvl(env, envp);
}

void	ft_init_env(t_list **env, char **envp)
{
	int		i;
	t_list	*tmp;

	ft_static_env(env, envp);
	i = 0;
	while (envp[i])
		i++;
	i--;
	while (i >= 0)
	{
		if (ft_strncmp("PWD=", envp[i], 4)
			&& ft_strncmp("OLDPWD=", envp[i], 7)
			&& ft_strncmp("SHLVL=", envp[i], 6))
		{
			tmp = ft_lstnew(ft_strdup(envp[i]));
			tmp->next = *env;
			*env = tmp;
		}
		i--;
	}
}
