/*
** my_atoi.c for my_atoi in /home/lecot_f/Minishell2/LETSGO
** 
** Made by Florian Lécot
** Login   <lecot_f@epitech.net>
** 
** Started on  Sun Mar  8 19:39:41 2015 Florian Lécot
** Last update Sun Mar  8 23:19:15 2015 Florian Lécot
*/

#include	"mysh.h"

int		my_atoi(char *str)
{
  int		nbr;
  int		compt;
  int		sign;
  int		of;

  nbr = 0;
  compt = -1;
  sign = 1;
  of = 0;
  while ((str[++compt] == '+' || str[compt] == '-') && str[compt] != '\0')
    {
      if (str[compt] == '-')
        sign = sign * -1;
    }
  while ((str[compt] >= '0' && str[compt] <= '9') && str[compt] != '\0')
    {
      of = nbr;
      nbr = nbr * 10 + str[compt] - '0';
      compt++;
    }
  if (nbr / 10 != of)
    return (0);
  nbr = nbr * sign;
  return (nbr);
}
