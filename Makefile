SDIR	=	src
SRCS	=	main.c events.c images.c colors.c init.c \
			fractals/mandelbrot.c fractals/julia.c \
			complex.c manupilation.c fractals/burning_ship.c \
			fractals/multi_mandelbrot.c

ODIR	=	obj
OBJS	=	$(addprefix $(ODIR)/,$(SRCS:.c=.o))

IDIR	=	inc
INCL	=	fractol.h ft_mlx_keys.h

CFLAGS	=	-Wall -Wextra -Werror
NAME	=	fractol
HEADER	=	$(addprefix $(IDIR)/,$(INCL))

OUTPUT	=	./

CC		=	cc

LIBS	=	-L/usr/local/lib -lmlx -Llibft/lib -lft -framework OpenGL -framework AppKit

INCLUDE	=	-I/usr/local/include -I$(IDIR) -Ilibft/inc

all: $(NAME)

run: all
	@$(OUTPUT)/$(NAME)

$(ODIR)/%.o: $(SDIR)/%.c $(HEADER)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS)
	@make -C libft
	$(CC) $(OBJS) $(LIBS) -o $(OUTPUT)/$(NAME)

clean:
	@make -C libft clean
	@rm -rf $(ODIR)

fclean: clean
	@make -C libft fclean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re run
