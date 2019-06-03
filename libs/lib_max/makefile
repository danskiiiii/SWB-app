
CC=g++
CFLAGS=-c -Wall

SRCDIR=src
OBJDIR=obj

all: mkdirs build

mkdirs:
	mkdir -p $(OBJDIR)

build: $(OBJDIR)/max.o
	ar rvs lib_max.a $^

$(OBJDIR)/max.o: $(SRCDIR)/max.cpp $(SRCDIR)/max.h
	$(CC) $(CFLAGS) $< -o $@


.PHONY: clean
clean:
	rm -f *.a *.o
	rm -rf $(OBJDIR) 
