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
	{
	ft_putendl("!!!!!!!!!!!!!!!!!!!!!!!!!!MAYBE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
		return (new);
	}
	if (s != NULL)
	{
		ft_putendl(s->str);
		while (s != NULL)
		{
			i = 0;
			while (split && split[i])
			{
				izi = add_joinaccolade(izi, s->str, split[i]);
				i++;
			}
			s = s->next;
		}
	}
	else
	{
		i = 0;
		while (split && split[i])
		{
			izi = add_dupaccolade(izi, split[i]);
			i++;
		}
	}
	s = izi;
	while (s != NULL)
	{
		ft_putendl(s->str);
		s = s->next;
	}
	return (izi);
}

int		check_rebuild_path(char *str)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == -42)
			return (1);
		i++;
	}
	return (0);
}

char	*rebuild_path(t_new *sb, char *str)
{
	char		*tmp1;
	char		*tmp2;
	char		*new;
	t_new		*s;
	int			i;
	int			p[2];

	i = 0;
	s = sb;
	new = ft_strdup("\0");
	while (str && str[i] && sb)
	{
		if (str[i] == -42)
		{
			i++;
			tmp1 = ft_strjoin(new, "[");
			tmp2 = ft_strjoin(tmp1, s->str);
			ft_strdel(&new);
			new = ft_strjoin(tmp2, "]");
			ft_strdel(&tmp1);
			ft_strdel(&tmp2);
			s = s->next;
		}
		else
		{
			p[0] = i;
			while (str && str[i])
				i++;
			p[1] = i;
			tmp1 = ft_strsub(str, p[0], p[1]);
			tmp2 = ft_strjoin(new, tmp1);
			new = ft_strdup(tmp2);
			ft_strdel(&tmp1);
			ft_strdel(&tmp2);
		}
	}
	ft_strdel(&str);
	return (new);
}

t_new	*rebuild_sb_struct(t_new *n_sb, t_new *s_sb)
{
	t_new		*izi;
	t_new		*s;

	s = s_sb;
	while (s)
	{
		izi = add_sbplease(izi, s->str);
		s = s->next;
	}
	return (izi);
}

t_new	*duplicate_sb(t_new *new, t_new *s)
{
	t_new *save;

	save = new;
	ft_putendl("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
	if (new && s)
	{
		while (save->next != NULL)
		{
			save->sb = rebuild_sb_struct(save->sb, s->sb);
			save = save->next;
		}
		free_new(s->sb);
	}
	ft_putendl("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
	return (new);
}
