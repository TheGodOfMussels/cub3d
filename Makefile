# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 16:29:38 by dimolin2          #+#    #+#              #
#    Updated: 2024/01/04 16:29:40 by dimolin2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

####### NAME #########

NAME = cub3d
PRNAME = cub3d

BNUS = bonus

INCLUDE = include

MLX_PATH = 

###### VARIABLE ######

DIRSRCS = 

DIROBJS = 

FLSRCS = src/main.c src/readfile.c src/fields_read.c src/utils.c src/fields_check.c src/read_map.c src/map_checker.c src/map_utils.c src/free_destroy.c src/init.c src/raycasting.c src/render.c src/key_handler.c src/utils2.c src/key_dir_handler.c

FLBNS = 

FLOBJS = ${FLSRCS:.c=.o}

OBJS = $(FLOBJS)

FLOBJS_BNS = ${FLBNS:.c=.o}

OBJS_BNS = $(FLOBJS_BNS)

ARUSD = libft.a
ARUSDDIR = libft/

ARINC = $(addprefix $(ARUSDDIR),$(ARUSD))

CC = gcc
AR = ar
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = include/minilibx-linux/libmlx.a -lXext -lX11 -lm -lz

###### COLORS ########

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

######## EXT #########

# make a .o file using a .c file
# $< for the .c file
# $@ for the .o file

# .inextention.outextention:

#.c.o:
$(DIROBJS)%.o: $(DIRSRCS)%.c
	@echo "$(GREEN)Compiling:$(BLUE) $< $(DEF_COLOR)"
	@${CC} ${CFLAGS} -I ${INCLUDE} -c $< -o $@

####### RULES ########

all: libft ${NAME}

${NAME}: ${OBJS}
	@echo "$(YELLOW)- Program Name: $(WHITE)${PRNAME}$(DEF_COLOR)"
	@echo "$(YELLOW)- Compiler: $(WHITE)${CC}$(DEF_COLOR)"
	@echo "$(YELLOW)- Flags: $(WHITE)${CFLAGS}$(DEF_COLOR)"
	@${CC} -L $(ARUSDDIR) -I $(INCLUDE) -o $(PRNAME) $(OBJS) $(MLXFLAGS) $(ARINC) ${CFLAGS}
	
bonus: $(OBJS_BNS)
	@echo "$(YELLOW)- Program Name: $(WHITE)${PRNAME}$(DEF_COLOR)"
	@echo "$(YELLOW)- Compiler: $(WHITE)${CC}$(DEF_COLOR)"
	@echo "$(YELLOW)- Flags: $(WHITE)${CFLAGS}$(DEF_COLOR)"
	@${CC} ${CFLAGS} -L $(ARUSDDIR) -I $(INCLUDE) -o $(PRNAME) $(OBJS_BNS) $(ARINC)

clean:
	@make -sC libft clean
	@${RM} ${OBJS} ${OBJS_BNS}
	@echo "$(RED)All $(CYAN)$(PRNAME)$(RED)'s objects removed with $(WHITE)${RM}$(DEF_COLOR) 🧹" 

fclean: clean
	@make -sC libft fclean
	@${RM} ${PRNAME} 
	@echo "$(RED)..and $(CYAN)${PRNAME} $(RED)as been removed$(DEF_COLOR) 🚮"

libft:
	@make -sC libft

libftclean:
	@make -sC libft clean

libftfclean:
	@make -sC libft fclean

re: fclean all 

.PHONY: all clean fclean re starting .c.o libft libftclean libftfclean minilibx
.SUFFIXES: .c .o 
