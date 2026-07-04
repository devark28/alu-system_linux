CC       = gcc
CFLAGS   = -g3 -Wall -Werror -Wextra -pedantic
FILENAME = strace

0_SRC = 0-$(FILENAME).c
$(FILENAME)_0: $(0_SRC:.c=.o)
	$(CC) $(CFLAGS) $(0_SRC) -o $(FILENAME)_0

1_SRC = 1-$(FILENAME).c
$(FILENAME)_1: $(1_SRC:.c=.o)
	$(CC) $(CFLAGS) $(1_SRC) -o $(FILENAME)_1
