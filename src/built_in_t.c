/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_t.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafay <tlafay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:06:17 by tlafay            #+#    #+#             */
/*   Updated: 2022/02/22 17:09:37 by tlafay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_list *env)
{
	t_list	*tmp;

	tmp = env;
	while (tmp)
	{
		if (ft_strchr(tmp->content, '='))
			printf("%s\n", tmp->content);
		tmp = tmp->next;
	}		
}

static void	ft_cd2(char *oldpwd, char *cwd, t_list **env, char *dir)
{
	t_list	*tmp;

	if (!dir)
		return ;
	free(dir);
	tmp = *env;
	if (!oldpwd)
		oldpwd = "PWD=";
	while (tmp)
	{
		if (!ft_strncmp("PWD=", tmp->content, 4))
		{
			free(tmp->content);
			tmp->content = ft_strjoin("PWD=", cwd);
		}
		if ((!ft_strncmp("OLDPWD", tmp->content, 7)
				&& ft_strlen(tmp->content) == 6)
			|| !ft_strncmp("OLDPWD=", tmp->content, 7))
		{
			free(tmp->content);
			tmp->content = ft_strjoin("OLD", oldpwd);
		}
		tmp = tmp->next;
	}
}

char	*ft_cd_noargs(t_list **env, char *dir)
{
	t_list	*tmp;
	char	**splitted;
	char	*ret;

	if (dir)
		return (ft_strdup(dir));
	tmp = *env;
	while (tmp)
	{
		splitted = ft_split(tmp->content, '=');
		if (!ft_strncmp("HOME", splitted[0], 5))
		{	
			ret = ft_strdup(splitted[1]);
			ft_free(splitted);
			return (ret);
		}
		ft_free(splitted);
		tmp = tmp->next;
	}
	ft_putstr_fd("minishell: cd: HOME not set\n", 2);
	return (NULL);
}

void	ft_cd(char *dir, t_list **env)
{
	t_list	*tmp;
	char	*oldpwd;
	char	cwd[256];

	dir = ft_cd_noargs(env, dir);
	if (dir && chdir(dir) == -1)
	{
		g_exit_value = 1;
		perror("minishell: cd");
	}
	if (dir && !getcwd(cwd, sizeof(cwd)))
	{
		g_exit_value = 1;
		perror("minishell: getcwd");
	}
	tmp = *env;
	oldpwd = NULL;
	while (dir && tmp)
	{
		if (!ft_strncmp("PWD=", tmp->content, 4))
			oldpwd = tmp->content;
		tmp = tmp->next;
	}
	ft_cd2(oldpwd, cwd, env, dir);
}

void	ft_pwd(void)
{
	char	cwd[256];

	if (!getcwd(cwd, sizeof(cwd)))
	{
		perror("minishell: pwd");
		g_exit_value = 1;
	}
	else
		printf("%s\n", cwd);
}
