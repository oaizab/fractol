SRCS	=	ft_isprint.c			ft_putchar_fd.c			ft_strjoin.c			ft_strtrim.c			ft_substr.c		\
			ft_atoi.c				ft_itoa.c				ft_putendl_fd.c			ft_strlcat.c			ft_bzero.c		\
			ft_putnbr_fd.c			ft_strlcpy.c			ft_tolower.c			ft_calloc.c				ft_memchr.c		\
			ft_putstr_fd.c			ft_strlen.c				ft_toupper.c			ft_isalnum.c			ft_memcmp.c		\
			ft_split.c				ft_strmapi.c			ft_isalpha.c			ft_memcpy.c				ft_strchr.c		\
			ft_strncmp.c			ft_strrchr.c			ft_isascii.c			ft_memmove.c			ft_strdup.c		\
			ft_strnstr.c			ft_isdigit.c			ft_memset.c				ft_striteri.c			get_next_line.c
ODIR	=	obj
OBJS	=	$(addprefix $(ODIR)/,$(SRCS:.c=.o))
BONUS	=	ft_lstadd_back_bonus.c	ft_lstclear_bonus.c		ft_lstiter_bonus.c		ft_lstmap_bonus.c	ft_lstsize_bonus.c	\
			ft_lstadd_front_bonus.c	ft_lstdelone_bonus.c	ft_lstlast_bonus.c		ft_lstnew_bonus.c
BOBJS	=	$(addprefix $(ODIR)/,$(BONUS:.c=.o))
IDIR	=	inc
INCL	=	libft.h
HEADER	=	$(addprefix $(IDIR)/,$(INCL))
NAME	=	libft.a
CC		=	cc
RM		=	rm -rf
CFLAGS	=	-Wall -Wextra -Werror
AR		=	ar rcs
SDIR	=	src
OUTPUT	=	lib

# ----------------------------------------------------------------------------

all:		$(NAME) bonus

$(ODIR)/%.o: $(SDIR)/%.c $(HEADER)
			@mkdir -p $(@D)
			@$(CC) $(CFLAGS) -I$(IDIR) -c $< -o $@

$(NAME):	$(OBJS)
			@mkdir -p $(OUTPUT)
			@$(AR) $(OUTPUT)/$(NAME) $(OBJS)

bonus:		$(BOBJS)
			@$(AR) $(OUTPUT)/$(NAME) $(BOBJS)

clean:
			@$(RM) $(OBJS) $(BOBJS) $(ODIR) 

fclean:		clean
			@$(RM) $(OUTPUT)/$(NAME) $(OUTPUT)

re:			fclean all

.PHONY:		all clean fclean re test bonus