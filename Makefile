CC = g++
CFLAGS = -std=c++20
LDFLAGS = -lSDL2
IDIR = include
ODIR = obj

_DEPS = defs.h screen.h 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o test-func.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o : %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

a : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

