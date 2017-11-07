#include "globing.h"

t_new	*make_comma(t_new *new, char *str)
{
	char	**split;
	t_new	*s;
	t_new	*izi;
	int		i;

	izi = NULL;
	s = new;
	split = ft_strsplit(str, ',');
	if (split == NULL)
		return (new);
	if (s != NULL)
	{
		while (s != NULL)
		{
			i = 0;
			while (split && split[i])
			{
				izi = add_joinaccolade(s, s->str, split[i]);
				i++;
			}
			s = s->next;
		}
	}
	else
	{
		while (split && split[i])
		{
			izi = add_dupaccolade(s, split[i]);
			i++;
		}
	}
	s = izi;
	ft_putendl("GGPFPPF");
	while (s != NULL)
	{
		ft_putendl(s->str);
		s = s->next;
	}
	return (izi);
}
