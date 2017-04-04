/*
** redir.c for redir in /home/lecot_f/Minishell2/LETSGO
** 
** Made by Florian Lécot
** Login   <lecot_f@epitech.net>
**
** Started on  Sun Mar  8 22:19:41 2015 Florian Lécot
** Last update Sun Mar  8 23:17:17 2015 Florian Lécot
*/

#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<sys/wait.h>
#include	<stdlib.h>
#include	"mysh.h"

static int	right_redir(t_rdr *rdr_list)
{
  int           new_stdout;

  if (rdr_list->type == 1)
    if ((rdr_list->fd_file = open(rdr_list->file,
				  O_WRONLY | O_TRUNC | O_CREAT, 0644)) == -1)
      {
	my_puterror("Error : Couldn't open \"");
	my_puterror(rdr_list->file);
	my_puterror("\".\n");
      }
  if (rdr_list->type == 2)
    if ((rdr_list->fd_file = open(rdr_list->file,
				  O_WRONLY | O_APPEND | O_CREAT, 0644)) == -1)
      {
        my_puterror("Error : Couldn't open \"");
        my_puterror(rdr_list->file);
        my_puterror("\".\n");
      }
  close(1);
  new_stdout = dup(rdr_list->fd_file);
  return (new_stdout);
}

int		check_redir(t_rdr *rdr_list)
{
  if (rdr_list)
    {
      if (rdr_list->type == 1 || rdr_list->type == 2)
	return (right_redir(rdr_list));
      else
	return (1);
    }
  return (0);
}
