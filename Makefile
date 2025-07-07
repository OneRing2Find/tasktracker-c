CFLAGS = -Iinclude
SRCS = src/main.c src/core/task.c src/core/file.c src/utils/utils.c
OBJS = $(SRCS:.c=.o)
