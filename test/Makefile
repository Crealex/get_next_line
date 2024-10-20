SRCS	=	../get_next_line.c ../get_next_line_utils.c main.c
CC		=	gcc
CFLAGS	=	-Werror -Wall -Wextra
BSIZE	=	-D BUFFER_SIZE=
EXEC	=	./a.out

all:	test

test:	${SRCS}
	${CC} ${CFLAGS} ${SRCS}
	${EXEC}

size:	${SRCS}
	${CC} ${CFLAGS} ${BSIZE} ${SRCS}
	${EXEC}

clean:
	rm -f ${EXEC}

re:		clean test

.PHONY: all clean re size test
