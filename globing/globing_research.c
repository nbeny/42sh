#include "globing.h"
#include <libft.h>

t_glob	*init_glob()
{
	t_glob		*g;

	if (!(g = (t_glob *)malloc(sizeof(t_glob))))
		return (NULL);
	g->isrep = 1;
	g->new = NULL;
	g->arg = NULL;
	g->p[0] = 0;
	g->p[1] = 0;
	g->slash = NULL;
	g->next = NULL;
	return (g);
}

t_glob	*add_glob_next(t_glob *g)
{
	t_glob	*s;

	s = g;
	if (g != NULL)
	{
		while (s->next != NULL)
			s = s->next;
		s->next = init_glob();
	}
	else
		g = init_glob();
	return (g);
}

t_glob	*add_glob_slash(t_glob *g)
{
	
	return (g);
}

t_arg	*init_argument()
{
	t_arg		*arg;

	if (!(arg = (t_arg *)malloc(sizeof(t_arg))))
		return (NULL);
	arg->id = 0;
	arg->str = NULL;
	arg->next = NULL;
	return (arg);
}

t_glob	*add_arg(t_glob *g, char *line, int a)
{
	t_arg		*s;

	s = g->arg;
	if (s != NULL)
	{
		while (s->next != NULL)
			s = s->next;
		s->next = init_argument();
		s = s->next;
		s->str = ft_strsub(line, g->p[0], g->p[1]);
		s->id = a;
	}
	else
	{
		g->arg = init_argument();
		g->arg->str = ft_strsub(line, g->p[0], g->p[1]);
		g->arg->id = a;
	}
	return (g);
}

t_glob	*zoom_research(t_glob *g, char *line)
{
	t_glob	*s;
	int		i;

	i = 0;
	s = g;
	while (line[i])
	{
		if (line[i] == '/')
			slash = slash_gestion(slash, line, &i);
		if (line[i] == '[')
			slash = square_bracket(slash, line, &i);
		else if (line[i] == '{')
			slash = accolade(slash, line, &i);
		else if (line[i] == '?')
			slash = interogation(slash, line, &i);
		else
			slash = part_arg(slash, line, &i);
	}
	s->new = do_we_match(s->arg, s->new);
	return (g);
}

t_glob	*globing_research(char **cmd)
{
	int			j;
	t_glob		*g;
	t_glob		*s;

	j = 0;
	g = NULL;
	g = init_glob();
	s = g;
	while (cmd && cmd[j])
	{
		slash = s;
		s = zoom_research(s, cmd[j]);
		s = s->next;
		j++;
	}
	return (g);
}
