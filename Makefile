CC ?= tcc
SRC = src/*
DEST = libiron.so
CFLAGS = -O2 -I./include -fPIC

all: $(DEST)

$(DEST): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) -shared -o $(DEST) *.o

clean:
	rm -f $(DEST) *.o

install: $(DEST)
	install -m755 $(DEST) /usr/local/lib64/
	cp include/iron/logger.h /usr/local/include


.PHONY: install all clean
