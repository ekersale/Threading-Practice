/*
** philosophe.h for philosophe in /home/kersal_e/projet_actuels/PSU_2013_philo/sources
** 
** Made by Elliot Kersale
** Login   <kersal_e@epitech.net>
** 
** Started on  Fri Mar 14 11:48:04 2014 Elliot Kersale
** Last update Sun Mar 23 19:57:20 2014 Elliot Kersale
*/

#ifndef			_PHILOSOPHE_H__
# define		_PHILOSOPHE_H__
/*
** INCLUDES
*/
#include		<stdlib.h>
#include		<stdio.h>
#include		<unistd.h>
#include		<string.h>
/* 
** DEFINE
*/
# define		PHILO		7
# define		REST		0
# define		EAT		1
# define		THINK		2
/*
** STRUCTS
*/
typedef struct  	s_list
{
  int           	status;
  int			stick;
  int			uid;
  char			*name;
  pthread_mutex_t	mutex;
  struct s_list		*next;
  struct s_list		*prev;
}               	t_list;
/*
** list.c
*/
t_list		*create_list(int);
void		empty_list(t_list *);
void		delete_list(t_list **);
int		add_after(t_list *, int);
char		*choose_name(int);
/*
** philosophe.c
*/
int    		init_thread(void);
void	       	*philo_alg(void *);
int	       	launch_thread(t_list *);
/*
** actions.c
*/
int    		check_eat(t_list *, int);
int	       	check_think(t_list *);
void   		check_sleep(t_list *);
/*
**
*/
#endif
//EOF _PHILOSOPHE_H__
