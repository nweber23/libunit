
NAME	=	libunit.a
CC		=	cc
AR		=	ar
CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	load_test.c \
			launch_tests.c \
			utils.c
OBJS	=	$(addprefix obj/, $(SRCS:.c=.o))

all: $(NAME)

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
