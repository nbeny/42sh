#include "globing.h"
//gg

t_glob	*init_glob()
{
	t_glob		*g;

	if (!(g = (t_glob *)malloc(sizeof(t_glob))))
		return (NULL);
	g->slashzero = 0;
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
	t_glob	*s;

	s = g;
	if (g != NULL && g->slash != NULL)
	{
		while (s->slash != NULL)
			s = s->slash;
		s->slash = init_glob();
	}
	else if (g != NULL)
		g->slash = init_glob();
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
		ft_putstr(s->str);
		s->id = a;
//		return (s);
	}
	else
	{
		g->arg = init_argument();
		g->arg->str = ft_strsub(line, g->p[0], g->p[1]);
		g->arg->id = a;
	}
	return (g);
}

t_glob	*remake_arg(t_glob *g, char *line)
{
	t_arg	*s;
	char	*tmp1;
	char	*tmp2;

	tmp1 = NULL;
	tmp2 = NULL;
	s = g->arg;
	if (s != NULL)
	{
		while (s->next != NULL)
			s = s->next;
		tmp1 = ft_strdup(s->str);
		tmp2 = ft_strsub(line, g->p[0], g->p[1]);
		ft_strdel(&(s->str));
		s->str = ft_strjoin(tmp1, tmp2);
		ft_strdel(&tmp1);
		ft_strdel(&tmp2);
	}
	else
	{
		g = add_arg(g, line, 0);
	}
	return (g);
}

void ft_printgg(t_glob *g)
{
	ft_putendl("----------->HERE");
	while (g)
	{
		while (g->arg)
		{
			if (g->arg->str)
				ft_putendl(g->arg->str);
			else 
				ft_putstr("NULL");
			g->arg = g->arg->next;
		}
		g = g->slash;
	}
	ft_putendl("----------->HERE");
}

t_glob	*zoom_research(t_glob *g, char *line)
{
	t_glob	*s;
	int		i;

	i = 0;
	s = g;
	if (line == NULL)
	{
		ft_putstr("zoom reasearch null return ");
		return (NULL);
	}

	while (line[i])
	{
		ft_putnbr(i);
		if (line[i] == '/')
			s = slash_gestion(s, line, &i);
		if (line[i] == '[')
			s = square_bracket(s, line, &i);
		else if (line[i] == '{')
		{
			ft_putchar('q');
			s = accolade(s, line, &i);
		}
		else if (line[i] == '?')
			s = interogation(s, line, &i);
		else
			s = part_arg(s, line, &i);
	}
//	ft_printgg(g);
//HH
	g = do_we_match(g);
	ft_putendl("return zoom search");
	return (g);
}

int		check_isglob(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '*' || line[i] == '?' ||\
			line[i] == '[' || line[i] == '{')
			return (1);
		i++;
	}
	return (0);
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
		if (check_isglob(cmd[j]))
		{
			s = zoom_research(s, cmd[j]);
			s = s->next;
		}
		j++;
	}
	t_glob *hh;

	hh = g;


	ft_putendl("start print ");
	while (hh->slash)
	{
		while (hh->resforever)
		{
			if (hh->resforever && hh->resforever->str)
				ft_putendl(hh->resforever->str);
			hh->resforever = hh->resforever->next;
		}
		hh = hh->slash;
	}
	return (g);
}
