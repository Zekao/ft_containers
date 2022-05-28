# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/30 22:50:16 by emaugale          #+#    #+#              #
#    Updated: 2022/05/28 05:47:10 by emaugale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME 		=	ft_containers

NAME_S		=	stackos

SRCS 		=	main.cpp		
TEST_STACK	=	stack_main.cpp	

OBJS		=		$(SRCS:.cpp=.o)
OBJS_STACK	=		$(TEST_STACK:.cpp=.o)
DEPS_STACK	=		$(TEST_STACK:.cpp=.d)
DEPS		=		$(SRCS:.cpp=.d)
INCLUDE		= 		include
RM		=		rm -f
CC		=		clang++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98 

%.o:				%.cpp
	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@ -I $(INCLUDE)

all:	$(NAME)

test:	$(NAME_S)

$(NAME_S):		$(OBJS_STACK)
	@echo "TEST FOR STACK HAVE BEEN COMPILED"
	$(CC) $(CFLAGS) $(OBJS_STACK) -o $(NAME_S)
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
	@$(RM) $(OBJS) $(DEPS) $(OBJS_STACK) $(DEPS_STACK)
	@echo "\033[1;31m ⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⣶⣄⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣦⣄⣀⡀⣠⣾⡇⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⢀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⢿⣿⣿⡇⠀⠀⠀⠀"
	@echo "⠀⣶⣿⣦⣜⣿⣿⣿⡟⠻⣿⣿⣿⣿⣿⣿⣿⡿⢿⡏⣴⣺⣦⣙⣿⣷⣄⠀⠀⠀\033[1;34m Goodbye everyone\033[1;31m"
	@echo "⠀⣯⡇⣻⣿⣿⣿⣿⣷⣾⣿⣬⣥⣭⣽⣿⣿⣧⣼⡇⣯⣇⣹⣿⣿⣿⣿⣧⠀⠀"
	@echo "⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠸⣿⣿⣿⣿⣿⣿⣿⣷⠀\033[m"
	@echo "\033[1;1;32m♻️  Objects have been \033[5;1;31mdeleted\033[m ♻️"

fclean:
	@$(RM) $(OBJS) $(DEPS) $(OBJS_STACK) $(DEPS_STACK)
	@$(RM) $(NAME) $(NAME_S)
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

-include $(DEPS) $(DEPS_STACK)
.PHONY: all clean fclean re test