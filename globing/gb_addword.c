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

t_glob	*add_accolade(t_glob *g, char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	ft_putendl("add_accolade");
	ft_putendl(str);
	if (ft_strlen(str) == 4)
	{
		if (ft_isalnum(str[i]) && str[i + 1] == '.' &&\
			str[i + 2] == '.' && ft_isalnum(str[i + 3]))
			g->new = make_pointpoint(g->new, str);
		else
			g->new = make_comma(g->new, str);
	}
	else
		g->new = make_comma(g->new, str);
	return (g);
}

t_glob	*add_interro(t_glob *g)
{
	t_new	*s;
	char	*tmp;

	tmp = NULL;
	s = g->new;
	if (s != NULL)
		while (s != NULL)
		{
			tmp = ft_strdup(s->str);
			ft_strdel(&(s->str));
			s->str = ft_strjoin(tmp, "?");
			ft_strdel(&tmp);
			s = s->next;
		}
	else
	{
		g->new = add_new(g->new);
		g->new->str = ft_strdup("?");
	}
	return (g);
}

t_glob	*add_word(t_glob *g, char *str)
{
	t_new		*s;
	char		*tmp;

	ft_putendl("add_word()");
	s = g->new;
	tmp = NULL;
	if (s != NULL)
	{
		ft_putendl("if");
		while (s != NULL)
		{
			tmp = ft_strdup(s->str);
			ft_strdel(&(s->str));
			s->str = ft_strjoin(tmp, str);
			ft_strdel(&tmp);
			s = s->next;
		}
	}
	else
	{
		ft_putendl("else");
		g->new = add_new(g->new);
		g->new->str = ft_strdup(str);
	}
	ft_putendl("return add_word()");
	return (g);
}

t_glob	*add_sbplease(t_glob *g, char *str)
{
	t_new	*s;

	s = g->sb;
	if (s != NULL)
	{
		while (s->next != NULL)
			s = s->next;
		s->next = init_new();
		s = s->next;
		s->str = ft_strdup(str);
		return (g);
	}
	else
	{
		g->sb = init_new();
		g->sb->str = ft_strdup(str);
		return (g);
	}
	return (g);

}

t_glob	*add_sb(t_glob *g, char *str)
{
	t_new	*sb;
	t_new	*s;
	char	*tmp;
	char	*w;

	sb = NULL;
	tmp = NULL;
	w = NULL;
	s = g->new;

	
	if (g && g->new)
	{
		ft_putendl("0--> new != NULL");
		g = add_sbplease(g, str);
		while (s != NULL)
		{
			tmp = ft_strdup(s->str);
			ft_strdel(&(s->str));
			w = creat_bracket(-42);
			s->str = ft_strjoin(tmp, w);
			ft_strdel(&tmp);
			ft_strdel(&w);
			s = s->next;
		}
	}
	else
	{
		g->new = init_new();
		g->new->str = creat_bracket(-42);
		g = add_sbplease(g, str);
	}
	return (g);
}
