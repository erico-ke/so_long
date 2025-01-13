NAME = so_long.a
CC = cc
FLAGS = -Wall -Wextra -Werror
SRC = main.c

LIBFT = ./libft/libft.a

all: $(OBJDIR) $(NAME)

$(LIBFT):
	@ make -C ./libft

MLX42_PATH = ./MLX42
MLX42 = ./MLX42/build/libmlx42.a

OBJDIR = obj/

OBJECTS = $(SRC:%.c=%.o)

$(OBJDIR):
	mkdir -p $@
	
$(OBJECTS)%.o: $(SRC)
	$(CC) -c $(CFLAGS) $< -o $@
	
$(NAME): $(OBJECTS) $(LIBFT)
	$(AR) -r $@ $?
	$(CC) $(FLAGS) $@ $(MLX42) $(LIBFT) $(LIB_SYS)

$(MLX42):
	cmake $(MLX42_PATH) -B $(MLX42_PATH)/build && make -C $(MLX42_PATH)/build -j4

		
clean:
	rm -rf $(OBJECTS)
	make -C ./libft clean
	make -C ./MLX42/build clean

fclean:
	rm -rf $(NAME)
	make -C ./libft fclean

re : fclean all
