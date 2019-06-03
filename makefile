CC:=g++
CFLAGS:=-c -Wall
OBJDIR:=obj
BINDIR:=bin
SRCDIR:=src

LIBS:=libs
MX:=_max
AV:=_avg

all: mkdirs libraries build install

mkdirs:
	mkdir -p $(BINDIR)
	mkdir -p $(OBJDIR)

build: $(OBJDIR)/main.o 

install:
	$(CC) $(OBJDIR)/main.o -L$(LIBS)/lib$(MX) -l$(MX) -L$(LIBS)/lib$(AV) -l$(AV) -o $(BINDIR)/main

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $< -o $@

libraries:
	@$(MAKE) -C $(LIBS)/lib$(MX)/
	@$(MAKE) -C $(LIBS)/lib$(AV)/

.PHONY: clean
clean:
	rm -rf $(OBJDIR) 
	rm -rf $(BINDIR)	
	rm -f log.txt	
	@$(foreach path,lib$(MX), $(MAKE) clean -C $(LIBS)/$(path) &&) true
	@$(foreach path,lib$(AV), $(MAKE) clean -C $(LIBS)/$(path) &&) true
