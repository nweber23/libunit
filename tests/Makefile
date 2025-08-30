MAKEFLAGS +=	-s
NAME	=	unit_test
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	main.c \
			ft_bus_error.c \
			dummy/00_launcher.c \
			dummy/01_ok_test.c \
			dummy/02_ko_test.c \
			dummy/03_sigsegv_test.c \
			dummy/04_bus_error_test.c \
			dummy/05_abort_test.c

OBJS	=	$(addprefix obj/, $(SRCS:.c=.o))

LIBFT	=	../libft/libft.a
LIBUNIT	=	../framework/libunit.a

all: $(LIBFT) $(LIBUNIT) $(NAME)

$(LIBFT):
	cd ../libft && $(MAKE) bonus

$(LIBUNIT):
	cd ../framework && $(MAKE)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBUNIT) $(LIBFT) -o $(NAME)

obj/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf obj/

fclean: clean
	rm -rf $(NAME)
	cd ../libft && $(MAKE) fclean
	cd ../framework && $(MAKE) fclean

re:
	$(MAKE) fclean
	$(MAKE) all

test: all
	@./$(NAME)