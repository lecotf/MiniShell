/*
** get_redir.c for get_redir in /home/lecot_f/Minishell2/LETSGO
** 
** Made by Florian Lécot
** Login   <lecot_f@epitech.net>
** 
** Started on  Sun Mar  8 02:13:28 2015 Florian Lécot
** Last update Sun Mar  8 15:04:50 2015 Florian Lécot
*/

#include	<stdlib.h>
#include	"mysh.h"

static char	*get_name_file(char *line, int i)
{
  char		*name_file;
  unsigned int	len;
  int		j;

  name_file = NULL;
  len = 0;
  j = i;
  while (line[i] != '\0' && line[i] != ' ' && line[i] != '\t' &&
	 line[i] != '<' && line[i] != '>')
    {
      len++;
      i++;
    }
  name_file = my_malloc(len + 1);
  i = 0;
  while (line[j] != '\0' && line[j] != ' ' && line[j] != '\t' &&
	 line[j] != '<' && line[j] != '>')
    {
      name_file[i] = line[j];
      i++;
      j++;
    }
  name_file[i] = '\0';
  return (name_file);
}

static void	get_type_redir(char *line, int *type, int i)
{
  if (line[i] == '>')
    *type = 1;
  else
    *type = 3;
  if (line[i + 1] == line[i])
    (*type)++;
}

char		*get_nfo_redir(char *line, int *type, int nb)
{
  int		i;

  i = -1;
  while (line[++i])
    {
      if (line[i] == '>' || line[i] == '<')
	{
	  get_type_redir(line, type, i);
	  if (line[i + 1] == line[i])
	    i++;
	  i++;
	  nb--;
	  if (nb == 0)
	    {
	      while (line[i] == ' ' || line[i] == '\t')
		i++;
	      return (get_name_file(line, i));
	    }
	}
    }
  return (NULL);
}
