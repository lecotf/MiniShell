/*
** parse_redir.c for parse_redir in /home/lecot_f/Minishell2/LETSGO
** 
** Made by Florian Lécot
** Login   <lecot_f@epitech.net>
** 
** Started on  Tue Mar  3 16:38:13 2015 Florian Lécot
** Last update Sun Mar  8 18:47:43 2015 Florian Lécot
*/

#include	"mysh.h"

static int	check_parse_pre_redir(char *line, int *i)
{
  char		red;
  char		err;

  red = line[*i];
  err = '>';
  if (red == err)
    err = '<';
  if (line[0] == '<' || line[0] == '>')
    return (puts_parse_error(red, 1));
  if ((*i == 1) && ((line[0] >= '!' && line[0] <= '#') ||
		    (line[0] >= 39 && line[0] <= ')') ||
		    (line[0] >= '{' && line[0] <= '~') ||
		    line[0] == '`' || line[0] == err))
    return (puts_parse_error(red, *i + 1));
  if ((*i > 1 && line[*i - 2] != '\\') &&
      ((line[*i - 1] >= '!' && line[*i - 1] <= '#') ||
       (line[*i - 1] >= 39 && line[*i - 1] <= '(') ||
       (line[*i - 1] >= '{' && line[*i - 1] <= '~') || line[*i - 1] == '`'))
    return (puts_parse_error(red, *i + 1));
  return (0);
}

static int	check_parse_post_redir(char *line, int *i, int *j)
{
  if ((line[*i] < '%') || (line[*i] > '%' && line[*i] < '+') ||
      (line[*i] > '-' && line[*i] < '0') ||
      (line[*i] > ':' && line[*i] < '=') ||
      (line[*i] > '=' && line[*i] < '@') ||
      line[*i] == '[' || line[*i] == ']' ||
      line[*i] == '^' || line[*i] == '`' || line[*i] > 'z')
    return (puts_parse_error(line[*j], *j + 1));
  return (0);
}

int		get_nbr_redir(char *line)
{
  int		nbr_cmd;
  int		i;
  int		j;

  i = -1;
  nbr_cmd = 0;
  while (line[++i])
    {
      if (line[i] == '>' || line[i] == '<')
	{
	  j = i;
	  if (check_parse_pre_redir(line, &i) == -1)
	    return (1);
	  if (line[i + 1] == line[i])
	    i++;
	  i++;
	  while (line[i] == ' ' || line[i] == '\t')
	    i++;
	  if (check_parse_post_redir(line, &i, &j) == -1)
	    return (1);
	  nbr_cmd++;
	}
    }
  return (nbr_cmd);
}
