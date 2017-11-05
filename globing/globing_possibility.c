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
	if (ft_strncmp(str, "[:blank:]", 9) == 0 ||\
		ft_strncmp(str, "[:alnum:]", 9) == 0 ||\
		ft_strncmp(str, "[:alpha:]", 9) == 0 ||\
		ft_strncmp(str, "[:ascii:]", 9) == 0 ||\
		ft_strncmp(str, "[:cntrl:]", 9) == 0 ||\
		ft_strncmp(str, "[:digit:]", 9) == 0 ||\
		ft_strncmp(str, "[:graph:]", 9) == 0 ||\
		ft_strncmp(str, "[:lower:]", 9) == 0 ||\
		ft_strncmp(str, "[:print:]", 9) == 0 ||\
		ft_strncmp(str, "[:punct:]", 9) == 0 ||\
		ft_strncmp(str, "[:space:]", 9) == 0 ||\
		ft_strncmp(str, "[:upper:]", 9) == 0 ||\
		ft_strncmp(str, "[:word:]", 8) == 0 ||\
		ft_strncmp(str, "[:xdigit:]", 10) == 0)
		return (1);
	return (0);
}

int		check_is_posix(char *str, int *i)
{
	int		j[2];
	int		save;
	char	*class;

	ft_putstr("check is posix");
		ft_putstr(str);
	class = NULL;
	save = *i;
	j[0] = *i;
	while (str[*i] && str[*i] != ']')
	{
		(*i)++;
	}
	j[1] = ++(*i);
	class = ft_strsub(str, j[0], j[1]);
	ft_putstr(class);
	if (check_name_pos(class) == 1)
	{
		ft_strdel(&class);
		return (*i);
	}
	ft_strdel(&class);
	return (++save);
}

t_glob	*square_bracket(t_glob *g, char *line, int *i)
{
	char	*tmp;

	ft_putstr("sqare");
	g->p[0] = ++(*i);
	while (line && line[*i] != '\0' && line[*i] != ']')
	{
		if (line[*i] && line[*i] == '[')
			(*i) = check_is_posix(line, i);
		else
			(*i)++;
	}
	g->p[1] = (*i);
	if (line[*i] == '\0')
	{
		g->p[0]--;
		g = remake_arg(g, line);
	}
	else
	{
		(*i)++;
		g = add_arg(g, line, 2);
	}
	
//	while ()
	ft_putendl("\n\nHEEEEREEEEE\n\n");
//	while (g->arg != NULL)
//	{
//		ft_putendl(g->arg->str);
//		g->arg = g->arg->next;
//	}
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
