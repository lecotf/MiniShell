/*
** stringlib.c for stringlib in /home/lecot_f/Minishell2/LETSGO
** 
** Made by Florian Lécot
** Login   <lecot_f@epitech.net>
** 
** Started on  Wed Feb 25 16:13:18 2015 Florian Lécot
** Last update Sun Mar  8 23:35:59 2015 Florian Lécot
*/

#include	<stdlib.h>
#include	"mysh.h"

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  if (str != NULL)
    while (str[i])
      i++;
  return (i);
}

char		*my_strcpy(char *dest, char *src)
{
  unsigned int	i;

  i = 0;
  if (src != NULL)
    {
      while (src[i])
	{
	  dest[i] = src[i];
	  i++;
	}
      dest[i] = '\0';
    }
  return (dest);
}

int		match_str(char *str, char *cmp)
{
  unsigned int	i;

  i = 0;
  if (str == NULL || cmp == NULL)
    return (1);
  if (my_strlen(str) != my_strlen(cmp))
    return (1);
  while (str[i])
    {
      if (str[i] != cmp[i])
        return (1);
      i++;
    }
  return (0);
}

char		*my_strcat(char *dest, char *src)
{
  unsigned int	i;
  unsigned int	j;

  i = 0;
  j = 0;
  if (src == NULL)
    return (NULL);
  if (src && dest)
    {
      while (dest[j])
        j++;
      while (src[i])
        {
          dest[j] = src[i];
          i++;
          j++;
        }
      dest[j] = '\0';
    }
  return (dest);
}
