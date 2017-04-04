/*
** puts_error.c for puts_error in /home/lecot_f/Minishell2/LETSGO
** 
** Made by Florian Lécot
** Login   <lecot_f@epitech.net>
** 
** Started on  Thu Mar  5 13:19:03 2015 Florian Lécot
** Last update Sun Mar  8 18:25:15 2015 Florian Lécot
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"mysh.h"

void		my_puterror(char *str)
{
  unsigned int	i;

  i = 0;
  if (str != NULL)
    {
      while (str[i])
        i++;
      write(2, str, i);
    }
}

int		puts_parse_error(char c, int rank_char)
{
  my_puterror("BabouSH : parse error near `");
  write(2, &c, 1);
  my_puterror("\" (");
  my_put_nbr(rank_char, 2);
  my_putstr(").\n");
  return (-1);
}

int		my_putexit(char error)
{
  if (error == 1)
    my_puterror("Error : Couldn't alloc memory.\n");
  else if (error == 2)
    my_puterror("Error : Couldn't read.\n");
  else
    my_puterror("An error has occured.\n");
  exit(1);
}
