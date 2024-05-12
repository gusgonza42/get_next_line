# <-- Library's Name --> #
NAME = gnl.a

# <-- Compilation Command --> #
CC = gcc

# <-- Compilation Flags --> #
CFLAGS = -Wall -Werror -Wextra

# <-- Remove Command -->#
RM = rm -f

# <-- HEADER --> #
HEADER = get_next_line.h

# <-- MAKEFILE --> #
MAKEFILE = Makefile

# <-- AR --> #
AR = ar -rcs

# <-- Files --> #
SRC_FILES = get_next_line.c get_next_line_utils.c

# <-- Objects --> #
OBJS = $(SRC_FILES:.c=.o)

# <-- Main Target --> #
all: $(NAME)

# <-- Objects Creation --> #
%.o: %.c $(HEADER) $(MAKEFILE)
	@echo "🧩 ☁️  Compiling... $<..."
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "🔨 🦔 $@ created!"

# <--Library Creation--> #
$(NAME): $(OBJS)
	@echo "✅ 🚀 0bjects created successfully!"
	@$(AR) $@ $(OBJS)
	@echo "✅ 🛰  $(NAME) created successfully!"

# <-- Objects Destruction --> #
clean:
	@$(RM) $(OBJS)
	@echo "🗑️  🚀 Objects destroyed successfully!"

# <-- Clean Execution + .a Destruction --> #
fclean: clean
	@$(RM) $(NAME) *.out
	@echo "🗑️  🛰  $(NAME) destroyed successfully!"

# <-- Fclean Execution -->
re: fclean all

# <-- Targets Declaration --> #
.PHONY : all clean fclean re
