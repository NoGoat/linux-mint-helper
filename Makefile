#C compiler to use
CC=cc 
#Optional C flags for compiler 
CFLAGS=-O3 -I ./includes 

#Wild card to get all C files in src dir
CSRC=$(wildcard ./src/*.c) 

#patsubst takes all the src files then produces an output name of ./filename.o 
COBJ=$(patsubst ./src/%.c, ./%.o, $(CSRC))

#Target binary name 
TARGET=helper

#Build the binary and run these requirements first 
$(TARGET): $(COBJ)
	$(CC) $(CFLAGS) $^ -o $@

#Build each C object file $^ is just the ./src/%.c abd $@ is the target so the ./%.o 
./%.o: ./src/%.c 
	$(CC) $(CFLAGS) -c $^ -o $@
	
