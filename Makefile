CC = gcc
CFLAGS = -Wall -Iinclude
SRCDIR = src
TESTDIR = tests
BINDIR = bin
TARGET = $(BINDIR)/program

SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(SRC:.c=.o)

TEST_SRC_USUARIO = $(TESTDIR)/test_usuario.c
TEST_OBJ_USUARIO = $(TEST_SRC_USUARIO:.c=.o)
TEST_TARGET_USUARIO = $(BINDIR)/test_usuario

TEST_SRC_INDUSTRIA = $(TESTDIR)/test_industria.c
TEST_OBJ_INDUSTRIA = $(TEST_SRC_INDUSTRIA:.c=.o)
TEST_TARGET_INDUSTRIA = $(BINDIR)/test_industria

# Arquivos fonte sem main.c para evitar múltiplas definições de main
TEST_DEPENDENCIES = src/industria.c src/usuario.c src/relatorio.c

.PHONY: all clean test

all: $(TARGET)

$(TARGET): $(OBJ)
	if not exist $(BINDIR) mkdir $(BINDIR)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: test_usuario test_industria

test_usuario: $(TEST_TARGET_USUARIO)

$(TEST_TARGET_USUARIO): $(TEST_OBJ_USUARIO)
	$(CC) $(CFLAGS) -o $@ $^ $(TEST_DEPENDENCIES)
	./$(TEST_TARGET_USUARIO)

test_industria: $(TEST_TARGET_INDUSTRIA)

$(TEST_TARGET_INDUSTRIA): $(TEST_OBJ_INDUSTRIA)
	$(CC) $(CFLAGS) -o $@ $^ $(TEST_DEPENDENCIES)
	./$(TEST_TARGET_INDUSTRIA)

clean:
	rm -f $(SRCDIR)/*.o $(TARGET)
	rm -f $(TESTDIR)/*.o $(TEST_TARGET_USUARIO) $(TEST_TARGET_INDUSTRIA)
