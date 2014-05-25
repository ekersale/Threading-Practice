##
## Makefile for epikong in /home/kersal_e/rush-epikong
## 
## Made by Elliot Kersale
## Login   <kersal_e@epitech.net>
## 
## Started on  Fri Mar  7 20:47:19 2014 Elliot Kersale
## Last update Sun Mar 23 19:43:22 2014 Elliot Kersale
##

SRCS		=	./sources/main.c		\
			./sources/list.c		\
			./sources/actions.c		\
			./sources/philosophe.c

OBJS		=	$(SRCS:.c=.o)

CC		=	gcc

INC		=	./include

CFLAGS		=	-Wall -W -g -ggdb3 -I $(INC)

NAME		=	philo

RM		=	rm -rf

$(NAME)		:	$(OBJS)
			$(CC) -lpthread $(OBJS) -o $(NAME)

all		:	fclean $(NAME)

clean		:
			$(RM) $(OBJS)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all
