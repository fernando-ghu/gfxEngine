CC = g++
CFLAGS = -std=c++20
LDFLAGS = -lSDL2
ODIR = obj

_OBJ = main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o : %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

a : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

