CFLAGS = -Iinclude
SRCS = src/main.c src/core/task.c src/core/file.c src/utils/utils.c

OBJS = $(patsubst src/%.c, build/%.o, $(SRCS))

program: $(OBJS)
	gcc $(CFLAGS) -o task_tracker $(OBJS)

build/%.o: src/%.c
	@mkdir -p $(dir $@)
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -rf build task_tracker 
