CC       = gcc

OBJ_FILE  = listener.o talker.o
EXE_FILE  = listener talker 
PROG 	  = prog1.c
TAGS      = -lm -o


listener: listener.c
	${CC} listener.c ${TAGS} listener 

talker: talker.c
	${CC} talker.c ${TAGS} talker 

#${EXE_FILE}: ${PROG}
#	${CC} ${PROG} ${TAGS} ${EXE_FILE}

all : ${EXE_FILE}

clean:
	rm -f ${OBJ_FILE} ${EXE_FILE}
