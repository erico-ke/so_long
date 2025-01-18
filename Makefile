NAME = so_long.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

MLX42_PATH = libs/MLX42
MLX42 = $(MLX42_PATH)/build/libmlx42.a

LIBFT_PATH = libs/libft
LIBFT = $(LIBFT_PATH)/libft.a

HEADERS = -I ./libs -I $(MLX42_PATH)/include/MLX42 -I $(LIBFT_PATH)

SRCS =	main.c

OBJS = $(SRCS:%.c=obj/%.o)


all : $(MLX42) $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX42) $(LIBFT) $(HEADERS) -lglfw -o $(NAME) -lm

$(LIBFT):
	make -C $(LIBFT_PATH)

$(MLX42):
	cmake $(MLX42_PATH) -B $(MLX42_PATH)/build && make -C $(MLX42_PATH)/build -j4

obj/%.o: %.c
	mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

clean:
	$(RM) obj
	make -C $(LIBFT_PATH) clean
	make -C $(MLX42_PATH)/build clean

fclean:
	$(RM) obj $(NAME)
	make -C $(LIBFT_PATH) fclean
	$(RM) $(MLX42_PATH)/build

re: fclean all
