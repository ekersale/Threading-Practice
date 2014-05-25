/*
** list.c for philosophe in /home/porres_m/PROJETS/philosophes/PSU_2013_philo
** 
** Made by Martin Porrès
** Login   <porres_m@epitech.net>
** 
** Started on  Thu Mar 13 10:44:07 2014 Martin Porrès
** Last update Sun Mar 23 19:58:47 2014 Elliot Kersale
*/

#include	<pthread.h>
#include        "philosophe.h"

char		*choose_name(int i)
{
  char		*name;

  if ((name = malloc(10 * sizeof(char))) == NULL)
  return (NULL);
  if (i == 0)
    name = "Aristote";
  if (i == 1)
    name = "Socrate";
  if (i == 2)
    name = "Diderot";
  if (i == 3)
    name = "Descartes";
  if (i == 4)
    name = "Marx";
  if (i == 5)
    name = "Gandhi";
  if (i == 6)
    name = "Thales";
  return (name);
}

t_list		*create_list(int i)
{
  t_list	*root;

  if ((root = malloc(sizeof(*root))) == NULL)
    perror("");
  else
    {
      root->stick = 1;
      root->status = REST;
      if ((root->name = malloc(strlen(choose_name(0)) * sizeof(char))) == NULL)
	return (NULL);
      root->uid = i;
      root->name = choose_name(i);
      pthread_mutex_init(&(root->mutex), NULL);
      root->prev = root;
      root->next = root;
    }
  return (root);
}

void		empty_list(t_list *list)
{
  t_list	*it;
  t_list	*tmp;
  int		i;

  i = 0;
  it = list;
  while (i < PHILO)
    {
      tmp = it->next;
      free(it);
      it = tmp;
      i++;
    }
}

void		delete_list(t_list **list)
{
  empty_list(*list);
  free(*list);
  *list = NULL;
}

int		add_after(t_list *elem, int i)
{
  t_list	*new_elem;

  if ((new_elem = malloc(sizeof(*new_elem))) == NULL)
      perror("");
  else
    {
      new_elem->stick = 1;
      new_elem->status = REST;
      if ((new_elem->name = malloc(strlen(choose_name(i - 1))
				   * sizeof(char))) == NULL)
	return (EXIT_FAILURE);
      new_elem->uid = i;
      new_elem->name = choose_name(i);
      pthread_mutex_init(&(new_elem->mutex), NULL);
      new_elem->prev = elem;
      new_elem->next = elem->next;
      elem->next->prev = new_elem;
      elem->next = new_elem;
    }
  return (EXIT_SUCCESS);
}
