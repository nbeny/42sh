#include "globing.h"

t_glob	*accolade(t_glob *g, char *line, int *i)
{
	int		save;
	ft_putstr("accolade");
	save = (*i);
	ft_putendl("accolade");
	g->p[0] = ++(*i);
	while (line[*i] != '\0' && line[*i] != '}')
		(*i)++;
	g->p[1] = (*i);
	ft_putendl("/n**/n**\n\t");
	ft_putchar(line[*i]);
	if (line[*i] != '\0' && (check_pointpoint(line, save) || check_comma(line, save)))
	{
		ft_putstr("if in accolade");
		(*i)++;
		g = add_arg(g, line, 3);
	}
//	else if (line[*i] != '\0' && check_comma(line, save))
	else
	{
		ft_putstr("else in accolade");
		g->p[0] = g->p[0] - 1;
		if (line[*i] == '}')
			g->p[1] = g->p[1];
		g = remake_arg(g, line);
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
	ft_putendl(line);
	ft_putnbr(*i);
//	sleep(1);
	if (line[0] == '/' )
		g->slashzero = 1;
	while (line[*i] != '\0' && line[*i] == '/')
		(*i)++;
	ft_putstr("end while i =");
	ft_putnbr(*i);
	ft_putendl(".");
	if (g->arg != NULL)
	{
		g = add_glob_slash(g);
//	g = do_we_match(g);
		g = g->slash;
		if (line[0] == '/')
			g->slashzero = 1;
	}
	return (g);
}
