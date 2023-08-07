CC = gcc

NAME := minishell

CFLAGS := -Wall -Wextra -Werror

SRCS := cmd_redirect.c built_in_t.c ft_parsing.c ft_check_fonc.c ft_strjoin.c \
		ft_echo.c minishell.c command_exec.c main.c ft_variable.c \
		ft_random_fc.c ft_export.c ft_init_env.c ft_unset.c ft_redirect.c \
		ft_exit.c buff_pipe.c ft_redirect_pipe.c ft_chevron_check_var.c ft_xmalloc.c \
		ft_here_doc.c

OBJS := ${SRCS:.c=.o}

OBJDIR := $(addprefix obj/, $(OBJS))

INCLUDES := includes/minishell.h ./libft/libft.h

all : libft $(NAME)

$(NAME) : $(OBJDIR)
	echo "\x1b[34m $1[Compiling minishell]\x1b[0m"
	$(CC) -lreadline -L ~/.brew/opt/readline/lib -I ~/.brew/opt/readline/include -lncurses libft/libft.a $(OBJDIR) -o $(NAME) $(CFLAGS)
	echo "\x1b[34m $1[Done]\x1b[0m"

libft : 
	$(MAKE) -C ./libft

obj/%.o : src/%.c libft/libft.a $(INCLUDES) Makefile
	mkdir -p obj
	$(CC) -c $< -I libft -I includes $(CFLAGS) -o $@

clean :
	$(MAKE) -C ./libft $@
	$(RM) $(OBJDIR)

fclean : clean
	$(MAKE) -C ./libft $@
	$(RM) $(NAME) 

re : fclean all

.PHONY : all clean fclean re libft
.SILENT:
