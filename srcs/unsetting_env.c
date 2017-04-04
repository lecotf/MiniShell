/*
** setting_env.c for setting_env.c in /home/lecot_f/Minishell/
** 
** Made by Florian Lécot
** Login   <lecot_f@epitech.net>
** 
** Started on  Sat Jan 31 02:41:15 2015 Florian Lécot
** Last update Sun Mar  8 22:04:42 2015 Florian Lécot
*/

#include	<stdlib.h>
#include	"mysh.h"

int		my_unsetenv(t_env *env, char *name)
{
  while (env)
    {
      if (match_str(env->name, name) == 0)
        if (env->value != NULL)
          {
            free(env->value);
            env->value = NULL;
          }
      env = env->next;
    }
  return (1);
}

void		ignore_env(t_env *env)
{
  while (env)
    {
      if (env->value != NULL)
        {
          free(env->value);
          env->value = NULL;
        }
      env = env->next;
    }
}
