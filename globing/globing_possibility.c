#include "globing.h"
#include <libft.h>

t_glob	*accolade(t_glob *g, char *line, int *i)
{
	if (line && line[*i] != '\0')
		i++;
	g->p[0] = *i;
	while (line[*i] != '\0' && line[*i] != '}')
		i++;
	g->p[1] = *i;
	if (line[*i] != '\0')
	{
		g = add_arg(g, line, 3);
	   i++;
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

	nb = 1;
	if (line && line[*i] != '\0')
		i++;
	g->p[0] = *i;
	while (line[*i] != '\0' && nb != 0)
	{
		if (line[*i] == '[')
			nb++;
		else if (line[*i] == ']')
			nb--;
		i++;
	}
	g->p[1] = *i;
	if (line[*i] != '\0' && nb == 0)
	{
		g = add_arg(g, line, 2);
		i++;
	}
/*
**	else
**		ft_putstr_fd(2, "error parse ']'\n");
*/
	return (g);
}

t_glob	*interogation(t_glob *g, char *line, int *i)
{
	g->p[0] = *i;
	if (line && line[*i] != '\0')
		i++;
	g->p[1] = *i;
	if (line[*i] != '\0')
	{
		g = add_arg(g, line, 1);
		i++;
	}
/*
**	else
**		ft_putstr_fd(2, "error parse '}'\n");
*/
	return (g);
}

t_glob	*part_arg(t_glob *g, char *line, int *i)
{
	g->p[0] = *i;
	while (line[*i] != '\0' && line[*i] != '[' &&\
		line[*i] != '{' && line[*i] != '?' && line[*i] != '/')
		i++;
	g->p[1] = *i;
	g = add_arg(g, line, 0);
	return (g);
}

t_glob	*slash_gestion(t_glob *g, char *line, int *i)
{
	t_glob	*s;

	while (line[*i] != '\0' && line[*i] == '/')
		i++;
	if (g->new != NULL)
	{
		
	}
	return (g);
}
