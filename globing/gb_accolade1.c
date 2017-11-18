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
				izi = add_joinaccolade(izi, s->str, split[i]);
				i++;
			}
			s = s->next;
		}
		free_new(new);
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
	free_split(split);
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
	new = NULL;
	while (str && str[i] && sb)
	{
		if (str[i] == -42)
		{
			i++;
			tmp1 = ft_strjoin(new, "[");
			tmp2 = ft_strjoin(tmp1, s->str);
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
/*
t_new	*rebuild_sb_struct(t_new *n_sb, t_new *s_sb)
{
	t_new		*izi;
	t_new		*s;

	s = s_sb;
	ft_putendl("((((((((((((((((((REBUILD_SB_STRUCT))))))))))))))))))");
	while (s)
	{
		ft_putstr("<i>");
		izi = add_sbplease(izi, s->str);
		s = s->next;
	}
	ft_putendl("((((((((((((((((((endREBUILD_SendB_STRUCTend))))))))))))))))))");
	return (izi);
	}*/
/*
t_new	*duplicate_sb(t_new *new, t_new *s)
{
	t_new *save;

	save = new;
	ft_putendl("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
	if (new && s)
	{
		ft_putendl("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
		while (save->next != NULL)
		{
			ft_putendl("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
			if (s && s->sb)
			{
				ft_putendl("boom");
				save->sb = rebuild_sb_struct(save->sb, s->sb);
			}
			ft_putendl("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
			save = save->next;
		}
		free_new(s->sb);
	}
	ft_putendl("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
	return (new);
}
*/
