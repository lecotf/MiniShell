/*
** make_cmd_list.c for make_cmd_list in /home/lecot_f/Minishell2/LETSGO
** 
** Made by Florian Lécot
** Login   <lecot_f@epitech.net>
** 
** Started on  Mon Mar  2 21:38:07 2015 Florian Lécot
** Last update Sun Mar  8 23:10:51 2015 Florian Lécot
*/

#include		<stdlib.h>
#include		"mysh.h"

static t_cmd		*insert_new_cmd(t_cmd *elem, char *str)
{
  unsigned int		nbr_option;
  int			nbr_redir;
  int			i;

  i = -1;
  nbr_option = (unsigned int)get_nbr_option(str);
  if ((nbr_redir = get_nbr_redir(str)) == -1)
    return (NULL);
  if ((elem = (t_cmd *)malloc(sizeof(t_cmd))) == NULL)
    my_putexit(1);
  elem->opt = NULL;
  if ((elem->opt = (char **)malloc((nbr_option + 1) * sizeof(char *))) == NULL)
    my_putexit(1);
  while (++i < ((int)nbr_option))
    elem->opt[i] = get_option_cmd(str, i);
  elem->opt[i] = NULL;
  elem->rdr = NULL;
  if (nbr_redir > 0)
    elem->rdr = make_redir_list(str, nbr_redir);
  elem->next = NULL;
  return (elem);
}

static t_cmd		*make_elem_cmd_list(t_cmd *list, char *str)
{
  t_cmd			*new_elem;
  t_cmd			*temp;

  temp = list;
  new_elem = NULL;
  if ((new_elem = insert_new_cmd(new_elem, str)) == NULL)
    return (NULL);
  if (list == NULL)
    return (new_elem);
  while (temp->next != NULL)
    temp = temp->next;
  temp->next = new_elem;
  return (list);
}

t_cmd			*make_cmd_list(char *line, int nb_cmd)
{
  t_cmd			*cmd_list;
  char			*cmd;
  int			i;

  i = 0;
  cmd = NULL;
  cmd_list = NULL;
  while (i < nb_cmd)
    {
      cmd = get_cmd_line(line, (i + 1));
      if ((cmd_list = make_elem_cmd_list(cmd_list, cmd)) == NULL)
	return (NULL);
      free_str(cmd);
      i++;
    }
  return (cmd_list);
}

void		free_cmd_list(t_cmd **list)
{
  t_cmd		*temp;
  int		i;

  temp = (*list);
  while ((*list) != NULL)
    {
      i = -1;
      (*list) = (*list)->next;
      if (temp->opt != NULL)
	while (temp->opt[++i] != NULL)
	  free_str(temp->opt[i]);
      if (temp->opt != NULL)
	free(temp->opt);
      if (temp != NULL)
	free(temp);
      temp = (*list);
    }
  if (temp != NULL)
    free(temp);
}
