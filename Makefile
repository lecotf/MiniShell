##
## Makefile for Makefile in /home/lecot_f/c_prog_elem/CPE_2014_bsq
## 
## Made by Florian Lécot
## Login   <lecot_f@epitech.net>
## 
## Started on  Tue Jan 13 07:04:32 2015 Florian Lécot
## Last update Wed Sep 21 15:34:22 2016 Lecot Florian
##

NAME		=	mysh

CC		=	gcc

RM		=	rm -f

COMPILEFLAGS	=	-W -Wall -Wextra -ansi -pedantic

INCLUDES	=	./includes/

LDFLAGS		=

CFLAGS		=	$(COMPILEFLAGS) -I$(INCLUDES)

SRCPATH		=	srcs

SRCS		=	$(SRCPATH)/main.c		\
			$(SRCPATH)/puts.c		\
			$(SRCPATH)/puts_error.c		\
			$(SRCPATH)/basic_fct.c		\
			$(SRCPATH)/my_atoi.c		\
			$(SRCPATH)/stringlib.c		\
			$(SRCPATH)/make_my_env.c	\
			$(SRCPATH)/get_next_line.c	\
			$(SRCPATH)/str_to_word_tab.c	\
			$(SRCPATH)/get_env.c		\
			$(SRCPATH)/env_list_fct.c	\
			$(SRCPATH)/run_mysh.c		\
			$(SRCPATH)/aff_prompt.c		\
			$(SRCPATH)/parse_cmd.c		\
			$(SRCPATH)/make_cmd_list.c	\
			$(SRCPATH)/parse_redir.c	\
			$(SRCPATH)/get_redir.c		\
			$(SRCPATH)/make_redir_list.c	\
			$(SRCPATH)/get_option_cmd.c	\
			$(SRCPATH)/check_builtins.c	\
			$(SRCPATH)/setting_env.c	\
			$(SRCPATH)/unsetting_env.c	\
			$(SRCPATH)/get_path.c		\
			$(SRCPATH)/env_in_tab.c		\
			$(SRCPATH)/access.c		\
			$(SRCPATH)/exec_bin.c		\
			$(SRCPATH)/redir.c

OBJS		=	$(SRCS:.c=.o)

DEBUG		=	no

ifeq ($(DEBUG), yes)
CC		=	clang
COMPILEFLAGS	=	-Weverything
LDFLAG		=	-g
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
