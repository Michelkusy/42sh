##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

PARS		=	src/parsing/

BUILTS		=	src/builtin/

TOLS		=	src/tools/

SHEL		=	src/shell/

TESTS		=	tests/

SRC		=	src/main.c 			\
			$(SHEL)minishell.c		\
			$(PARS)binary_tree.c		\
			$(PARS)analyse.c		\
			$(TOLS)display_env.c		\
			$(TOLS)get_time.c		\
			$(PARS)parser.c			\
			$(TOLS)tools.c			\
			$(BUILTS)setenv.c		\
			$(BUILTS)unsetenv.c		\
			$(SHEL)redirection.c		\
			$(SHEL)exit_redirect.c		\
			$(SHEL)entrance_redirect.c	\
			$(TOLS)checking.c		\
			$(SHEL)pipe.c			\
			$(BUILTS)cd.c			\
			$(TOLS)error_exec.c		\
			$(BUILTS)exit.c			\
			$(SHEL)exec.c			\
			$(BUILTS)echo.c			\
			$(BUILTS)history.c		\
			$(BUILTS)alias.c 		\
			$(BUILTS)which.c		\
			$(SHEL)local.c			\
			$(TOLS)utils.c 			\
			src/lang.c			\
			$(BUILTS)sup_history.c		\

SRC_TEST	=	$(TESTS)tests_function.c 	\
			$(TESTS)tests_generic.c 	\
			$(TESTS)main.c 			\
			$(SHEL)minishell.c		\
			$(PARS)binary_tree.c		\
			$(PARS)analyse.c		\
			$(TOLS)display_env.c		\
			$(TOLS)get_time.c		\
			$(TOLS)tools.c			\
			$(PARS)parser.c			\
			$(BUILTS)setenv.c		\
			$(BUILTS)unsetenv.c		\
			$(BUILTS)which.c		\
			$(SHEL)redirection.c		\
			$(SHEL)exit_redirect.c		\
			$(SHEL)entrance_redirect.c	\
			$(TOLS)checking.c		\
			$(SHEL)pipe.c			\
			$(BUILTS)cd.c			\
			$(TOLS)error_exec.c		\
			$(BUILTS)exit.c			\
			$(SHEL)exec.c			\
			$(BUILTS)echo.c			\
			$(BUILTS)history.c		\
			$(BUILTS)alias.c 		\
			$(SHEL)local.c			\
			$(TOLS)utils.c 			\
			$(BUILTS)sup_history.c		\
			src/lang.c			\

OBJ		=	$(SRC:.c=.o)

OBJ_TEST	=	$(SRC_TEST:.c=.o)

CFLAGS		=	-Wall -Wextra

CPPFLAGS	=	-I./include/

LIB		=	-L./lib/my/ -lmy

NAME		=	42sh

NAME_TEST	=	unit_tests

DEPS		=	include/my.h

CC		=	gcc

RM		=	rm -rf

MAC_OS_FILES 	=	$(NAME).dSYM

all:			lib $(NAME)

debug:			CFLAGS += -g3
debug: 			re

$(NAME):		$(OBJ)
			$(CC) $(CPPFLAGS) -o $(NAME) $(OBJ) $(LIB)

clean:
			$(RM) $(OBJ)

fclean:			clean lib_clean tests_clean
			$(RM) $(NAME)
			$(RM) $(MAC_OS_FILES)
			$(RM) .vscode/

re:			fclean all

lib:
			@make --no-print-directory re -C ./lib
			@make --no-print-directory clean -C ./lib

lib_clean:
			@make --no-print-directory fclean -C ./lib

tests_run: 		lib $(OBJ)
			$(CC) $(CPPFLAGS) -o $(NAME_TEST) $(SRC_TEST) $(LIB) --coverage -lcriterion
			./$(NAME_TEST)

rm_test:
			$(RM) $(NAME_TEST)
			$(RM) *.gcda
			$(RM) *.gcno
			make clean

tests_clean:		rm_test

all_clean: 		fclean rm_test

.PHONY:			all clean fclean re \
			lib lib_clean tests_run tests_clean rm_test
