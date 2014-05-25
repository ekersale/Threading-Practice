/*
** actions.c for philosophe in /home/kersal_e/projet_actuels/PSU_2013_philo
** 
** Made by Elliot Kersale
** Login   <kersal_e@epitech.net>
** 
** Started on  Sun Mar 23 19:39:30 2014 Elliot Kersale
** Last update Sun Mar 23 19:46:13 2014 Elliot Kersale
*/

#include		"philosophe.h"

int			check_eat(t_list *list, int rice)
{
  if (list->status != EAT)
    {
      if (rice > 1 && list->stick == 1 && list->next->stick == 1)
	{
	  list->stick = 0;
	  list->next->stick = 0;
	  printf("Philosophe %s - %d is eating\n", list->name, list->uid);
	  list->status = EAT;
	  sleep(1);
	  list->stick = 1;
	  list->next->stick = 1;
	  return (EXIT_SUCCESS);
	}
    }
  return (EXIT_FAILURE);
}

int			check_think(t_list *list)
{
  if (list->status == REST || list->status == EAT)
    {
      if (list->stick == 1 || list->next->stick == 1)
	{
	  list->status = THINK;
	  if (list->stick == 1)
	    {
	      printf("Philosophe %s - %d is thinking\n", list->name, list->uid);
	      list->stick = 0;
	      sleep(1);
	      list->stick = 1;
	      return (EXIT_SUCCESS);
	    }
	  else
	    {
	      printf("Philosophe %s - %d is thinking\n", list->name, list->uid);
	      list->next->stick = 0;
	      sleep(1);
	      list->next->stick = 1;
	      return (EXIT_SUCCESS);
	    }
	}
    }
  return (EXIT_FAILURE);
}

void			check_sleep(t_list *list)
{
  if (list->status != REST && list->status == EAT)
    printf("Philosophe %s - %d is sleeping\n", list->name, list->uid);
}
