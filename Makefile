all: example

example: example.c ml.c 

clean:
	rm -rf *.o example

.PHONY: all clean
