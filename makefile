# common vars:
CC = clang
CFLAGS = -O3 -static
COMPILER_OUTPUT = ./local_build/compiler-output

# cat target vars:
CAT_MAIN = ./src/cat/main.c
CAT_OUTPUT = ./local_build/binaries/cat

# dynamic targets, builds everything.
all: cat

# targets:
cat:
	@echo "\e[0;33mmake: Info: Building cat..\e[0;37m"
	@$(CC) $(CFLAGS) $(CAT_MAIN) -o $(CAT_OUTPUT) >$(COMPILER_OUTPUT) 2>&1 && \
	echo "\e[0;33mmake: Info: Build finished successfully\e[0;37m" || echo "\e[0;31mmake: Error: Compilation failed. Check $(COMPILER_OUTPUT) for details.\e[0;37m";

clean:
	@rm -f $(CAT_OUTPUT) $(COMPILER_OUTPUT)

.PHONY: all cat clean