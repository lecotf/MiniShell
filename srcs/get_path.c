/*
** get_path.c for get_path in /home/lecot_f/Minishell
** 
** Made by Florian Lécot
** Login   <lecot_f@epitech.net>
** 
** Started on  Thu Jan 29 10:34:38 2015 Florian Lécot
** Last update Tue Nov 15 10:57:42 2016 
*/

#include	<stdlib.h>
#include	"mysh.h"

char		**get_path(t_env *env)
{
  char		**path;
  char		*str;

  path = NULL;
  str = NULL;
  if ((path = str_twt(path, (str = my_getenv(env, "PATH=")), 1)) == NULL)
    {
      if ((path = (char **)malloc((1) * sizeof(char *))) == NULL)
	my_putexit(1);
      path[0] = 0;
    }
  free_str(str);
  return (path);
}
