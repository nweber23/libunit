
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
	@printf '\033[0m (     (                    )  (            \n'
	@printf '\033[93m )\\ )  )\\ )   (          ( /(  )\\ )  *   )  \n'
	@printf '\033[93m(()/( (()/( ( )\\     (   )\\())(()/(` )  /( \n'
	@printf '\033[33m /(_)) /(_)))((_)    )\\ ((_)\\  /(_))( )(_)) \n'
	@printf '\033[33m(\033[91m_\033[33m))  (\033[91m_\033[33m)) ((\033[91m_\033[33m)\033[91m_  _\033[33m ((\033[91m_\033[33m) \033[91m_\033[33m((\033[91m_\033[33m)(\033[91m_\033[33m)) (\033[91m_\033[33m(\033[91m_\033[33m())  \n'
	@printf '\033[91m| |   |_ _| | _ )| | | || \\| ||_ _||_   _|  \n'
	@printf '\033[91m| |__  | |  | _ \\| |_| || .` | | |   | |    \n'
	@printf '\033[31m|____||___| |___/ \\___/ |_|\\_||___|  |_|    \n\n\033[0m'


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
