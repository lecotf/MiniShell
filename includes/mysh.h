/*
** mysh.h for mysh in /home/lecot_f/Minishell2/LETSGO/includes
**
** Made by Florian Lécot
** Login   <lecot_f@epitech.net>
**
** Started on  Tue Feb 24 17:48:50 2015 Florian Lécot
** Last update Tue Apr  4 10:35:51 2017 
*/

#ifndef		MYSH_H_
#define		MYSH_H_

# define	SIZE_BUFFER	128

typedef	struct	s_env
{
  char		*name;
  char		*value;
  struct s_env	*next;
}		t_env;

typedef	struct	s_rdr
{
  int		type;
  int		fd_file;
  char		*file;
  struct s_rdr	*next;
}		t_rdr;

typedef	struct	s_cmd
{
  char		**opt;
  struct s_rdr	*rdr;
  struct s_cmd	*next;
}		t_cmd;

t_env		*set_env(t_env *, char **);
t_env		*add_end_env_list(t_env *, char *);
t_cmd		*make_cmd_list(char *, int);
t_rdr		*make_redir_list(char *, int);
char		**str_twt(char **, char *, int);
char		**get_path(t_env *);
char		**make_tab_env(char **, t_env *);
char		*get_next_line(const int);
char		*my_getenv(t_env *, char *);
char		*my_strcpy(char *, char *);
char		*my_strcat(char *, char *);
char		*get_cmd_line(char *, int);
char		*make_path_command(char *, char *);
char		*get_nfo_redir(char *, int *, int);
char		*get_option_cmd(char *, int);
int		run_mysh(t_env *, int *);
int		puts_parse_error(char, int);
int		check_access(t_env *, t_cmd *);
int		get_nbr_cmd(char *);
int		check_redir(t_rdr *);
int		get_nbr_redir(char *);
int		get_nbr_option(char *);
int		check_builtins(t_env *, char **, int *);
int		call_setenv(t_env *, char **);
int		my_unsetenv(t_env *, char *);
int		match_str(char *, char *);
int		my_strlen(char *);
int		my_putexit(char);
int		my_atoi(char *);
int		run_mysh(t_env *, int *);
void		*my_malloc(unsigned int);
void		my_putstr(char *);
void		my_puterror(char *);
void		my_putchar(char, int);
void		my_put_nbr(int, int);
void		aff_prompt(t_env *);
void		show_env(t_env *);
void		ignore_env(t_env *);
void		free_env(t_env **);
void		free_str(char *);
void		free_cmd_list(t_cmd **);
void		my_exec(char *, t_cmd *, char **);

#endif		/* !MYSH_H_ */
