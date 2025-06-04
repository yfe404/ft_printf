# **************************************************************************** #
#                                  VARIABLES                                   #
# **************************************************************************** #

NAME				= libftprintf.a

# Directories
SRCS_DIR			= ft_printf
SRCS_DIR_CONV		= ft_printf/conversion
LIBFT_DIR			= libft

# Source files
SRCS_FILES			= ft_printf.c parsing.c numbers_utils_count.c numbers_utils_print.c utils.c
SRCS_FILES_CONV		= ft_uint.c ft_int.c ft_string.c ft_pointer.c

SRCS				= $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))
SRCS_CONV			= $(addprefix $(SRCS_DIR_CONV)/, $(SRCS_FILES_CONV))

OBJS				= $(SRCS:.c=.o)
OBJS_CONV			= $(SRCS_CONV:.c=.o)

# Compiler and flags
CC					= cc
CFLAGS				= -Wall -Wextra -Werror

# Commands
AR          = ar rcs
RM          = rm -f

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_CONV)
	@$(MAKE) -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a $(NAME)
	@$(AR) $(NAME) $(OBJS) $(OBJS_CONV)

bonus:
	@$(MAKE) re

$(SRCS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -I$(SRCS_DIR) -I$(LIBFT_DIR) -c $< -o $@

$(SRCS_DIR_CONV)/%.o: $(SRCS_DIR_CONV)/%.c
	$(CC) $(CFLAGS) -I$(SRCS_DIR_CONV) -I$(LIBFT_DIR) -c $< -o $@

clean:
	@$(RM) $(OBJS) $(OBJS_CONV)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re
