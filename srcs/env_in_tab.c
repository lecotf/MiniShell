/*
** env_in_tab.c for env_in_tab in /home/lecot_f/Minishell/finish/srcs
** 
** Made by Florian Lécot
** Login   <lecot_f@epitech.net>
** 
** Started on  Sat Jan 31 10:33:55 2015 Florian Lécot
** Last update Sun Mar  8 23:10:31 2015 Florian Lécot
*/

#include	<stdlib.h>
#include	"mysh.h"

static char	*complete_tab(char *elem_tab, char *var_env)
{
  elem_tab = NULL;
  if (var_env != NULL)
    {
      elem_tab = my_malloc((unsigned int)my_strlen(var_env) + 1);
      elem_tab = my_strcpy(elem_tab, var_env);
    }
  return (elem_tab);
}
char		**make_tab_env(char **tab, t_env *env)
{
  unsigned int	i;
  t_env		*temp;

  i = 0;
  temp = env;
  while (temp)
    {
      if (temp->value != NULL)
        i++;
      temp = temp->next;
    }
  if ((tab = (char **)malloc((i + 1) * sizeof(char *))) == NULL)
    my_putexit(1);
  i = 0;
  while (env)
    {
      if ((tab[i] = complete_tab(tab[i], env->value)) != NULL)
	i++;
      env = env->next;
    }
  tab[i] = NULL;
  return (tab);
}
