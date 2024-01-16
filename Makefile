#-------------------------------------  COLORS  --------------------------------
RESET			= \033[0m
BLACK 			= \033[1;30m
RED 			= \033[1;31m
GREEN 			= \033[1;32m
YELLOW		 	= \033[1;33m
BLUE			= \033[1;34m
PURPLE 			= \033[1;35m
CYAN 			= \033[1;36m
WHITE 			= \033[1;37m

#----------------------------------- COMMANDS ----------------------------------
CC				= cc
RM 				= rm -rf

#-----------------------------------  FLAGS  -----------------------------------
CFLAGS			= -Wall -Wextra -Werror
NPD				= --no-print-directory
CMLX			= -lmlx -Ilmlx -lXext -lX11
CMATH			= -lm
#----------------------------------  FOLDERS ------------------------------------

LIBFTDIR 		= libftrm
LIBFT 			= $(LIBFTDIR)/libft.a
MATHVECDIR 		= mathvec
MATHVEC 		= $(MATHVECDIR)/mathvec.a
MLX 			= ./mlx/libmlx.a
MLX_PATH		= ./mlx
INCLUDE			= includes
SRCS			= src
_SUBFOLDERS		= test
VPATH			= $(SRCS) $(addprefix $(SRCS)/, $(_SUBFOLDERS))
OBJDIR			= obj

#--------------------------------- FILES  ---------------------------------------
NAME 			= minirt

_FILES 			= test inits exit keys render get

OBJ				= $(_FILES:%=%.o)
TARGET			= $(addprefix $(OBJDIR)/, $(OBJ))
_HEADERS		= minirt.h
HDR				= $(addprefix $(INCLUDE)/, $(_HEADERS))

#---------------------------------  RULES  --------------------------------------

all: $(NAME)

$(NAME): $(OBJDIR) $(TARGET) $(LIBFT) $(MATHVEC) $(MLX) main.c
	$(CC) $(CFLAGS) main.c $(TARGET) -I $(INCLUDE) $(LIBFT) $(MATHVEC) -o $(NAME) -L $(MLX_PATH) $(CMLX) $(CMATH)
	echo "[$(GREEN)Success$(RESET)] MiniRita created successfully$(BOLD)$(RESET)"

$(OBJDIR)/%.o : %.c $(HDR)
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $<$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(LIBFT):
	echo "[$(CYAN)Compiling$(RESET)] libft$(RESET)"
	$(MAKE) $(NPD) -C $(LIBFTDIR)
	echo "[$(GREEN)Success$(RESET)] Libft compilation compleated!$(BOLD)$(RESET)"

$(MATHVEC):
	echo "[$(CYAN)Compiling$(RESET)] mathvec$(RESET)"
	$(MAKE) $(NPD) -C $(MATHVECDIR)
	echo "[$(GREEN)Success$(RESET)] Mathvec compilation compleated!$(BOLD)$(RESET)"

$(MLX):
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)MLX$(RESET)"
	$(MAKE) $(NPD) -C $(MLX_PATH)

clean:
	$(RM) $(OBJDIR)
	$(MAKE) clean $(NPD) -C  $(LIBFTDIR)
	$(MAKE) clean $(NPD) -C  $(MLX_PATH)
	echo "[$(RED)Deleting$(RESET)]  object files deleted$(BOLD)$(RESET)"

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean $(NPD) -C $(LIBFTDIR)
	$(MAKE) clean $(NPD) -C $(MLX_PATH)
	echo "[$(RED)Deleting$(RESET)]  .a deleted$(BOLD)"

re: fclean all

.SILENT:

.PHONY: all clean fclean re