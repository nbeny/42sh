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
		ft_putendl(s->str);
		while (s != NULL)
		{
			i = 0;
			ft_putendl("wesh");
			while (split && split[i])
			{
				ft_putendl("couble");
				izi = add_joinaccolade(izi, s->str, split[i]);
				i++;
			}
			s = s->next;
		}
	}
	else
	{
		while (split && split[i])
		{
			ft_putendl("123");
			izi = add_dupaccolade(izi, split[i]);
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
			tmp2 = ft_strjoin(tmp1, sb->str);
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
	if (new[0] == '\0')
		return (NULL);
	else
		return (new);
	/*
	int i;
	char *new_path;
	char *tmp;
	int j;
	char *ff;

	ft_putendl("REBUILDDDDD");
	ft_putendl(sb);
	ft_putendl(str);
	ff = NULL;
	j = 0;
	tmp = NULL;
	new_path = NULL;
	if (!str || !sb)
		return (NULL);
	if (str[0] != -42)
	{
		while (str[i] != -42)
			i++;
		new_path = ft_strsub(str, 0, i);
		tmp = ft_strjoin(new_path, "[");
	}
	else
		tmp = ft_strdup("[");

	ft_strdel(&new_path);

	new_path = ft_strjoin(tmp, sb);
	ft_strdel(&tmp);
	tmp = ft_strjoin(new_path, "]");
	ft_strdel(&new_path);
	i++;
	j = i;
	while (str[i])
		i++;
	new_path = ft_strsub(str, j, i);
	ff = ft_strjoin(tmp, new_path);
	ft_putendl("RET REBUILDPATH:");
	ft_putendl(ff);
		return (NULL);
	*/
}
