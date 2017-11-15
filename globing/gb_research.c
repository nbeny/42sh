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

t_glob	*globing_research(char **cmd)
{
	int			j;
	t_glob		*g;
	t_glob		*s;
	char		**split_acc;
	int			k;

	k = 0;
	split_acc = NULL;
	j = 1;
	g = NULL;
	g = init_glob();
	s = g;
	while (cmd && cmd[j])
	{
		if (check_isglob(cmd[j]))
		{
/*			if (check_is_acc(cmd[j]))
			{
				if (check_is_acc(cmd[j]))
					ft_putendl("chack acc OK");
				split_acc = ft_split_acc(cmd[j]);
				while (split_acc[k])
				{
					ft_putendl("go zoom research");
					s = zoom_research(s, split_acc[k]);
					s->next = add_glob_next(s);
					s = s->next;
					
					k++;
				}
				k = 0;
				while (split_acc[k])
					ft_strdel(&split_acc[k++]);
				free(split_acc);
				split_acc = NULL;
				k = 0;
			}
			else*/
			{
				s = zoom_research(s, cmd[j]);
					s->next = add_glob_next(s);

				s = s->next;
			}
		}
		else
		{
			if (!s->slash)
			{
				if (!s->resforever)
				{
					s->resforever = add_path(s->resforever, cmd[j]);
				}
			}
		}
		j++;
	}
	t_glob *hh;

	hh = g;


	ft_putendl("start print ");
	while (hh){
	while (hh->slash)
	{
			hh = hh->slash;
	}
		while (hh->resforever)
		{
			if ( hh->resforever->str)
				ft_putendl(hh->resforever->str);
			hh->resforever = hh->resforever->next;

		}
		hh = hh->next;}
		return (g);
}
