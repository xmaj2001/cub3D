NAME = cub3D

LIBFT = ./libft
LIBMLX = ./minilibx-linux

SRC_DRAW = src/draw/draw.ui.c src/draw/draw.minimap.c src/draw/add.textures.c src/draw/init.textures.c src/draw/draw.background.c src/draw/load.texture.c src/draw/draw.square.c src/draw/print.image.c src/draw/free_textures.c src/draw/put.pixel.c src/draw/get.color_texture.c src/draw/update.background.c src/draw/init.background.c
SRC_ERROR = src/error/error.texture.c
SRC_MAP = src/map/error.c src/map/handling_map3.c src/map/freing.c src/map/handling_map4.c src/map/ft_split.c src/map/handling_map5.c src/map/get_game_ready.c src/map/handling_map.c src/map/get_next.c src/map/handling_map_helper.c src/map/handling_map0.5.c src/map/init.map.c src/map/handling_map1.c src/map/handling_map2.c
SRC_PLAYER = src/player/player.c  src/player/player.keypress.c src/player/player.move.c
SRC = src/init.c src/wall.c src/frame.c src/sprite.c  src/main.c src/system.c src/utils.c src/raycast.c src/raycast.utils.c src/vector.c $(SRC_DRAW) $(SRC_ERROR) $(SRC_MAP) $(SRC_PLAYER)

OBJ = $(SRC:.c=.o)

FLAGS =
CC = cc

all: $(NAME)

dev:
	$(CC) $(FLAGS) $(SRC) -o $(NAME) $(LIBFT)/libft.a -L$(LIBMLX) -lmlx -lXext -lX11 -lm

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT)/libft.a -L$(LIBMLX) -lmlx -lXext -lX11 -lm

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	rm -f $(NAME)

re: fclean all

run: fclean all
	$(MAKE) clean

