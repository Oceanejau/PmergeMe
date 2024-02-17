NAME = PmergeMe

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 
INCLUDES = ./includes

SRCS =	PmergeMe.cpp\
		main.cpp\

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -I $(INCLUDES) $(OBJS) -o $(NAME)

.cpp.o:
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $^ -o $@

clean:
	@rm -rf $(NAME) $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SILENT:
