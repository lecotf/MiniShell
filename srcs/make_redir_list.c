/*
** make_redir_list.c for make_redir_list in /home/lecot_f/Minishell2/LETSGO
** 
** Made by Florian Lécot
** Login   <lecot_f@epitech.net>
** 
** Started on  Sun Mar  8 04:32:42 2015 Florian Lécot
** Last update Sun Mar  8 22:31:06 2015 Florian Lécot
*/

#include		<stdlib.h>
#include		"mysh.h"

static t_rdr		*insert_new_redir(t_rdr *elem, char *line, int redir)
{
  if ((elem = (t_rdr *)malloc(sizeof(t_rdr))) == NULL)
    exit(EXIT_FAILURE);
  elem->type = 0;
  elem->fd_file = -1;
  elem->file = NULL;
  elem->file = get_nfo_redir(line, &elem->type, redir);
  elem->next = NULL;
  return (elem);
}

static t_rdr		*make_elem_rdr_list(t_rdr *list, char *line, int redir)
{
  t_rdr			*new_elem;
  t_rdr			*temp;

  temp = list;
  new_elem = NULL;
  new_elem = insert_new_redir(new_elem, line, redir);
  if (list == NULL)
    return (new_elem);
  while (temp->next != NULL)
    temp = temp->next;
  temp->next = new_elem;
   return (list);
}

t_rdr			*make_redir_list(char *line, int nbr_redir)
{
  t_rdr			*rdr_list;
  int			i;

  i = 1;
  rdr_list = NULL;
  while (i <= nbr_redir)
    {
      rdr_list = make_elem_rdr_list(rdr_list, line, i);
      i++;
    }
  return (rdr_list);
}
