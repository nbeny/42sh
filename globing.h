#ifndef GLOBING_H
# define GLOBING_H
#include "globing/libft/include/libft.h"

#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"
#define RED     "\x1b[31m"

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
	int				slashzero;
	struct s_arg	*arg;
	struct s_new	*new;
	struct s_new	*sb;
	struct s_new	*resforever;
	int				p[2];
	struct s_glob	*slash;
}				t_glob;
/*
**gb_init
*/
t_glob			*init_glob();
t_glob			*add_glob_next(t_glob *g);
t_glob			*add_glob_slash(t_glob *g);
t_arg			*init_argument();
t_glob			*add_arg(t_glob *g, char *line, int a);
/*
**gb_research
*/
t_glob			*remake_arg(t_glob *g, char *line);
t_glob			*zoom_research(t_glob *g, char *line);
int				check_isglob(char *line);
char			**globing_research(char **cmd);
/*
**gb_possibility
*/
t_glob			*accolade(t_glob *g, char *line, int *i);
int				check_name_pos(char *str);
int				check_is_posix(char *str, int *i);
t_glob			*square_bracket(t_glob *g, char *line, int *i);
t_glob			*interogation(t_glob *g, char *line, int *i);
t_glob			*part_arg(t_glob *g, char *line, int *i);
t_glob			*slash_gestion(t_glob *g, char *line, int *i);
/*
**gb_addword
*/
char			*creat_bracket(int c);
t_glob			*add_accolade(t_glob *g, char *str);
t_glob			*add_interro(t_glob *g);
t_glob			*add_word(t_glob *g, char *str);
t_glob			*add_sbplease(t_glob *g, char *str);
t_glob			*add_sb(t_glob *g, char *str);
/*
**gb_match
*/
t_new			*init_new();
t_new			*add_new(t_new *new);
int				check_sbmatch(char *s1, t_new *sb);
int				nmatch(char *s1, char *s2, t_new *sb);
t_glob			*check_slash(t_glob *g, t_new *st_path, t_glob *save);
t_glob			*do_we_match(t_glob *g);
/*
**gb_match_pos
*/
int				sb_lessmatchno(int c, char *str, int *i);
int				sb_exclammatch(int c, char *str, int *i);
int				sb_lessmatch(int c, char *str, int *i);
int				sb_classmatch(int c, char *str, int *i);
int				sb__match(int c, char *str, int *i);
int				sb__match_no(int c, char *str, int *i);
/*
**gb_matchrep
*/
char			*tri_join(int zero, char *path, char *str);
t_new			*match_rep(t_glob *g, char *path);
char			*found_path(int zero, char *path, char *dname);
t_glob			*match_file(t_glob *g, char *path);
/*
**gb_recupchartab
*/
int				count_match(t_glob *g);
int				check_char42(char *s);
void			reverse_char42(char *s);
void			get_char42(char *s);
/*
**gb_tools_match
*/
int				ft_islower(int c);
int				ft_isupper(int c);
int				ft_iscntrl(int c);
int				ft_isgraph(int c);
int				ft_isprint(int c);
/*
**gb_tools_match1
*/
int				ft_ispunct(int c);
int				ft_isspace(int c);
int				ft_isword(int c);
int				ft_isblank(int c);
int				ft_isxdigit(int c);
/*
**gb_accolade
*/
int				check_pointpoint(char *line, int i);
int				check_comma(char *line, int i);
t_new			*add_joinaccolade(t_new *new, char *s1, char *s2);
t_new			*add_dupaccolade(t_new *new, char *str);
t_new			*make_pointpoint(t_new *new, char *str);
/*
**gb_accolade1
*/
t_new			*make_comma(t_new *new, char *str);
int				check_rebuild_path(char *str);
char			*rebuild_path(t_new *sb, char *str);
t_new			*rebuild_sb_struct(t_new *n_sb, t_new *s_sb);
t_new			*duplicate_sb(t_new *new, t_new *s);
/*
**gb_slash_gestion
*/
t_new			*join_list(t_new *izi, t_new *rec_path);
t_new			*add_path(t_new *st_path, char *path);
char			**list_to_tab_new(t_new *e);
/*
**gb_free
*/
void			free_split(char **split);
void			free_arg(t_arg *arg);
void			free_new(t_new *new);
void			free_resforever(t_new *resforever);
void			free_glob_slash(t_glob *g);
#endif
