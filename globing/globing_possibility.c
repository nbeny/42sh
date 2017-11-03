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

t_glob	*square_bracket(t_glob *g, char *line, int *i)
{
	int		nb;
	ft_putendl("square bracket");
	nb = 1;
	if (line && line[*i] != '\0')
		(*i)++;
	g->p[0] = *i;
	while (line[*i] != '\0' && nb != 0)
	{
		if (line[*i] == '[')
			nb++;
		else if (line[*i] == ']')
			nb--;
		(*i)++;
	}
	g->p[1] = *i;
	if (line[*i] != '\0' && nb == 0)
	{
		g = add_arg(g, line, 2);
		(*i)++;
	}
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
