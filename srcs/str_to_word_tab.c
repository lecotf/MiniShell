/*
** str_to_word_tab.c for str_to_word_tab in /home/lecot_f/Minishell
** 
** Made by Florian Lécot
** Login   <lecot_f@epitech.net>
** 
** Started on  Thu Jan 29 06:21:05 2015 Florian Lécot
** Last update Sun Mar  8 20:51:26 2015 Florian Lécot
*/

#include		<stdlib.h>
#include		"mysh.h"

static int		check_allowed_char(char c, int option)
{
  if (option == 0)
    {
      if (c > ' ')
	return (0);
      else
	return (1);
    }
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
      || (c >= '0' && c <= '9') || c == '/')
    return (0);
  else
    return (1);
}

static unsigned int	nbr_words(char *str, int option)
{
  unsigned int		i;
  unsigned int		ret;

  i = 0;
  ret = 0;
  while (str[i])
    {
      if (check_allowed_char(str[i], option) == 0)
        {
          ret++;
	  while (check_allowed_char(str[i], option) == 0)
            i++;
        }
      else
        i++;
    }
  return (ret);
}

static unsigned int	len_words(char *str, int option, unsigned int *i)
{
  unsigned int		ret;

  ret = 0;
  while (str[(*i)])
    {
      if (check_allowed_char(str[(*i)], option) == 0)
        {
          while (check_allowed_char(str[(*i)], option) == 0)
            {
              ret++;
              (*i)++;
            }
          return (ret);
        }
      else
        (*i)++;
    }
  return (ret);
}

static char	*cpy_words(char *dest, char *src, int option, unsigned int *i)
{
  unsigned int	j;

  j = 0;
  while (src[(*i)])
    {
      if (check_allowed_char(src[(*i)], option) == 0)
        {
          while (check_allowed_char(src[(*i)], option) == 0)
            {
              dest[j] = src[(*i)];
              (*i)++;
              j++;
            }
          dest[j] = '\0';
          return (dest);
        }
      else
        (*i)++;
    }
  return (dest);
}

char			**str_twt(char **tab, char *str, int option)
{
  unsigned int		size_tab;
  unsigned int		i;
  unsigned int		compt_len;
  unsigned int		compt_cpy;

  i = 0;
  compt_len = 0;
  compt_cpy = 0;
  if (str == NULL)
    return (NULL);
  size_tab = (nbr_words(str, option) + 1);
  if ((tab = (char **)malloc((size_tab) * sizeof(char *))) == NULL)
    my_putexit(1);
  while (i < (size_tab - 1))
    {
      tab[i] = my_malloc((len_words(str, option, &compt_len)) + 1);
      tab[i] = cpy_words(tab[i], str, option, &compt_cpy);
      i++;
    }
  tab[i] = NULL;
  return (tab);
}
