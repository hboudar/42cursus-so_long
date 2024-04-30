#---------------------Mandatory-------------------#
NAME	=	so_long
M_SRC	=	mandatory/main.c mandatory/map.c mandatory/flood_fill.c \
			mandatory/game.c mandatory/player.c mandatory/destroy.c
M_OBJ	=	$(M_SRC:.c=.o)
M_H		=	mandatory/so_long.h
#-------------------------------------------------#

#----------------------Bonus----------------------#
B_NAME	=	so_long_bonus
B_SRC	=	bonus/main_bonus.c bonus/map_bonus.c bonus/flood_fill_bonus.c bonus/change_player_bonus.c\
			bonus/game_bonus.c bonus/player_bonus.c bonus/enemy_bonus.c bonus/destroy_bonus.c
B_OBJ	=	$(B_SRC:_bonus.c=_bonus.o)
B_H		=	bonus/so_long_bonus.h
#-------------------------------------------------#

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f
LINKS 	=	-lmlx -framework OpenGL -framework AppKit

all: pre $(NAME)

bonus: pre $(B_NAME)

$(NAME): $(M_OBJ) libs/libs.a
	$(CC) $(M_OBJ) $(LINKS) -o $(NAME) libs/libs.a

$(B_NAME): $(B_OBJ) libs/libs.a
	$(CC) $(B_OBJ) $(LINKS) -o $(B_NAME) libs/libs.a

mandatory/%.o: mandatory/%.c $(M_H)
	$(CC) $(CFLAGS) -c -Imlx $< -o $@

bonus/%_bonus.o: bonus/%_bonus.c $(B_H)
	$(CC) $(CFLAGS) -c -Imlx $< -o $@

pre:
	@cd libs && make

clean:
	$(RM) $(M_OBJ) $(B_OBJ)

fclean: clean
	$(RM) $(NAME) $(B_NAME)
	@cd libs && make fclean

re: fclean all
