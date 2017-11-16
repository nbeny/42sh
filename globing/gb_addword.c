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
	t_new	*s;
	char	*tmp;
	int		i;

	i = 0;
	s = new;
	ft_putendl("add_accolade");
	ft_putendl(str);
	if (ft_strlen(str) == 4)
	{
		if (ft_isalnum(str[i]) && str[i + 1] == '.' && \
			str[i + 2] == '.' && ft_isalnum(str[i + 3]))
			new = make_pointpoint(new, str);
		else
			new = make_comma(new, str);
	}
	else
		new = make_comma(new, str);
	new = duplicate_sb(new, s);
	return (new);
}

t_new	*add_interro(t_new *new)
{
	t_new	*s;
	char	*tmp;

	tmp = NULL;
	s = new;
	if (s != NULL)
		while (s != NULL)
		{
			tmp = ft_strdup(s->str);
			ft_strdel(&(s->str));
			s->str = ft_strjoin(tmp, "?");
			s = s->next;
		}
	else
	{
		new = add_new(new);
		new->str = ft_strdup("?");
	}
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
		new = add_new(new);
		new->str = ft_strdup(str);
	}
	ft_putendl("return add_word()");
	return (new);
}

t_new	*add_sbplease(t_new *sb, char *str)
{
	t_new	*s;

	s = sb;
	if (s != NULL)
	{
		while (s->next != NULL)
			s = s->next;
		s->next = init_new();
		s = s->next;
		s->str = ft_strdup(str);
		return (sb);
	}
	else
	{
		sb = init_new();
		sb->str = ft_strdup(str);
		return (sb);
	}
	return (sb);

}

t_new	*add_sb(t_new *new, char *str)
{
	t_new	*sb;
	t_new	*s;
	char	*tmp;
	char	*w;

	sb = NULL;
	tmp = NULL;
//	if (new)
//		new->sb = NULL;
	w = NULL;
	s = new;

	
	if (new != NULL)
	{
		ft_putendl("0--> new != NULL");
		while (s != NULL)
		{
			tmp = ft_strdup(s->str);
			ft_strdel(&(s->str));
			w = creat_bracket(-42);
			s->str = ft_strjoin(tmp, w);
			ft_strdel(&w);
			s->sb = add_sbplease(s->sb, str);
			s = s->next;
		}
	}
	else
	{
		new = init_new();
		new->str = creat_bracket(-42);
		new->sb = add_sbplease(new->sb, str);
	}
	return (new);
}
