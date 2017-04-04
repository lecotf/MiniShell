/*
** basic_fct.c for basic_fct in /home/lecot_f/Minishell2/LETSGO
** 
** Made by Florian Lécot
** Login   <lecot_f@epitech.net>
** 
** Started on  Wed Feb 25 16:59:08 2015 Florian Lécot
** Last update Mon Mar  2 17:10:48 2015 Florian Lécot
*/

#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	"mysh.h"

void		*my_malloc(unsigned int len)
{
  void		*temp;

  if ((temp = malloc(len)) == NULL)
    my_putexit(1);
  return (temp);
}

void		free_str(char *str)
{
  if (str != NULL)
    free(str);
}
