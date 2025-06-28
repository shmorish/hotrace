NAME		:= hotrace

# SOURCES
# Note: Need to fix
SRCS_DIR	:= ./srcs
SRCS		:= $(shell find ./srcs -name "*.c" | tr '\n' ' ')

# OBJECTS
OBJS_DIR	:= ./objs
OBJS		:= $(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.c=.o))
DEPS		:= $(OBJS:.o=.d)

# LINKER
INC			= -I ./incs/

# COMPILER
CC			:= cc
CFLAGS		= -Wall -Wextra -Werror $(INC) -MMD -MP

ifeq ($(MAKECMDGOALS), address)
	CFLAGS += -g3 -fsanitize=address
endif

all			: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: srcs/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean		:
	$(RM) -r $(OBJS_DIR)

fclean		: clean
	$(RM) $(NAME)

re			: fclean all

address		: clean all

.PHONY		: all clean fclean re address

-include $(DEPS)