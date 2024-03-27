SRCS =	main.cpp \
		Serializer.cpp

OBJS = 	${SRCS:.cpp=.o}

TOTAL_OBJS = ${OBJS}

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = convert

${NAME} : ${TOTAL_OBJS}
	${CC} ${CFLAGS} ${TOTAL_OBJS} -o $@

%.o :%.cpp
	${CC} ${CFLAGS} -c -I. $< -o $@

all : ${NAME}

clean:
	rm -f ${OBJS}

fclean:
	make clean
	rm -rf ${NAME}

re: 
	make fclean
	make all

.PHONY: all clean fclean re
