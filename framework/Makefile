
NAME	=	libunit.a
CC		=	cc
AR		=	ar
CFLAGS	=	-Wall -Wextra -Werror

VPATH	=	src

SRC		=	unit.c
OBJS	=	$(addprefix obj/, $(SRCS:.cpp=.o))

all:

$(NAME): $(OBJS)
	$(AR) -rcs $(NAME) $(OBJS)

obj/%.o: %c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf /obj

fclean: clean
	rm -rf $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all
