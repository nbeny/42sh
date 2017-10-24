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
