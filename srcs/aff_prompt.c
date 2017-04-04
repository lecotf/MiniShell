/*
** aff_prompt.c for aff_prompt in /home/lecot_f/Minishell2/LETSGO/srcs
** 
** Made by Florian Lécot
** Login   <lecot_f@epitech.net>
** 
** Started on  Fri Feb 27 00:12:50 2015 Florian Lécot
** Last update Sun Mar  8 18:32:35 2015 Florian Lécot
*/

#include	<stdlib.h>
#include	"mysh.h"

static void	make_prompt(char *user, char *pwd, char *home)
{
  unsigned int	i;

  i = 0;
  my_putstr(user);
  my_putstr(" in ");
  while (home[i] == pwd[i])
    i++;
  my_putchar('~', 1);
  while (pwd[i])
    {
      my_putchar(pwd[i], 1);
      i++;
    }
}

void		aff_prompt(t_env *env)
{
  char		*user;
  char		*pwd;
  char		*home;

  user = NULL;
  pwd = NULL;
  home = NULL;
  user = my_getenv(env, "USER=");
  pwd = my_getenv(env, "PWD=");
  home = my_getenv(env, "HOME=");
  my_putstr("# ");
  if (user == NULL || home == NULL || pwd == NULL)
    my_putstr("BabouSH");
  else
    make_prompt(user, pwd, home);
  my_putstr(" : ");
  free_str(user);
  free_str(pwd);
  free_str(home);
}
