NAME = fractol

all: $(NAME)

SRCS = ./srcs/colors.c ./srcs/events.c ./srcs/fix_fractal.c ./srcs/initial.c ./srcs/julia_fractal.c ./srcs/main.c ./srcs/man.c ./srcs/mouse_event.c ./srcs/square.c ./srcs/zoom.c ./srcs/thread_fix.c ./srcs/thread_julia.c
FLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a

$(NAME):
	@make -C libft
	@gcc -I /usr/local/Include $(SRCS) -Wall -Wextra -Werror $(LIBFT) -o $(NAME) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

clean:
	@make -C libft/ clean
fclean: clean
	@make -C libft/ fclean
	@rm -rf $(NAME)

re: fclean all
