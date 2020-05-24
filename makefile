.PHONY: compile clean mrproper install

BINARIES_FOLDER=binaries
BINARY=collatz

SOURCES_FOLDER=sources
SOURCES=$(wildcard $(SOURCES_FOLDER)/*.c)

OBJECTS_FOLDER=objects
OBJECTS=$(SOURCES:$(SOURCES_FOLDER)/%.c=$(OBJECTS_FOLDER)/%.o)

C_FLAGS=-Wall -Wextra -Wpedantic -O3 -std=c18

# make
# make compile
compile: $(BINARIES_FOLDER)/$(BINARY)

$(BINARIES_FOLDER)/$(BINARY): $(OBJECTS)
	@mkdir -p $(BINARIES_FOLDER)
	@gcc -o $@ $^

$(OBJECTS_FOLDER)/%.o: $(SOURCES_FOLDER)/%.c
	@mkdir -p $(OBJECTS_FOLDER)
	@gcc $(C_FLAGS) -o $@ -c $^

# make clean
clean:
	@rm -rf $(OBJECTS_FOLDER)

# make mrproper
mrproper: clean
	@rm -rf $(BINARIES_FOLDER)

# make install (requires superuser privileges)
install:
	@cp $(BINARIES_FOLDER)/$(BINARY) /usr/local/bin/$(BINARY)
	@mkdir -p /usr/local/man/man1
	@cp man/$(BINARY).1 /usr/local/man/man1/$(BINARY).1

# make uninstall (requires superuser privileges)
uninstall:
	@rm -rf /usr/local/bin/$(BINARY)
	@rm -rf /usr/local/man/man1/$(BINARY).1
