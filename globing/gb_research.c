#include "globing.h"

t_glob	*remake_arg(t_glob *g, char *line)
{
	t_arg	*s;
	char	*tmp1;
	char	*tmp2;

	tmp1 = NULL;
	tmp2 = NULL;
	s = g->arg;
	if (s != NULL)
	{
		while (s->next != NULL)
			s = s->next;
		tmp1 = ft_strdup(s->str);
		tmp2 = ft_strsub(line, g->p[0], g->p[1]);
		ft_strdel(&(s->str));
		s->str = ft_strjoin(tmp1, tmp2);
		ft_strdel(&tmp1);
		ft_strdel(&tmp2);
	}
	else
	{
		g = add_arg(g, line, 0);
	}
	return (g);
}

t_glob	*zoom_research(t_glob *g, char *line)
{
	t_glob	*s;
	int		i;

	i = 0;
	s = g;
	if (line == NULL)
	{
		ft_putstr("zoom reasearch null return ");
		return (NULL);
	}
	while (line[i])
	{
		ft_putnbr(i);
		if (line[i] == '/')
			s = slash_gestion(s, line, &i);
		if (line[i] == '[')
			s = square_bracket(s, line, &i);
		else if (line[i] == '{')
		{
			ft_putchar('q');
			s = accolade(s, line, &i);
		}
		else if (line[i] == '?')
			s = interogation(s, line, &i);
		else
			s = part_arg(s, line, &i);
	}
	g = do_we_match(g);
	ft_putendl("return zoom search");
	return (g);
}

int		check_isglob(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '*' || line[i] == '?' ||\
			line[i] == '[' || line[i] == '{')
			return (1);
		i++;
	}
	return (0);
}

char	**globing_research(char **cmd)
{
	int			j;
	t_new		*res;
	char		**end;
	t_glob		*g;
	t_glob		*s;
	char		**split_acc;

	split_acc = NULL;
	j = 1;
	g = NULL;
	if (!(g = (t_glob *)malloc(sizeof(t_glob))))
		return (NULL);
	res = NULL;
	while (cmd && cmd[j])
	{
		g = init_glob();
		if (check_isglob(cmd[j]))
		{
			g = zoom_research(g, cmd[j]);
			s = g;
			while (s->slash)
				s = s->slash;
			res = join_list(res, s->resforever);
		}
		else
		{
			res = add_path(res, cmd[j]);
		}
		j++;
	}
	ft_putendl("start print ");
	while (res)
	{
		ft_putendl(res->str);
		res = res->next;
	}
	end = list_to_tab_new(res);
	j = 0;
	while (end && end[j])
	{
		ft_putendl(end[j]);
		j++;
	}
	return (end);
}
