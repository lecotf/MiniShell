/*
** exec_bin.c for exec_bin in /home/lecot_f/Minishell/finish/srcs
** 
** Made by Florian Lécot
** Login   <lecot_f@epitech.net>
** 
** Started on  Sat Jan 31 10:30:12 2015 Florian Lécot
** Last update Sun Mar  8 23:16:14 2015 Florian Lécot
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/wait.h>
#include	"mysh.h"

char		*make_path_command(char *path, char *command)
{
  char		*path_command;

  path_command = NULL;
  path_command = my_malloc((unsigned int)my_strlen(path) +
			   (unsigned int)my_strlen(command) + 2);
  path_command = my_strcpy(path_command, path);
  path_command[my_strlen(path)] = '/';
  path_command[my_strlen(path) + 1] = '\0';
  path_command = my_strcat(path_command, command);
  return (path_command);
}

void		my_exec(char *path_command, t_cmd *cmd_list, char **env)
{
  pid_t		pid;
  int		statut;
  int		stdout;

  stdout = -1;
  pid = fork();
  if (pid == -1)
    my_puterror("Error : impossible to duplicate the process.n");
  else if (pid == 0)
    {
      check_redir(cmd_list->rdr);
      if (execve(path_command, cmd_list->opt, env) != -1)
	my_puterror("Error : unable to run the command.\n");
      if (stdout != -1)
	close(cmd_list->rdr->fd_file);
      exit(1);
    }
  else
    wait(&statut);
  free_str(path_command);
}
