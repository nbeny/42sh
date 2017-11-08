#include "globing.h"

t_new	*add_path(t_new *st_path, char *path)
{
	t_new		*s;

	s = st_path;
	if (st_path != NULL)
	{
		while (s->next != NULL)
			s = s->next;
		s->next = init_new();
		s = s->next;
		s->str = ft_strdup(path);
	}
	else
	{
		st_path = init_new();
		st_path->str = ft_strdup(path);
	}
	return (st_path);
}

t_new	*
