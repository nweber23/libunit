
# unit_test, run_tests
NAME	=	unit_test
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

VPATH	=	./ \
			ft_isalpha/

SRCS	=	main.c \
			00_launcher.c \
			01_basic_test.c \
			02_failed_test.c

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
	@echo "================================================================================\n"

obj/%.o: %.c
	@mkdir -p obj
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