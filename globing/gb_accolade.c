#include "globing.h"

int		check_pointpoint(char *line, int i)
{
	i++;
	if (line && ft_isalnum(line[i]))
		if (line[i + 1] == '.')
			if (line[i + 2] == '.')
				if (ft_isalnum(line[i + 3]))
					return (1);
	return (0);
}

int		check_comma(char *line, int i)
{
	i++;
	while (line[i] != '}' && line[i] != '\0')
	{
		if (line[i] == ',')
			while (line[i] == '}' && line[i] != '\0')
			{
				if (line[i] == '}')
					return (1);
				i++;
			}
		i++;
	}
	return (0);
}

t_new	*add_joinaccolade(t_new *new, char *s1, char *s2)
{
	t_new	*s;

	s = new;
	if (new != NULL)
	{
		while (s->next != NULL)
			s = s->next;
		s->next = init_new();
		s = s->next;
		s->str = ft_strjoin(s1, s2);
	}
	else
	{
		new = init_new();
		new->str = ft_strjoin(s1, s2);
	}
	return (new);
}

t_new	*add_dupaccolade(t_new *new, char *str)
{
	t_new	*s;

	s = new;
	if (new != NULL)
	{
		while (s->next != NULL)
			s = s->next;
		s->next = init_new();
		s = s->next;
		s->str = ft_strdup(str);
	}
	else
	{
		new = init_new();
		new->str = ft_strjoin(str);
	}
	return (new);
}

t_new	*make_pointpoint(t_new *new, char *str)
{
	t_new	*s;
	t_new	*izi;
	int		c;
	char	*w;

	izi = NULL;
	c = 0;
	if (str != NULL)
		c = str[0];
	else
		return (new);
	s = new;
	if (new != NULL)
	{
		w = creat_bracket(str[0]);
		izi = add_joinaccolade(izi, s->str, w);
		ft_strdel(&w);
		while (s != NULL)
		{
			while (c <= str[3])
			{
				w = creat_bracket(str[0]);
				izi = add_joinaccolade(izi, s->str, w);
				ft_strdel(&w);
				c++;
			}
			s = s->next;
		}
	}
	else
	{
		w = creat_bracket(str[3]);
		izi = add_dupaccolade(izi, w);
		ft_strdel(&w);
		while (c <= str[3])
		{
			w = creat_bracket(str[3]);
			izi = add_dupaccolade(izi, w);
			ft_strdel(&w);
			c++;
		}
	}
	return (izi);
}
