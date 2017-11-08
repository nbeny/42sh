#include "globing.h"

t_new	*make_comma(t_new *new, char *str)
{
	char	**split;
	t_new	*s;
	t_new	*izi;
	int		i;

	i = 0;
	izi = NULL;
	s = new;
	split = ft_strsplit(str, ',');
		ft_putendl("STARTGGPFPPF");
		int j = 0;
		while (split[j])
		{
			ft_putendl(split[j++]);
		}
	if (split == NULL)
		return (new);
	if (s != NULL)
	{
		ft_putchar('a');
//		while (s != NULL)
		{
			ft_putchar('q');
			i = 0;
			while (split && split[i])
			{
				ft_putendl("\t if while in make_comma");
				izi = add_joinaccolade(izi, s->str, split[i]);
				i++;
			}
			s = s->next;
		}
	}
	else
	{
		ft_putchar('e');
		while (split && split[i])
		{
			ft_putendl("\t else while in make_comma");
//			if (izi == NULL)
//				izi = add_dupaccolade(s, split[i]);
//			else
			izi = add_dupaccolade(izi, split[i]);
			 ft_putendl(">>>>>>>>>>");
			i++;
		}
		
	}
	s = izi;
	ft_putendl("/!\\ print new in make_comma");
//	while (s != NULL)
//	{
//		if (str == NULL)
//			ft_putendl("NULL");
//		else
//			ft_putendl(s->str);
//
//		s = s->next;
//	}
	ft_putendl("end_print.");
	return (izi);
}
