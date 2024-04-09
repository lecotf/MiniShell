#include	<stdlib.h>
#include	<unistd.h>
#include	"mysh.h"

static void	aff_command_error(char msg, char *str)
{
  if (msg == 1)
    my_puterror("BabouSH: command not found: ");
  else
    my_puterror("BabouSH: permission denied : ");
  my_puterror(str);
  my_putchar('\n', 2);
}

static int	check_permission(char *path_command, char *command)
{
  if (access(path_command, X_OK) == 0)
    return (0);
  else
    aff_command_error(2, command);
  return (1);
}

static void	free_double_tab(char **tab, char **tab_)
{
  unsigned int	i;

  i = 0;
  while (tab[i])
    {
      free_str(tab[i]);
      i++;
    }
  if (tab[i] != NULL)
    free_str(tab[i]);
  if (tab != NULL)
    free(tab);
  i = 0;
  while (tab_[i])
    {
      free_str(tab_[i]);
      i++;
    }
  if (tab_[i] != NULL)
    free_str(tab_[i]);
  if (tab_ != NULL)
    free(tab_);
}

int		check_access(t_env *env, t_cmd *cmd_list)
{
  char		**path;
  char		**env_tab;
  char		*path_command;
  int		i;

  i = 0;
  path = get_path(env);
  path_command = NULL;
  env_tab = NULL;
  env_tab = make_tab_env(env_tab, env);
  while (path[i])
    {
      path_command = make_path_command(path[i], cmd_list->opt[0]);
      if (access(path_command, F_OK) == 0)
	{
	  if (check_permission(path_command, cmd_list->opt[0]) == 0)
	    my_exec(path_command, cmd_list, env_tab);
	  free_double_tab(env_tab, path);
	  return (0);
	}
      i++;
    }
  aff_command_error(1, cmd_list->opt[0]);
  free_double_tab(env_tab, path);
  return (0);
}
