/*
** check_builtins.c for check_builtins in /home/lecot_f/Minishell/
** 
** Made by Florian Lécot
** Login   <lecot_f@epitech.net>
**
** Started on  Sat Jan 31 03:18:03 2015 Florian Lécot
** Last update Sun Mar  8 23:10:15 2015 Florian Lécot
*/

#include	<stdlib.h>
#include	"mysh.h"

static int	match_command(char *str, char *cmp)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  if (str == NULL || cmp == NULL)
    return (1);
  while (str[i] != '\0' && str[i] <= ' ')
    i++;
  while (str[i] > ' ' && str[i])
    {
      if (str[i] != cmp[j])
	return (1);
      i++;
      j++;
    }
  if (j != my_strlen(cmp))
    return (1);
  while (str[i])
    {
      if (str[i] > ' ')
	return (1);
      i++;
    }
  return (0);
}

int		check_builtins(t_env *env, char **line, int *exit)
{
  if (match_command(line[0], "env") == 0)
    {
      if (line[1] == NULL)
	show_env(env);
      else if ((match_command(line[1], "-i") == 0) && line[2] == NULL)
	ignore_env(env);
      else
	return (0);
      return (1);
    }
  if (match_command(line[0], "setenv") == 0)
    return (call_setenv(env, line));
  if (match_command(line[0], "unsetenv") == 0)
    {
      if (line[1] == NULL)
	my_puterror("Usage : unsetenv NAME\n");
      return (my_unsetenv(env, line[1]));
    }
  if (match_command(line[0], "exit") == 0)
    {
      if (line[1] != NULL)
	*exit = my_atoi(line[1]);
      return (42);
    }
  return (0);
}
