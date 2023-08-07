/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajossera <ajossera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:01:11 by tlafay            #+#    #+#             */
/*   Updated: 2022/02/22 18:42:37 by ajossera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <limits.h>
# include <term.h>
# include <curses.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>

# include "libft.h"

extern int	g_exit_value;

typedef struct s_sh
{
	int		is_pipe;
	char	*line;
	char	**argv;
	int		close;
	int		stdout_fd;
	int		stdin_fd;
	int		pipe_fd;
	t_list	*env;
}	t_sh;

void	rl_replace_line(const char *text, int clear_undo);

//ft_strjoin.c//
char	*ft_strfjoin(char *s1, char *s2);
char	*ft_strffjoin(char *s1, char *s2);
char	*ft_str(char *a);
char	*ft_strjoinf(char *s1, char *s2);

//ft_parsing.c//
char	**ft_parsing(char *str, t_list *envp, int i);
int		ft_one_argument(char *str, int i, int nb);

//ft_echo.c//
void	ft_echo(char **argv);

//ft_check_fonc.c//
int		ft_exit(char *str);
char	**ft_add_cmd(char *str, char **cmd);
char	*ft_strfree(char *a);

//ft_export.c//
int		export_invalid(char *var);
void	ft_export(char **var, t_list **env);

//ft_unset.c//
void	ft_unset(char **var, t_list **env);

//ft_init_env.c//
void	ft_init_env(t_list **env, char **envp);

//ft_built_in_t.c//
void	ft_env(t_list *env);
void	ft_cd(char *dir, t_list **env);
void	ft_pwd(void);

//test.c//
char	*ft_change_arg(char *str);
int		ft_redirect_cmd(t_sh *sh, char **cmd, int j);
void	sigquit(int sig);

//minishell.c//
int		ft_make_cmd(char **argv, t_sh *sh, int *i, int j);

//ft_redirect_pipe.c//
int		ft_redirect_pipe(char **argv, t_sh *sh);

//command_test.c//
int		command_exec(char **cmd, char **envp, int fd);
char	**strstrcpy(char **str);

//buff_pipe.c//
int		ft_pipe(int fd, int end);
char	**list_to_buf(t_list *env);

//ft_heredoc.c//
int		heredoc(char *delimiter, int stdout_fd, int stdin_fd, t_list *env);

//ft_redirect.c//
int		redirect_in(char *filein);
int		redirect_out(char *fileout);
int		redirect_out_append(char *fileout);

//random_fc.c//
char	*ccut(char *str, char c);
int		atoi_error(char *str);
int		ft_free(char **str);
int		ft_all_space(char *str);
int		strstrlen(char **str);

//ft_variable.c//
int		ft_variable(int i, char **str, t_list *envp);
char	*ft_all_variable(char *str, t_list *envp, int i);

//ft_chevron_check_var.c//
int		ft_have_problem(int i, char **str);
int		ft_check_variable(int i, char **str);
char	*ft_change_chevron(char *str, int pj);

//ft_exit.c//
void	ft_exit2(char **arg, t_sh *sh);

int		ft_free_one(char *str);

void	*ft_xmalloc(int size);

#endif
