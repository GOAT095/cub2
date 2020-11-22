SRCS_cub3d = cub3d.c log_errors/error.c file/file_read2.c \
ft_initialize.c keys_set.c file/file_check.c \
file/file_read.c raycasting/raycasting.c \
raycasting/wall.c helper/math_functions.c raycasting/player.c raycasting/texture.c raycasting/sprite.c \
screan/screenshot.c helper/free.c raycasting/collision.c file/fill_map.c \

SRCS_libft = libft/ft_strdup.c libft/ft_substr.c libft/ft_strjoin.c libft/ft_putstr_fd.c \
libft/ft_strlen.c libft/ft_strncmp.c libft/ft_strlcpy.c \
libft/ft_isdigit.c libft/ft_putchar_fd.c libft/ft_strnstr.c libft/ft_atoi.c \
libft/get_next_line.c libft/ft_strjoin_free.c  libft/ft_strchr.c libft/ft_split.c \
libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_strtrim.c\

SRCS = ${SRCS_cub3d} ${SRCS_libft}

INCL = -Iincludes/

OBJS = ${SRCS:.c=.o}

NAME = cub3D

FLAGS = -Wall -Wextra -Werror -g

all : $(NAME)
		@echo "successfully made :-)"

$(NAME) : ${OBJS}
		gcc  ${FLAGS} -I/usr/local/include -o$(NAME) ${OBJS} -L/usr/local/lib -lmlx -framework Opengl -framework APPKIT 

.c.o : ${SRCS}
		gcc ${FLAGS} -c ${INCL} $< -o ${<:.c=.o}
clean :
		rm -f ${OBJS}

fclean : clean
		rm -f $(NAME)

re : fclean
		make all

.PHONY: all clean fclean re
