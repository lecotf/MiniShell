/*
** get_option_cmd.c for get_option_cmd in /home/lecot_f/Minishell2/LETSGO
** 
** Made by Florian Lécot
** Login   <lecot_f@epitech.net>
** 
** Started on  Sun Mar  8 12:43:28 2015 Florian Lécot
** Last update Sun Mar  8 23:17:57 2015 Florian Lécot
*/

#include	<stdlib.h>
#include	"mysh.h"

static char	*make_elem_option(char *line, int i)
{
  char		*elem_option;
  int		j;

  elem_option = NULL;
  j = i;
  while (line[i] > ' ' && ((i > 0 && line[i - 1] == '\\') ||
			   (line[i] != '>' && line[i] != '<')))
    i++;
  elem_option = my_malloc((unsigned int)(i - j) + 1);
  i = 0;
  while (line[j] > ' ' && ((j > 0 && line[j - 1] == '\\') ||
			   (line[j] != '>' && line[j] != '<')))
    {
      elem_option[i] = line[j];
      i++;
      j++;
    }
  elem_option[i] = '\0';
  return (elem_option);
}

static int	skip_redir(char *line, int i)
{
  if (line[i] == '>' || line[i] == '<')
    {
      while (line[i] == '>' || line[i] == '<' ||
	     (line[i] <= ' ' && line[i] != '\0'))
	i++;
      while (line[i] > ' ' && ((i > 0 && line[i - 1] == '\\') ||
			       (line[i] != '>' && line[i] != '<')))
	i++;
    }
  return (i);
}

char		*get_option_cmd(char *line, int nbr_option)
{
  int		i;

  i = 0;
  while (line[i] != '\0')
    {
      while (line[i] <= ' ' && line[i] != '\0')
        i++;
      if (line[i] > ' ' && ((i > 0 && line[i - 1] == '\\') ||
                            (line[i] != '>' && line[i] != '<')))
        {
	  if (nbr_option == 0)
	    return (make_elem_option(line, i));
          nbr_option--;
          while (line[i] > ' ' && ((i > 0 && line[i - 1] == '\\') ||
                                   (line[i] != '>' && line[i] != '<')))
            i++;
        }
      i = skip_redir(line, i);
      if (line[i])
        i++;
    }
  return (NULL);
}

int		get_nbr_option(char *line)
{
  int		nbr;
  int		i;

  i = 0;
  nbr = 0;
  while (line[i] != '\0')
    {
      while (line[i] <= ' ' && line[i] != '\0')
	i++;
      if (line[i] > ' ' && ((i > 0 && line[i - 1] == '\\') ||
			    (line[i] != '>' && line[i] != '<')))
	{
	  nbr++;
	  while (line[i] > ' ' && ((i > 0 && line[i - 1] == '\\') ||
				   (line[i] != '>' && line[i] != '<')))
	    i++;
	}
      i = skip_redir(line, i);
      if (line[i])
	i++;
    }
  return (nbr);
}
