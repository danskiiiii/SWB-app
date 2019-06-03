
CC=g++
CFLAGS=-c -Wall

SRCDIR=src
OBJDIR=obj

all: mkdirs build

mkdirs:
	mkdir -p $(OBJDIR)

build: $(OBJDIR)/avg.o
	ar rvs lib_avg.a $^

$(OBJDIR)/avg.o: $(SRCDIR)/avg.cpp $(SRCDIR)/avg.h 
	$(CC) $(CFLAGS) $< -o $@


.PHONY: clean
clean:
	rm -f *.a *.o
	rm -rf $(OBJDIR) 
