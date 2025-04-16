CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
LDFLAGS = -lX11 -lXext -lmlx

TARGET = fractol

SRC = destroy_julia.c destroy_mandelbrot.c hooks_julia.c hooks_mandelbrot.c \
      julia.c main.c mandelbrot.c math.c scaling.c utils.c zoom.c handler.c sanitize.c

OBJ = $(SRC:%.c=%.o)

all: $(TARGET)

$(TARGET): $(OBJ) fractol.h
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

clean:
	rm -rf *.o

fclean: clean
	rm -f $(TARGET)

re: fclean all


.PHONY: all clean fclean re 

.SECONDARY:

