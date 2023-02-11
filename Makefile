all: example

example: example.c matrix.c ml.c
	${CC} $^ -o $@

clean:
	rm -rf *.o example

.PHONY: all clean
