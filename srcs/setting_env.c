/*
** call_setting_env.c for call_setting_env in /home/lecot_f/Minishell2/LETSGO
** 
** Made by Florian Lécot
** Login   <lecot_f@epitech.net>
** 
** Started on  Sun Mar  8 21:28:32 2015 Florian Lécot
** Last update Sun Mar  8 21:59:32 2015 Florian Lécot
*/

#include	<stdlib.h>
#include	"mysh.h"

static int	check_duplicate_var(t_env *env, char *name)
{
  while (env)
    {
      if (match_str(env->name, name) == 0)
        return (1);
      env = env->next;
    }
  return (0);
}

static void	my_setenv(t_env *env, char *name, char *var)
{
  if (check_duplicate_var(env, name) == 0)
    env = add_end_env_list(env, var);
  else
    while (env)
      {
        if (match_str(env->name, name) == 0)
          {
            if (env->value != NULL)
              free(env->value);
            env->value = NULL;
            env->value = my_malloc((unsigned int)my_strlen(var) + 1);
            env->value = my_strcpy(env->value, var);
          }
        env = env->next;
      }
}

static char	*get_param_setenv(char *str)
{
  char		*name;
  int		i;
  int		j;

  i = -1;
  j = 0;
  name = NULL;
  while ((str[++i] >= 'A' && str[i] <= 'Z') || str[i] == '_')
    j++;
  if (j == 0 || str[i] != '=')
    return (NULL);
  name = my_malloc((unsigned int)j + 1);
  i = 0;
  while (str[i] != '=')
    {
      name[i] = str[i];
      i++;
    }
  return (name);
}

int		call_setenv(t_env *env, char **line)
{
  char		*name;

  name = NULL;
  if (line[1] == NULL)
    {
      my_puterror("Usage : setenv NAME=value.\n");
      return (1);
    }
  if ((name = get_param_setenv(line[1])) == NULL)
    {
      my_puterror("Usage : setenv NAME=value.\n");
      return (1);
    }
  my_setenv(env, name, line[1]);
  free_str(name);
  return (1);
}
