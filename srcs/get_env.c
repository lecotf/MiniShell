/*
** get_env.c for get_env in /home/lecot_f/Minishell
** 
** Made by Florian Lécot
** Login   <lecot_f@epitech.net>
** 
** Started on  Thu Jan 29 04:34:08 2015 Florian Lécot
** Last update Fri Feb 27 00:32:08 2015 Florian Lécot
*/

#include	<stdlib.h>
#include	"mysh.h"

static char	*get_name_var_env(char *name, int size_name)
{
  char		*value;
  int		i;

  i = 0;
  value = NULL;
  value = my_malloc((unsigned int)my_strlen(name));
  while (name[i + size_name])
    {
      value[i] = name[i + size_name];
      i++;
    }
  value[i] = '\0';
  return (value);
}

static int	find_var_env(char *value, char *elem)
{
  int		i;

  i = 0;
  if (elem[i] == '\0')
    return (1);
  while (elem[i])
    {
      if (elem[i] == value[i])
        i++;
      else
        return (1);
    }
  return (0);
}

char		*my_getenv(t_env *env, char *elem)
{
  char		*ret;

  ret = NULL;
  while (env != NULL)
    {
      if (env->value != NULL)
        if (env->value[0] != '\0')
          if (find_var_env(env->value, elem) == 0)
            {
              ret = get_name_var_env(env->value, my_strlen(elem));
              return (ret);
            }
      env = env->next;
    }
  return (NULL);
}
