#include "globing.h"

void	globing_free_new(t_new *new)
{
	t_new	*f;
	t_new	*s;

	s = new;
	if (s != NULL)
		while (s != NULL)
		{
			f = s;
			s = s->next;
			if (f->str != NULL)
				ft_strdel(&(f->str));
			free(f);
			f = NULL;
		}
}
