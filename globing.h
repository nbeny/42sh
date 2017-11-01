#ifndef GLOBING_H
# define GLOBING_H

#include <stdlib.h>
#include "globing/libft/include/libft.h"
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
	int				isrep;
	struct s_arg	*arg;
	struct s_new	*new;
	int				p[2];
	struct s_glob	*slash;
	struct s_glob	*next;
}				t_glob;
/*
**gb_tools.c
*/
t_new   *get_no_ascii(t_new *s, char *str, int *i, t_new *s_izi);
t_new   *get_ascii(t_new *s, char *str, int *i, t_new *izi);
t_new   *check_class(t_new *s, char *class, t_new *s_izi);
t_new   *get_class_posix(t_new *s, char *str, int *i, t_new *s_izi);
/*
**gb_tools1.c
*/
t_new   *get_not_ascii_dup(char *str, int *i, t_new *s_izi);
t_new   *get_ascii_dup(char *str, int *i, t_new *s_izi);
t_new   *check_class_dup(char *class, t_new *s_izi);
t_new   *get_class_posix_dup(char *str, int *i, t_new *s_izi);
/*
**gb_match
*/
t_new   *init_new();
t_new   *add_new(t_new *new);
int     nmatch(char *s1, char *s2);
t_new   *check_walcards(t_new *new);
t_new   *do_we_match(t_arg *arg, t_new *new);

/*
**gb_research
*/
t_glob  *init_glob();
t_arg   *init_argument();
t_glob  *add_arg(t_glob *g, char *line, int a);
t_glob  *globing_research(char **cmd);
t_glob	*add_glob_next(t_glob *g);
t_glob	*add_glob_slash(t_glob *g);
t_glob  *zoom_research(t_glob *g, char *line);
/*
**gb_possibility
*/
t_glob  *accolade(t_glob *g, char *line, int *i);
t_glob  *square_bracket(t_glob *g, char *line, int *i);
t_glob  *interogation(t_glob *g, char *line, int *i);
t_glob  *part_arg(t_glob *g, char *line, int *i);
t_glob  *slash_gestion(t_glob *g, char *line, int *i);
/*
**gb_addword
*/
char    *creat_bracket(int c);
t_new   *add_accolade(t_new *new, char *str);
t_new   *add_interogation(t_new *new);
t_new   *add_word(t_new *new, char *str);
t_new   *sb_ascii_posjoin(t_new *s, int c1, int c2, t_new *izi);
t_new   *sb_ascii_posdup(t_new *new, int c1, int c2);
t_new   *sb_not_this_ascii_posdup(t_new *new, int c1, int c2);
t_new   *sb_not_ascii_posjoin(t_new *s, int c1, int c2, t_new *izi);
t_new   *add_square_bracket(t_new *new, char *str);
/*
**globing_class.c
*/
t_new   *class_alnum_posix(t_new *s, t_new *s_izi);
t_new   *class_alpha_posix(t_new *s, t_new *s_izi);
t_new   *class_blank_posix(t_new *s, t_new *s_izi);
t_new   *class_ascii_posix(t_new *s, t_new *s_izi);
t_new   *class_cntrl_posix(t_new *s, t_new *s_izi);
/*
**globing_class1.c
*/
t_new   *class_digit_posix(t_new *s, t_new *s_izi);
t_new   *class_graph_posix(t_new *s, t_new *s_izi);
t_new   *class_lower_posix(t_new *s, t_new *s_izi);
t_new   *class_print_posix(t_new *s, t_new *s_izi);
t_new   *class_punct_posix(t_new *s, t_new *s_izi);
/*
**globing_class2.c
*/
t_new   *class_space_posix(t_new *s, t_new *s_izi);
t_new   *class_upper_posix(t_new *s, t_new *s_izi);
t_new   *class_word_posix(t_new *s, t_new *s_izi);
t_new   *class_xdigit_posix(t_new *s, t_new *s_izi);
/*
**globing_class3.c
*/
t_new   *class_alnum_posix_dup(t_new *s_izi);
t_new   *class_alpha_posix_dup(t_new *s_izi);
t_new   *class_blank_posix_dup(t_new *s_izi);
t_new   *class_ascii_posix_dup(t_new *s_izi);
t_new   *class_cntrl_posix_dup(t_new *s_izi);
/*
**globing_class4.c
*/
t_new   *class_digit_posix_dup(t_new *s_izi);
t_new   *class_graph_posix_dup(t_new *s_izi);
t_new   *class_lower_posix_dup(t_new *s_izi);
t_new   *class_print_posix_dup(t_new *s_izi);
t_new   *class_punct_posix_dup(t_new *s_izi);
/*
**globing_class5.c
*/
t_new   *class_space_posix_dup(t_new *s_izi);
t_new   *class_upper_posix_dup(t_new *s_izi);
t_new   *class_word_posix_dup(t_new *s_izi);
t_new   *class_xdigit_posix_dup(t_new *s_izi);
/*
**gb_free
*/
void	globing_free_new(t_new *new);
char    **ft_magic_list_to_tab(t_new *e);
t_new   *ft_magic_tab_to_list(char **env);
#endif
