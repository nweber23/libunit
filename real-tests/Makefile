
# unit_test, run_tests
NAME	=	unit_test
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	main.c \
			ft_isalpha/00_launcher.c \
			ft_isalpha/01_basic_test.c \
			ft_isalpha/02_digit_test.c \
			ft_isalpha/03_whitespace_test.c \
			ft_isalpha/04_zero_test.c \
			ft_isalpha/05_underscore_test.c \
			ft_isalpha/06_punctuation_test.c \
			ft_isalpha/07_extended_ascii_test.c \
			ft_isalpha/08_negative_test.c \
			ft_isalpha/09_int_min_test.c \
			ft_isalpha/10_int_max_test.c \
			ft_strlen/00_launcher.c \
			ft_strlen/01_basic_test.c \
			ft_strlen/02_null_test.c \
			ft_strlen/03_empty_test.c \
			ft_strlen/04_whitespace_test.c \
			ft_strlen/05_42char_test.c

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