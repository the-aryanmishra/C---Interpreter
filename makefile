CC = gcc
OBJS = obj/arithmetic.o obj/condition.o obj/interpreter.o obj/print.o obj/variable.o obj/main.o

c_minus_minus: $(OBJS)
	$(CC) $^ -o $@

ut_%: obj/%.o
	$(CC) ut/$@.c $^ -o $@

obj/%.o: src/%.c
	$(CC) -c $< -o $@

clean:
	del $(subst /,\,$(OBJS))