/*
** main.c for main in /home/lecot_f/Minishell2/LETSGO
** 
** Made by Florian Lécot
** Login   <lecot_f@epitech.net>
** 
** Started on  Sun Mar  8 18:44:14 2015 Florian Lécot
** Last update Sun Mar  8 19:00:01 2015 Florian Lécot
*/

#include	<stdlib.h>
#include	<signal.h>
#include	"mysh.h"

int		main(int ac, char **av, char **env)
{
  t_env		*my_env;
  int		exit;

  (void)ac;
  (void)av;
  exit = 0;
  my_env = NULL;
  signal(SIGINT, SIG_IGN);
  my_env = set_env(my_env, env);
  while (run_mysh(my_env, &exit) != 42);
  free_env(&my_env);
  return (exit);
}
