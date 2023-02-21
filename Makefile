CC = g++

SRCDIR = src
TESTDIR = tests
INCDIR = include
OBJDIR = obj
BINDIR = bin

CFLAGS = -Wall -I$(INCDIR)

CFILES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/$(SRCDIR)/%.o,$(CFILES))

TESTFILES = $(wildcard $(TESTDIR)/*.cpp)
TESTOBJECTS = $(patsubst $(TESTDIR)/%.cpp,$(OBJDIR)/$(TESTDIR)/%.o,$(TESTFILES))

BINARY = $(BINDIR)/test

all: $(BINDIR) $(OBJDIR) $(BINARY)

test: $(BINDIR) $(OBJDIR) $(BINARY)
	./$(BINARY)

$(BINARY): $(OBJECTS) $(TESTOBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)/$(SRCDIR)/%.o: $(SRCDIR)/%.cpp $(INCDIR)/%.h
	$(CC) $(CFLAGS)  -c -o $@ $<

$(OBJDIR)/$(TESTDIR)/%.o: $(TESTDIR)/%.cpp
	$(CC) $(CFLAGS)  -c -o $@ $<

$(BINDIR):
	mkdir -p $(BINDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)
	mkdir -p $(OBJDIR)/$(SRCDIR)
	mkdir -p $(OBJDIR)/$(TESTDIR)

clean:
	rm -rf $(BINDIR) $(OBJDIR)
