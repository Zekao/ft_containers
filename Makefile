# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/30 22:50:16 by emaugale          #+#    #+#              #
#    Updated: 2022/04/30 22:50:39 by emaugale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME 		=	ft_containers

SRCS 		=	main.cpp		\

OBJS		=		$(SRCS:.cpp=.o)
DEPS		=		$(SRCS:.cpp=.d)
INCLUDE		= 		include
RM		=		rm -f
CC		=		c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98

%.o:				%.cpp
	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@ -I $(INCLUDE)

all:	$(NAME)

$(NAME):		$(OBJS)
	@clear
	@echo "\033[1;34m                                                                                                                     "
	@echo "#######                                                  ###                                                   "
	@echo "#       #    #   ##   #    #  ####    ##   #      ###### ###  ####     #####  #####   ####       # ######  ####  ##### "
	@echo "#       ##  ##  #  #  #    # #    #  #  #  #      #       #  #         #    # #    # #    #      # #      #    #   #   "
	@echo "#####   # ## # #    # #    # #      #    # #      #####  #    ####     #    # #    # #    #      # #####  #        #   "
	@echo "#       #    # ###### #    # #  ### ###### #      #               #    #####  #####  #    #      # #      #        #   "
	@echo "#       #    # #    # #    # #    # #    # #      #          #    #    #      #   #  #    # #    # #      #    #   #   "
	@echo "####### #    # #    #  ####   ####  #    # ###### ######      ####     #      #    #  ####   ####  ######  ####    #   "
	@echo "									"
	@echo "Project name : $(NAME)"
	@echo "\n\033[1;32mCompilation en cours... ⌛\033[0;m\n"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@make wait
	@echo "Bonne correction!"

clean:
	@$(RM) $(OBJS) $(DEPS)
	@echo "\033[1;31m ⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⣶⣄⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣦⣄⣀⡀⣠⣾⡇⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⢀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⢿⣿⣿⡇⠀⠀⠀⠀"
	@echo "⠀⣶⣿⣦⣜⣿⣿⣿⡟⠻⣿⣿⣿⣿⣿⣿⣿⡿⢿⡏⣴⣺⣦⣙⣿⣷⣄⠀⠀⠀\033[1;34m Goodbye everyone\033[1;31m"
	@echo "⠀⣯⡇⣻⣿⣿⣿⣿⣷⣾⣿⣬⣥⣭⣽⣿⣿⣧⣼⡇⣯⣇⣹⣿⣿⣿⣿⣧⠀⠀"
	@echo "⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠸⣿⣿⣿⣿⣿⣿⣿⣷⠀\033[m"
	@echo "\033[1;1;32m♻️  Objects have been \033[5;1;31mdeleted\033[m ♻️"

fclean:
	@$(RM) $(OBJS) $(DEPS)
	@$(RM) $(NAME)
	@echo -n "\033[0;31m⠀"
	@echo "UNINSTALLING LEAGUE OF LEGENDS"
	@echo "[##############]"
	@echo "　╭━╮╭━╮ ╭╮ ╱ "　　
	@echo "　╰━┫╰━┫ ╰╯╱ ╭╮ "　　
	@echo "　╰━╯╰━╯　╱　╰╯" 　　　　　
	@echo "　     COMPLETE"
	@echo "\033[1;1;32m♻️  Objects and $(NAME) have been \033[5;1;31mdeleted\033[m ♻️"

wait:

re:		fclean all

-include $(DEPS)
.PHONY: all clean fclean re