SRCS_cub3d = cub3d.c log_errors/error.c file/file_read2.c \
ft_initialize.c keys_set.c file/file_check.c \
file/file_read.c raycasting/raycasting.c \
raycasting/wall.c helper/math_functions.c raycasting/player.c raycasting/texture.c raycasting/sprite.c \
screan/screenshot.c helper/free.c raycasting/collision.c file/fill_map.c \

SRCS_utils = utils/ft_strdup.c utils/ft_substr.c utils/ft_strjoin.c utils/ft_putstr_fd.c \
utils/ft_strlen.c utils/ft_strncmp.c utils/ft_strlcpy.c \
utils/ft_isdigit.c utils/ft_putchar_fd.c utils/ft_strnstr.c utils/ft_atoi.c \
utils/get_next_line.c utils/ft_strjoin_free.c  utils/ft_strchr.c utils/ft_split.c \
utils/ft_memcmp.c utils/ft_memcpy.c utils/ft_strtrim.c\

SRCS = ${SRCS_cub3d} ${SRCS_utils}

INCL = -Iincludes/

OBJS = ${SRCS:.c=.o}

NAME = cub3D

FLAGS = -Wall -Wextra -Werror -g

all : $(NAME)
		@echo "successfully made :-)"

$(NAME) : ${OBJS}
		@gcc  ${FLAGS} -I/usr/local/include -o$(NAME) ${OBJS} -L/usr/local/lib -lmlx -framework Opengl -framework APPKIT -O3

.c.o : ${SRCS}
		@gcc ${FLAGS} -c ${INCL} $< -o ${<:.c=.o}
clean :
		@rm -f ${OBJS}

fclean : clean
		@rm -f $(NAME)

re : fclean
		@make all

.PHONY: all clean fclean re
