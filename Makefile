NAME		:= hotrace

# SOURCES
SRCS_DIR	:= ./srcs
SRCS		:= $(shell find ./srcs -name "*.c" | tr '\n' ' ')

# OBJECTS
OBJS_DIR	:= ./objs
DEPS_DIR	:= ./deps
OBJS		:= $(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.c=.o))
DEPS		:= $(subst $(SRCS_DIR), $(DEPS_DIR), $(SRCS:.c=.d))

# LINKER
INC			= -I ./incs/

# COMPILER
CC			:= cc
CFLAGS		= -Wall -Wextra -Werror $(INC) -MMD -MP

ifeq ($(MAKECMDGOALS), address)
	CFLAGS += -g3 -fsanitize=address
endif

all			: $(NAME)

$(NAME)	: $(OBJS) $(DEPS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: srcs/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(DEPS_DIR)/%.d: srcs/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MM $< > $@

clean		:
	$(RM) -r $(OBJS_DIR) $(DEPS_DIR)

fclean		: clean
	$(RM) $(NAME)

re			: fclean all

address		: clean all

.PHONY		: all clean fclean re address

-include $(DEPS)