#include "globing.h"

t_new	*join_list(t_new *izi, t_new *rec_path)
{
	t_new	*s;

	s = izi;
	if (izi != NULL)
	{
		while (s->next != NULL)
			s = s->next;
		s->next = rec_path;
	}
	else
	{
		izi = rec_path;
	}
	return (izi);
}

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
