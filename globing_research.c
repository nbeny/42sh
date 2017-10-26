#include "globing.h"
#include <libft.h>

t_glob	*init_glob()
{
	t_glob		*g;

	if (!(g = (t_glob *)malloc(sizeof(t_glob))))
		return (NULL);
	g->new = NULL;
	g->arg = NULL;
	g->p[0] = 0;
	g->p[1] = 0;
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

t_glob	*globing_research(char **cmd)
{
	int			i;
	int			j;
	t_glob		*g;

	j = 0;
	g = NULL;
	g = init_glob();
	while (cmd && cmd[j])
	{
		i = 0;
		while (cmd[j][i])
		{
			if (cmd[j][i] == '[')
				g = square_bracket(g, cmd[j], &i);
			else if (cmd[j][i] == '{')
				g = accolade(g, cmd[j], &i);
			else if (cmd[j][i] == '?')
				g = interogation(g, cmd[j], &i);
			else
				g = part_arg(g, cmd[j], &i);
		}
		g->new = do_we_match(g->arg, g->new);
		j++;
	}
	return (g);
}
