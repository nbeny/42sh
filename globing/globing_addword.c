#include "globing.h"

char	*creat_bracket(int c)
{
	char *s;

	if (!(s = (char *)malloc(sizeof(char) * 2)))
		return(NULL);
	s[0] = c;
	s[1] = '\0';
}

t_new	*add_accolade(t_new *new, char *str)
{
	
	return (izi);
}

t_new	*add_interogation(t_new *new)
{
	t_new	*s;
	t_new	*izi;
	t_new	*s_izi;
	char	*tmp;
	char	*w;
	int		i;

	s = new;
	izi = NULL;
	if (s != NULL)
	{
		while (s != NULL)
		{
			i = 32;
			izi = add_new(izi);
			s_izi = izi;
			w = creat_bracket(i);
			s_izi->str = ft_strjoin(s->str, w);
			ft_strdel(&w);
			i++;
			while (i < 127)
			{
				s_izi->next = add_new(izi);
				w = creat_bracket(i);
				s_izi->str = ft_strjoin(s->str, w);
				ft_strdel(&w);
				i++;
			}
			s = s->next;
		}
		globing_free_new(new);
		new = izi;
	}
	else
	{
		i = 32;
		new = add_new(new);
		s = new;
		w = creat_bracket(i);
		s->str = ft_strdup(w);
		ft_strdel(&w);
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
	}
	return (new);
}

t_new	*add_word(t_new *new, char *str)
{
	t_new		*s;
	char		*tmp;

	s = new;
	tmp = NULL;
	if (s != NULL)
	{
		while (s != NULL)
		{
			tmp = ft_strdup(s->str);
			ft_strdel(&(s->str));
			s->str = ft_strjoin(tmp, str);
			s = s->next;
		}
	}
	else
	{
		s = add_new(s);
		s->str = ft_strdup(str);
	}
	return (new);
}

t_new	*add_square_bracket(t_new *new, char *str)
{
	t_new	*s;
	t_new	*izi;
	int		i;

	s = new;
	izi = NULL;
	if (s != NULL)
	{
		
		globing_free_new(new);
	}
	else
	{
		i = 0;
		if (str != NULL && str[0] != '\0')
		{
			if (str[i + 1] == '-' && str[i + 2] != '\0')
				izi = sb_mode_shoot_null(s, str, izi);
			else
				izi = sb_mode_other_null(s, str, izi);
		}
	}
	return (izi);
}
