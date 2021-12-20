# Makefile syntax guide: https://makefiletutorial.com/
# More guidance here: https://stackoverflow.com/q/40621451
# And here: https://stackoverflow.com/q/3220277
# Use tabs for indentation, not spaces!

# Variables
CC := "$(GBDKDIR)bin/lcc"
SRC_DIR := ./src
BIN_DIR := ./bin

OUTPUT := ./bin/dropbear.gb

 # Find all *.c files in ./src 
SRCS := $(wildcard $(SRC_DIR)/*.c)

# String substitute all ./src/*.c entries for ./bin/*.o
OBJS := $(patsubst $(SRC_DIR)/%.c,$(BIN_DIR)/%.o,$(SRCS)) 

# First target, so this is the default target. Defines how we build "dropbear.gb".
# $BIN depends on $OBJS, so make will go and compile each ./src/*c file into a ./bin/*.o file first
# then link them all into "dropbear.gb".
build: $(OUTPUT)
$(OUTPUT): $(OBJS)
	$(CC) -o $(OUTPUT) $(OBJS)

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -o $@

# Targets can invoke other targets so we can rebuild with a clean followed by a build
rebuild: clean build

# Clean bin directory. Targets don't have to be defined in order.
clean:
	find ./bin -type f ! -name "*.gitkeep" -delete

# Print all variable values. Use -s option to avoid redundant printing.
debug:
	echo "Output:   	"	$(OUTPUT)
	echo "Compiler: 	"	$(CC)
	echo "Source Dir:	"	$(SRC_DIR)
	echo "Source Files:	"	$(SRCS)
	echo "Binary Dir:	"	$(BIN_DIR)
	echo "Object Files:	"	$(OBJS)
