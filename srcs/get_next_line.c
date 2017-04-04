/*
** Made by Florian Lécot
** Email : <contact.florianlecot@gmail.com>
** 
** Started on  Tue Nov  8 16:03:38 2016 
** Last update Tue Apr  4 10:36:03 2017 
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "mysh.h"

static char		*ret_line(char *line, char *buffer, ssize_t *compt, ssize_t size_line)
{
  const char		*temp;
  ssize_t		len_line;
  ssize_t		i;

  errno = 0;
  if (line == NULL)
    {
      if ((line = malloc((size_t)size_line + 1)) == NULL)
	{
	  fprintf(stderr, "Error : Couldn't allocate memory (%s).\n", strerror(errno));
	  exit(EXIT_FAILURE);
	}
      len_line = 0;
    }
  else
    {
      for (temp = line; *temp; ++temp);
      len_line = temp - line;
      if ((line = realloc(line, (size_t)len_line + (size_t)size_line + 1)) == NULL)
	{
	  fprintf(stderr, "Error : Couldn't reallocate memory (%s).\n", strerror(errno));
	  exit(EXIT_FAILURE);
	}
    }
  for (i = 0; i < size_line; i++)
    line[len_line + i] = buffer[(*compt) + i];
  line[len_line + i] = '\0';
  *compt += size_line + 1;
  return (line);
}

char			*get_next_line(const int fd)
{
  static char		buffer[SIZE_BUFFER + 1];
  static ssize_t	compt = 0;
  static ssize_t	size_read = 0;
  ssize_t		size_line;
  char			*line;

  for (size_line = 0, line = NULL, errno = 0 ;; size_line++)
    {
      if (compt >= size_read)
	{
	  compt = 0;
	  size_line = 0;
	  if ((size_read = read(fd, buffer, SIZE_BUFFER)) < 0)
	    fprintf(stderr, "Error : Couldn't read (%s).\n", strerror(errno));
	  if (size_read <= 0)
	    return (line);
	}
      if (buffer[compt + size_line] == '\n')
	return (ret_line(line, buffer, &compt, size_line));
      if (compt + size_line == (size_read - 1))
	line = ret_line(line, buffer, &compt, (size_line + 1));
    }
}
