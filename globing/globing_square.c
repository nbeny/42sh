#include "globing.h"

t_new	*sb_boucle_new(t_new *s, t_new *izi, char *str)
{
	t_izi	s_izi;

	s_izi = izi;
	while (s != NULL)
	{
		sb_boucle_str(s, s_izi, str);
		s = s->next;
	}
	return (s_izi);
}

t_new	*sb_boucle_str(t_new *s, t_new *s_izi, char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i + 1] != '\0')
		{
			if (str[i + 1] == '-' && str[i + 2] != '\0')
			{
				s_izi = sb_ascii_posjoin(s, (int)str[i], (int)str[i + 2], s_izi);
				i += 3;
			}
			else
			{
				s_izi = sb_ascii_posjoin(s, (int)str[i], ((int)str[i] + 1), s_izi);
				i++;
			}
		}
		else
		{
			s_izi = sb_ascii_posjoin(s, (int)str[i], ((int)str[i] + 1), s_izi);
			i++;
		}
	}
	return (s_izi);
}

t_new	*sb_ascii_posjoin(t_new *s, int c1, int c2, t_new *izi)
{
	char	*w;
	int		i;

	i = c1;
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

t_new	*sb_ascii_posdup(int c1, int c2)
{
	t_new	*new;
	t_new	*s;
	char	*w;
	int	i;

	i = c1;
	new = add_new(new);
	s = new;
	w = creat_bracket(i);
	s->str = ft_strdup(w);
	ft_strdel(&w);
	i++;
	while (i < c2)
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

t_new	*sb_not_null(t_new *s, char *str, t_new *izi)
{
	t_new	*s_izi;
	char	*tmp;
	char	*w;
	int		i;

	i = 0;
	if (str != NULL)
	{
		i = (int)str[i];
		izi = add_new(izi);
		s_izi = izi;
		w = creat_bracket(i);
		s_izi->str = ft_strjoin(s->str, w);
		ft_strdel(&w);
		i++;
		while (str[i])
		{
			if (str[i + 1] == '-')
			{
				if (str[i + 2] != '\0')
				{
					s_izi->next = add_new(izi);
					w = creat_bracket(i);
					s_izi->str = ft_strjoin(s->str, w);
					ft_strdel(&w);
					i++;
				}
				else
				{
					;
				}
			}
			else
			{
				s_izi->next = add_new(izi);
				w = creat_bracket(i);
				s_izi->str = ft_strjoin(s->str, w);
				ft_strdel(&w);
				i++;
			}
		}
	}
	return (izi);
}

t_new	*sb_mode_other(t_new *s, char *str, t_new *izi)
{
	t_new	*s_izi;
	char	*tmp;
	char	*w;
	int		i;

	i = 0;
	if (str != NULL)
	{
		izi = add_new(izi);
		s_izi = izi;
		w = creat_bracket(str[i]);
		s_izi->str = ft_strjoin(s->str, w);
		ft_strdel(&w);
		i++;
		while (str && str[i])
		{
			s_izi->next = add_new(izi);
			w = creat_bracket(str[i]);
			s_izi->str = ft_strjoin(s->str, w);
			ft_strdel(&w);
			i++;
		}
	}
	return (izi);
}

t_new	*sb_mode_shoot_null(t_new *s, char *str, t_new *izi)
{
	t_new	*s_izi;
	char	*tmp;
	char	*w;
	int		i;

	i = 0;
	if (str != NULL)
	{
		i = (int)str[i];
		new = add_new(new);
		s = new;
		w = creat_bracket(i);
		s->str = ft_strdup(w);
		ft_strdel(&w);
		i++;
		while (i < (int)str[i + 2])
		{
			s->next = add_new(new);
			s = s->next;
			w = creat_bracket(i);
			s->str = ft_strdup(w);
			ft_strdel(&w);
			i++;
		}
	}
	return (izi);
}

t_new	*sb_mode_other_null(t_new *s, char *str, char *izi)
{
	t_new	*s_izi;
	char	*tmp;
	char	*w;
	int		i;

	i = 0;
	if (str != NULL)
	{
		new = add_new(new);
		s = new;
		w = creat_bracket(str[i]);
		s->str = ft_strdup(w);
		ft_strdel(&w);
		i++;
		while (str && str[i])
		{
			s->next = add_new(new);
			s = s->next;
			w = creat_bracket(str[i]);
			s->str = ft_strdup(w);
			ft_strdel(&w);
			i++;
		}
	}
	return (izi);
}

t_new	*sb_not_null(t_new *s, char *str, t_new *izi)
{
	
}
