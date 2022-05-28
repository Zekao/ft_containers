# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/30 22:50:16 by emaugale          #+#    #+#              #
#    Updated: 2022/05/28 06:10:48 by emaugale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME 		=	ft_containers
NAME_S		=	stack_test
NAME_V		=	vector_test

SRCS 		=	main.cpp		
TEST_STACK	=	stack_main.cpp	
TEST_VECTOR	=	vector_main.cpp	

OBJS		=		$(SRCS:.cpp=.o)
DEPS		=		$(SRCS:.cpp=.d)
OBJS_STACK	=		$(TEST_STACK:.cpp=.o)
DEPS_STACK	=		$(TEST_STACK:.cpp=.d)
OBJS_VECTOR	=		$(TEST_VECTOR:.cpp=.o)
DEPS_VECTOR	=		$(TEST_VECTOR:.cpp=.d)

INCLUDE		= 		include
RM			=		rm -f
CC			=		clang++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98 

%.o:				%.cpp
	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@ -I $(INCLUDE)

all:	$(NAME)

stack:	$(NAME_S)

vector: $(NAME_V)

$(NAME_S):		$(OBJS_STACK)
	@echo "TEST FOR STACK HAVE BEEN COMPILED"
	$(CC) $(CFLAGS) $(OBJS_STACK) -o $(NAME_S)
$(NAME_V):		$(OBJS_VECTOR)
	@echo "TEST FOR STACK HAVE BEEN COMPILED"
	$(CC) $(CFLAGS) $(OBJS_VECTOR) -o $(NAME_V)
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
	@$(RM) $(OBJS) $(DEPS) $(OBJS_STACK) $(DEPS_STACK) $(OBJS_VECTOR) $(DEPS_VECTOR)
	@echo "\033[1;31m ⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⣶⣄⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣦⣄⣀⡀⣠⣾⡇⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⢀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⢿⣿⣿⡇⠀⠀⠀⠀"
	@echo "⠀⣶⣿⣦⣜⣿⣿⣿⡟⠻⣿⣿⣿⣿⣿⣿⣿⡿⢿⡏⣴⣺⣦⣙⣿⣷⣄⠀⠀⠀\033[1;34m Goodbye everyone\033[1;31m"
	@echo "⠀⣯⡇⣻⣿⣿⣿⣿⣷⣾⣿⣬⣥⣭⣽⣿⣿⣧⣼⡇⣯⣇⣹⣿⣿⣿⣿⣧⠀⠀"
	@echo "⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠸⣿⣿⣿⣿⣿⣿⣿⣷⠀\033[m"
	@echo "\033[1;1;32m♻️  Objects have been \033[5;1;31mdeleted\033[m ♻️"

fclean:
	@$(RM) $(OBJS) $(DEPS) $(OBJS_STACK) $(DEPS_STACK) $(OBJS_VECTOR) $(DEPS_VECTOR)
	@$(RM) $(NAME) $(NAME_S) $(NAME_V)
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

-include $(DEPS) $(DEPS_STACK) $(DEPS_VECTOR)
.PHONY: all clean fclean re stack vector