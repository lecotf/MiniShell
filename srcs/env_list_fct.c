/*
** env_list_fct.c for env_list_fct in /home/lecot_f/Minishell2/LETSGO
** 
** Made by Florian Lécot
** Login   <lecot_f@epitech.net>
** 
** Started on  Wed Feb 25 16:03:43 2015 Florian Lécot
** Last update Sun Mar  8 18:32:50 2015 Florian Lécot
*/

#include	<stdlib.h>
#include	"mysh.h"

void		show_env(t_env *my_env)
{
  while (my_env)
    {
      if (my_env->value != NULL)
        if (my_env->value[0] != '\0')
          {
            my_putstr(my_env->value);
            my_putstr("\n");
          }
      my_env = my_env->next;
    }
}

void		free_env(t_env **list)
{
  t_env		*temp;

  temp = NULL;
  if (list != NULL)
    {
      temp = (*list);
      while ((*list) != NULL)
        {
          (*list) = (*list)->next;
          if (temp->name)
            free(temp->name);
          if (temp->value)
            free(temp->value);
          free(temp);
          temp = (*list);
        }
      free(temp);
    }
}
