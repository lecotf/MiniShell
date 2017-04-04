/*
** parse_cmd.c for parse_cmd in /home/lecot_f/Minishell2/LETSGO
** 
** Made by Florian Lécot
** Login   <lecot_f@epitech.net>
** 
** Started on  Fri Feb 27 18:58:19 2015 Florian Lécot
** Last update Sun Mar  8 18:47:10 2015 Florian Lécot
*/

#include	<stdlib.h>
#include	"mysh.h"

static int	check_parse_error(char *line, int *i)
{
  if ((*i > 1 && line[*i - 2] != '\\' && line[*i - 1] == ';' &&
       line[*i] == ';') || (*i == 1 && line[*i - 1] == ';' && line[*i] == ';'))
    return (puts_parse_error(';', *i + 1));
  return (0);
}

static int	check_end_value(char *line, int end)
{
  if ((end > 0) && (line[end] == ';' && line[end - 1] <= ' '))
    end--;
  while (line[end] == '\0' || line[end] == ' ' || line[end] == '\t')
    end--;
  if (line[end] > ' ' && line[end] != ';')
    end++;
  if ((end > 0 ) && (line[end] == ';' && line[end - 1] == '\\'))
    end++;
  return (end);
}

static char	*make_cmd(char *line, int begin, int end)
{
  char		*cmd;
  int		size;
  int		i;

  i = -1;
  if (begin == end)
    begin--;
  while (begin > 0 && (line[begin] == ' ' || line[begin] == '\t'))
    begin--;
  if ((begin == 1 && line[begin] == ';') && (line[begin - 1] == '\\'))
    begin--;
  end = check_end_value(line, end);
  size = end - begin;
  cmd = NULL;
  cmd = my_malloc((unsigned int)size + 1);
  while (begin < end)
    {
      cmd[++i] = line[begin];
      begin++;
    }
  cmd[++i] = '\0';
  return (cmd);
}

int		get_nbr_cmd(char *line)
{
  int		i;
  int		nb;
  int		valid_line;

  i = -1;
  nb = 0;
  valid_line = 0;
  while (line[++i])
    {
      if (line[i] > ' ' && line[i] != ';')
	valid_line++;
      if (i > 0 && line[i] == ';' && line[i - 1] != '\\' && valid_line != 0)
	{
	  nb++;
	  valid_line = 0;
	}
      if (check_parse_error(line, &i) == -1)
	return (0);
    }
  return ((valid_line > 0) ? ++nb : nb);
}

char		*get_cmd_line(char *line, int final_cmd)
{
  int		i;
  int		current_cmd;
  int		valid_line;
  int		begin;

  i = -1;
  current_cmd = 0;
  valid_line = 0;
  begin = 0;
  while (line[++i])
    {
      if (line[i] > ' ' && line[i] != ';')
	valid_line++;
      if (valid_line == 1)
	begin = i;
      if (i > 0 && line[i] == ';' && line[i - 1] != '\\' && valid_line != 0)
	{
          current_cmd++;
          valid_line = 0;
	  if (current_cmd == final_cmd)
	    return (make_cmd(line, begin, i));
	}
    }
  return (make_cmd(line, begin, i));
}
