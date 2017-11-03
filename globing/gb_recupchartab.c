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

int		check_char42(char *s)
{
	int		i;

	i = 0;
	if (s != NULL)
		while (s[i] != '\0')
		{
			if (s[i] == -42)
				return (1);
			i++;
		}
	return (0);
}

void	reverse_char42(char *s)
{
	int		i;

	i = 0;
	if (s != NULL)
		while (s[i] != '\0')
		{
			if (s[i] == 42)
				s[i] = -42;
			i++;
		}
}

void	get_char42(char *s)
{
	int		i;

	i = 0;
	if (s != NULL)
		while (s[i] != '\0')
		{
			if (s[i] == -42)
				s[i] = 42;
			i++;
		}
}
