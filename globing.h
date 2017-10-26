#ifndef GROBING_H
# define GLOBING_H
typedef struct	s_arg
{
	int				id;
	char			*str;
	struct s_arg	*next;
}				t_arg;
typedef struct	s_new
{
	char			*str;
	struct s_new	*next;
}				t_new;
typedef struct	s_glob
{
	struct s_arg	*arg;
	struct s_new	*new;
	int				p[2];
}				t_glob;
#endif

/*
**gb_match
*/
t_new   *init_new();
t_new   *add_new(t_new *new);
t_new   *check_walcards(t_new *new);
t_new   *do_we_match(t_arg *arg, t_new *new);
/*
**gb_research
*/
t_glob  *init_glob();
t_arg   *init_arg(char *line);
t_glob  *add_arg(t_glob *g, char *line, int a);
t_glob  *globing_research(char **cmd);
/*
**gb_possibility
*/
t_glob  *accolade(t_glob *g, char *line, int *i);
t_glob  *square_bracket(t_glob *g, char *line, int *i);
t_glob  *interogation(t_glob *g, char *line, int *i);
t_glob  *part_arg(t_glob *g, char *line, int *i);
/*
**gb_addword
*/
char    *creat_bracket(int c);
t_new   *add_accolade(t_new *new, char *str);
t_new   *add_interogation(t_new *new);
t_new   *add_word(t_new *new, char *str);
t_new   *sb_ascii_posdup(t_new *new, int c1, int c2);
t_new   *add_square_bracket(t_new *new, char *str);
