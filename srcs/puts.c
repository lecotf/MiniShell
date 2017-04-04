/*
** puts.c for puts in /home/lecot_f/Minishell2/LETSGO
** 
** Made by Florian Lécot
** Login   <lecot_f@epitech.net>
** 
** Started on  Wed Feb 25 15:27:08 2015 Florian Lécot
** Last update Thu Mar  5 13:20:07 2015 Florian Lécot
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"mysh.h"

void		my_putchar(char c, int fd)
{
  write(fd, &c, 1);
}

void		my_putstr(char *str)
{
  unsigned int	i;

  i = 0;
  if (str != NULL)
    {
      while (str[i])
	i++;
      write(1, str, i);
    }
}

void		my_put_nbr(int nb, int fd)
{
  if (nb < 0)
    {
      write(1, "-", 1);
      nb = -nb;
    }
  if (nb >= 10)
    my_put_nbr(nb / 10, fd);
  my_putchar((nb % 10) + 48, fd);
}
