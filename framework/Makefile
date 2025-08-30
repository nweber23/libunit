
NAME	=	libunit.a
CC		=	cc
AR		=	ar
CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	load_test.c \
			launch_tests.c \
			utils_print.c \
			utils_counter.c
OBJS	=	$(addprefix obj/, $(SRCS:.c=.o))

LIBFT	=	../libft/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	cd ../libft && $(MAKE) bonus

$(NAME): $(OBJS)
	$(AR) rcs $(NAME) $(OBJS)

obj/%.o: %.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf obj/

fclean: clean
	rm -rf $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all
