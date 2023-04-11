NAME	:= so_long
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ./lib/MLX42
LIBFT	:= ./lib/Libft
SO_LONG := ./lib/So_long

HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIBFT) -I $(SO_LONG)
LIBS	:= $(LIBMLX)/build/libmlx42.a $(LIBFT)/libft.a -ldl -lglfw -pthread -lm
SRCS	:=  ./src/main.c \
			./src/logic.c \
			./src/map_validity.c \
			./src/build_map.c \
			./src/load_free.c \
			./src/helpers.c
OBJS	:= ${SRCS:.c=.o}

# $(shell find ./src -iname "*.c")

all: libft libmlx $(NAME)

libft:
	@make -C $(LIBFT)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<) "

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@rm -fr $(LIBMLX)/build
	@make -C ./lib/Libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C ./lib/Libft fclean

re: fclean all

.PHONY: all, clean, fclean, re, libmlx libft
