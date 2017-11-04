#include "globing.h"
//gg

t_glob	*accolade(t_glob *g, char *line, int *i)
{
		ft_putendl("accolade");
	if (line && line[*i] != '\0')
		(*i)++;
	g->p[0] = *i;
	while (line[*i] != '\0' && line[*i] != '}')
		(*i)++;
	g->p[1] = *i;
	if (line[*i] != '\0')
	{
		g = add_arg(g, line, 3);
	   (*i)++;
	}
/*
**	else
**		ft_putstr_fd(2, "error parse '}'\n");
*/
	return (g);
}

int check_name_pos(char *str)
{
	if (ft_strncmp(str, "[:blank:]", 10) == 0 ||\
		ft_strncmp(str, "[:alnum:]", 10) == 0 ||\
		ft_strncmp(str, "[:alpha:]", 10) == 0 ||\
		ft_strncmp(str, "[:ascii:]", 10) == 0 ||\
		ft_strncmp(str, "[:cntrl:]", 10) == 0 ||\
		ft_strncmp(str, "[:digit:]", 10) == 0 ||\
		ft_strncmp(str, "[:graph:]", 10) == 0 ||\
		ft_strncmp(str, "[:lower:]", 10) == 0 ||\
		ft_strncmp(str, "[:print:]", 10) == 0 ||\
		ft_strncmp(str, "[:punct:]", 10) == 0 ||\
		ft_strncmp(str, "[:space:]", 10) == 0 ||\
		ft_strncmp(str, "[:upper:]", 10) == 0 ||\
		ft_strncmp(str, "[:word:]", 9) == 0 ||\
		ft_strncmp(str, "[:xdigit:]", 11) == 0)
		return (1);
	return (0);
}
int check_is_posix(char *str, int *i)
{
	int j[2];
	char *class;

	class = NULL;
	j[0] = *i;
	while (str[*i] != ']')
	{
		(*i)++;
	}
	j[1] = ++(*i);
	class = ft_strsub(str, j[0], j[1]);
	if (check_name_pos(class) == 1)
	{
		ft_strdel(&class);
		return (1);
	}
	ft_strdel(&class);
	return (0);

}
t_glob	*square_bracket(t_glob *g, char *line, int *i)
{
	while (line && line[*i] != '\0' && line[*i] != ']')
	{
		if (line[*i] == '[')
			check_is_posix(line, i);
		else
			(*i)++;
	}
	g = add_arg(g, line, 2);
	return (g);
/*
**	else
**		ft_putstr_fd(2, "error parse ']'\n");
*/
	return (g);
}

t_glob	*interogation(t_glob *g, char *line, int *i)
{
	ft_putendl("interrogation");
	g->p[0] = *i;
	if (line && line[*i] != '\0')
		(*i)++;
	g->p[1] = *i;
//	if (line[*i] != '\0')
		g = add_arg(g, line, 1);
/*
**	else
**		ft_putstr_fd(2, "error parse '}'\n");
*/
	return (g);
}

t_glob	*part_arg(t_glob *g, char *line, int *i)
{
		ft_putendl("part_arg()");
	g->p[0] = *i;
	while (line[*i] != '\0' && line[*i] != '[' &&\
		line[*i] != '{' && line[*i] != '?' && line[*i] != '/')
		(*i)++;
	g->p[1] = *i;
	g = add_arg(g, line, 0);
	return (g);
}

t_glob	*slash_gestion(t_glob *g, char *line, int *i)
{
	char	*tmp;

	ft_putendl("slash_gestion(1)");
	tmp = NULL;
	while (line[*i] != '\0' && line[*i] == '/')
		(*i)++;
		ft_putstr("end while i =");
		ft_putnbr(*i);
		ft_putendl(".");
	g->isrep = 1;
	g->new = do_we_match(g->arg, g->new);
	g = add_glob_slash(g);
	g = g->slash;
	return (g);
}
