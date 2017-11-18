#include "globing.h"

t_glob	*init_glob()
{
	t_glob		*g;

	if (!(g = (t_glob *)malloc(sizeof(t_glob))))
		return (NULL);
	g->slashzero = 0;
	g->new = NULL;
	g->resforever = NULL;
	g->arg = NULL;
	g->p[0] = 0;
	g->p[1] = 0;
	g->slash = NULL;
	g->sb = NULL;
//	g->next = NULL;
	return (g);
}
/*
t_glob	*add_glob_next(t_glob *g)
{
	t_glob		*s;

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
*/
t_glob	*add_glob_slash(t_glob *g)
{
	t_glob		*s;

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

t_arg   *init_argument()
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
	ft_putstr("create arg");
	if (s != NULL)
	{
		while (s->next != NULL)
			s = s->next;
		s->next = init_argument();
		s = s->next;
		s->str = ft_strsub(line, g->p[0], g->p[1]);
		s->id = a;
		printf(RED "\n malloc : %p"RESET"\n",s);
	}
	else
	{
		g->arg = init_argument();
		g->arg->str = ft_strsub(line, g->p[0], g->p[1]);
		g->arg->id = a;
		printf(RED"\n malloc : %p"RESET"\n",g);
	}
	return (g);
}
