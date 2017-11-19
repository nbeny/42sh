#include "globing.h"

t_glob	*add_sbplease(t_glob *g, char *str)
{
	t_new		*s;

	s = g->sb;
	if (s != NULL)
	{
		while (s->next != NULL)
			s = s->next;
		s->next = init_new();
		s = s->next;
		s->str = ft_strdup(str);
	}
	else
	{
		g->sb = init_new();
		g->sb->str = ft_strdup(str);
	}
	return (g);
}
