#include "globing.h"

int		count_match(t_glob *g)
{
	int		i;
	t_glob	*s;

	i = 0;
	s = g;
	if (s == NULL)
		return (0);
	while (s != NULL)
	{
		if (s->arg != NULL)
			i++;
		s = s->next;
	}
	return (i);
}

