all: example

example: example.c ml.c matrix.c

clean:
	rm -rf *.o example

.PHONY: all clean
