/*
** philosophe.c for philosophe in /home/kersal_e/projet_actuels/PSU_2013_philo
** 
** Made by Elliot Kersale
** Login   <kersal_e@epitech.net>
** 
** Started on  Sun Mar 23 19:41:39 2014 Elliot Kersale
** Last update Sun Mar 23 19:59:16 2014 Elliot Kersale
*/

#include		<pthread.h>
#include		"philosophe.h"

int			rice = 10;

void			*philo_alg(void *arg)
{
  t_list		*list;
  int			i;

  list = (t_list*)arg;
  while (rice > 0)
    {
      check_think(list);
      pthread_mutex_lock(&list->mutex);
      pthread_mutex_lock(&list->next->mutex);
      i = check_eat(list, rice);
      check_sleep(list);
      pthread_mutex_unlock(&list->mutex);
      pthread_mutex_unlock(&list->next->mutex);
      if (i == 0)
	rice--;
    }
  return (NULL);
}

int			launch_thread(t_list *list)
{
  pthread_t		philo[PHILO];
  int			count;
  int			ret;

  count = 0;
  while (count < PHILO)
    {
      if (count == 0)
	list = list->next;
      ret = pthread_create(&philo[count], NULL, philo_alg, list);
      if (ret)
	return (EXIT_FAILURE);
      list = list->next;
      count++;
    }
  count = 0;
  while (count < PHILO && !pthread_join(philo[count], NULL))
    count++;
  return (EXIT_SUCCESS);
}

int			init_thread()
{
  int			count;
  t_list		*list;

  count = 1;
  list = create_list(0);
  while (count < PHILO)
    {
      add_after(list, count);
      count++;
    }
  if (launch_thread(list) == EXIT_FAILURE)
    perror("Initializing thread failed");
  delete_list(&list);
  return (EXIT_SUCCESS);
}
