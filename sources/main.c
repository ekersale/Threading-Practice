/*
** main.c for philosophe in /home/kersal_e/projet_actuels/cpp_nibbler
** 
** Made by Elliot Kersale
** Login   <kersal_e@epitech.net>
** 
** Started on  Thu Mar 13 10:27:44 2014 Elliot Kersale
** Last update Sun Mar 23 19:52:38 2014 Elliot Kersale
*/

#include		"philosophe.h"

int			main()
{
  if (init_thread() == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
