#include "globing.h"
//gg

char	*creat_bracket(int c)
{
	char *s;

	if (!(s = (char *)malloc(sizeof(char) * 2)))
		return(NULL);
	s[0] = c;
	s[1] = '\0';
	return (s);
}

t_new	*add_accolade(t_new *new, char *str)
{
	t_new	*izi;

	izi = new;
	ft_putstr(str);
	return (izi);
}

t_new	*add_interogation(t_new *new)
{
	t_new	*s;
	t_new	*izi;
	t_new	*s_izi;
	char	*w;
	int		i;

	ft_putendl("add interrogation");
	s = new;
	izi = NULL;
	if (s != NULL)
	{
		ft_putendl("s != NULL");
		if (s->str != NULL)
			ft_putendl("s->str is true");
		else
			ft_putendl("s->str pu");
		izi = add_new(izi);
		s_izi = izi;
		while (s != NULL)
		{
			i = 32;
			while (i != 127)
			{
				s_izi = add_new(izi);
				w = creat_bracket(i);
				s_izi->str = ft_strjoin(s->str, w);
				ft_strdel(&w);
				if (i == 41)
					i++;
				i++;
			}
			s = s->next;
		}
		globing_free_new(new);
		new = izi;
	}
	else
	{
		ft_putendl("s == NULL");
		i = 32;
		ft_putendl("1");
		new = add_new(new);
		ft_putendl("2");
		s = new;
		w = creat_bracket(i);
		s->str = ft_strdup(w);
		ft_strdel(&w);
		i++;
		while (i != 127)
		{
				ft_putendl("3");
			s = add_new(s);
				ft_putendl("4");
			s = s->next;
			w = creat_bracket(i);
			s->str = ft_strdup(w);
			ft_strdel(&w);
			if (i == 41)
				i++;
			i++;
		}
	}
	s = new;
	while (s != NULL)
	{
		if (s->str != NULL)
			ft_putendl(s->str);
		else
			ft_putendl("s->str pu");

		s = s->next;
	}
	ft_putendl("end add interrogation");
	return (new);
}

t_new	*add_word(t_new *new, char *str)
{
	t_new		*s;
	char		*tmp;

	ft_putendl("add_word()");
	s = new;
	tmp = NULL;
	if (s != NULL)
	{
		ft_putendl("if");
		while (s != NULL)
		{
			tmp = ft_strdup(s->str);
			if (tmp == NULL)
				ft_putendl("tmp == NULL");
			else
				ft_putendl("tmp != NULL");
			ft_strdel(&(s->str));
			s->str = ft_strjoin(tmp, str);
			s = s->next;
		}
	}
	else
	{
		ft_putendl("else");
		s = add_new(s);
		s->str = ft_strdup(str);
		if (s->str == NULL)
			ft_putstr("gg");
		else
			ft_putstr(s->str);
		
		return (s);
	}
	ft_putendl("return add_word()");
	return (new);
}

t_new	*sb_ascii_posjoin(t_new *s, int c1, int c2, t_new *izi)
{
	char	*w;
	int		i;

	if (c1 < c2)
		i = c1;
	else if (c1 > c2)
	{
		i = c2;
		c2 = c1;
	}
	else
		return (izi);
	while (i <= c2)
	{
		izi->next = add_new(izi);
		w = creat_bracket(i);
		izi->str = ft_strjoin(s->str, w);
		ft_strdel(&w);
		i++;
	}
	return (izi);
}

t_new	*sb_ascii_posdup(t_new *new, int c1, int c2)
{
	t_new	*s;
	char	*w;
	int		i;

	s = new;
	if (c1 < c2)
		i = c1;
	else if (c1 > c2)
	{
		i = c2;
		c2 = c1;
	}
	else
		return (new);
	while (i < c2)
	{
		s->next = add_new(new);
		s = s->next;
		w = creat_bracket(i);
		s->str = ft_strdup(w);
		ft_strdel(&w);
		i++;
	}
	return (s);
}

t_new	*sb_not_this_ascii_posdup(t_new *new, int c1, int c2)
{
	t_new	*s;
	char	*w;
	int		i;

	if (c1 > c2)
	{
		i = c1;
		c1 = c2;
		c2 = i;
	}
	i = 32;
	while (i < c1)
	{
		s->next = add_new(new);
		s = s->next;
		w = creat_bracket(i);
		s->str = ft_strdup(w);
		ft_strdel(&w);
		i++;
	}
	while (i <= c2)
		i++;
	while (i < 127)
	{
		s->next = add_new(new);
		s = s->next;
		w = creat_bracket(i);
		s->str = ft_strdup(w);
		ft_strdel(&w);
		i++;
	}
	return (new);
}

t_new	*sb_not_ascii_posjoin(t_new *s, int c1, int c2, t_new *izi)
{
	char	*w;
	int		i;

	if (c1 > c2)
	{
		i = c1;
		c1 = c2;
		c2 = i;
	}
	i = 32;
	while (i < c1)
	{
		izi->next = add_new(izi);
		w = creat_bracket(i);
		izi->str = ft_strjoin(s->str, w);
		ft_strdel(&w);
		i++;
	}
	while (i <= c2)
		i++;
	while (i < 127)
	{
		izi->next = add_new(izi);
		w = creat_bracket(i);
		izi->str = ft_strjoin(s->str, w);
		ft_strdel(&w);
		i++;
	}
	return (izi);
}

t_new	*add_square_bracket(t_new *new, char *str)
{
	t_new	*s;
	t_new	*izi;
	t_new	*s_izi;
	char	*w;
	int		i;

	s = new;
	izi = NULL;
	if (s != NULL)
	{
		while (s != NULL)
		{
			i = 0;
			izi = add_new(izi);
			s_izi = izi;
			w = creat_bracket(str[i]);
			s_izi->str = ft_strjoin(s->str, w);
			ft_strdel(&w);
			i++;
			while (str && str[i])
			{
				if (str[i] == '^' || str[i] == '!')
				{
					i++;
					s_izi = get_no_ascii(s, str, &i, s_izi);
				}
				else if (str[i] == '[')
				{
					i++;
					s_izi = get_class_posix(s, str, &i, s_izi);
				}
				else
					s_izi = get_ascii(s, str, &i, s_izi);
			}
			s = s->next;
		}
		globing_free_new(new);
		new = izi;
	}
	else
	{
		i = 0;
		new = add_new(new);
		s = new;
		w = creat_bracket(str[i]);
		s->str = ft_strdup(w);
		ft_strdel(&w);
		i++;
		while (str && str[i])
		{
			if (str[i + 1] == '-')
			{
				if (str[i + 1] == '-' && str[i + 2] != '\0')
				{
					s_izi = sb_ascii_posdup(s_izi, (int)str[i], (int)str[i + 2]);
					i += 3;
				}
				else
				{
					s_izi = sb_ascii_posdup(s_izi, (int)str[i], ((int)str[i] + 1));
					i++;
				}
			}
			else
			{
				s_izi = sb_ascii_posdup(s_izi, (int)str[i], ((int)str[i] + 1));
				i++;
			}
		}
	}
	return (new);
}
