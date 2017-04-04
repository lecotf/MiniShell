/*
** make_my_env.c for make_my_env in /home/lecot_f/Minishell/my_env/merge
** 
** Made by Florian Lécot
** Login   <lecot_f@epitech.net>
** 
** Started on  Sat Jan 31 02:53:06 2015 Florian Lécot
** Last update Sun Mar  8 19:45:23 2015 Florian Lécot
*/

#include		<stdlib.h>
#include		"mysh.h"

static unsigned int	size_name(char *str)
{
  unsigned int		i;

  i = 0;
  while ((str[i] != '=' || str[i] == '_') && str[i])
    i++;
  return (i);
}

static char		*get_name(char *dest, char *src)
{
  unsigned int		i;

  i = 0;
  while (src[i] != '=' && src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

static t_env		*insert_new_elem(t_env *elem, char *str)
{
  if ((elem = (t_env *)malloc(sizeof(t_env))) == NULL)
    exit(EXIT_FAILURE);
  elem->name = NULL;
  elem->value = NULL;
  elem->name = my_malloc(size_name(str) + 1);
  elem->name = get_name(elem->name, str);
  elem->value = my_malloc((unsigned int)my_strlen(str) + 1);
  elem->value = my_strcpy(elem->value, str);
  elem->next = NULL;
  return (elem);
}

t_env			*add_end_env_list(t_env *list, char *str)
{
  t_env			*new_elem;
  t_env			*temp;

  temp = list;
  new_elem = NULL;
  new_elem = insert_new_elem(new_elem, str);
  if (list == NULL)
    return (new_elem);
  while (temp->next != NULL)
    temp = temp->next;
  temp->next = new_elem;
   return (list);
}

t_env			*set_env(t_env *my_env, char **env)
{
  int			i;

  i = -1;
  if (env != NULL)
    while (env[++i] != NULL)
      my_env = add_end_env_list(my_env, env[i]);
  return (my_env);
}
