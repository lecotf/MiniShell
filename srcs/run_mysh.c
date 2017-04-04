/*
** run_mysh.c for run_mysh in /home/lecot_f/Minishell2/LETSGO
** 
** Made by Florian Lécot
** Login   <lecot_f@epitech.net>
** 
** Started on  Sun Mar  8 18:44:04 2015 Florian Lécot
** Last update Sun Mar  8 20:55:19 2015 Florian Lécot
*/

#include	<stdlib.h>
#include	"mysh.h"

static int	exec_cmd(t_cmd *cmd_list, t_env *env, int *exit)
{
  int		ret;

  while (cmd_list != NULL)
    {
      if (cmd_list->opt == NULL)
	return (0);
      if (cmd_list->opt[0] == NULL)
	return (0);
      if ((ret = check_builtins(env, cmd_list->opt, exit)) == 42)
	return (42);
      if (ret == 0)
	check_access(env, cmd_list);
      cmd_list = cmd_list->next;
    }
  return (0);
}

int		run_mysh(t_env *env, int *exit)
{
  t_cmd		*cmd_list;
  char		*line;

  line = NULL;
  cmd_list = NULL;
  aff_prompt(env);
  if ((line = get_next_line(0)) == NULL)
    {
      my_putchar('\n', 1);
      return (42);
    }
  if ((cmd_list = make_cmd_list(line, get_nbr_cmd(line))) == NULL)
    return (0);
  if (exec_cmd(cmd_list, env, exit) == 42)
    {
      free_cmd_list(&cmd_list);
      free_str(line);
      return (42);
    }
  free_cmd_list(&cmd_list);
  free_str(line);
  return (0);
}
