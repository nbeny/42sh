#include "globing.h"
//gg

t_new	*init_new()
{
	t_new	*new;

	if (!(new = (t_new *)malloc(sizeof(t_new))))
		return (NULL);
	new->str = NULL;
	new->next = NULL;
	return (new);
}

t_new	*add_new(t_new *new)
{
	t_new	*s;

	ft_putstr("new()");
	s = new;
	if (s != NULL)
	{
		while (s->next != NULL)
			s = s->next;
		s->next = init_new();
		s = s->next;
	}
	else
	{
		s = init_new();
		return (s);
	}
	return (new);
}

int		check_sbmatch(char *s1, t_new *sb)
{
	t_new	*s;
	int		i;
	int		ret;

	ret = -1;
	s = sb;
	i = 0;
	if (sb->str == NULL)
		ft_putendl("&&&&&&&&&&&&&&&&&&&&&");
	ft_putendl(sb->str);
	if (sb)
		while (sb->str && sb->str[i])
		{
			if (i == 0 && sb->str[0] == '!' && sb->str[i + 1] != '\0')
			{
				if (!(ret = sb_exclammatch(*s1, sb->str, &i)))
					return (0);
			}
			else if (i == 0 && sb->str[0] == '^' && sb->str[i + 1] != '\0')
			{
				if (!(ret = sb_exclammatch(*s1, sb->str, &i)))
					return (0);
			}
			else if (i > 0 && sb->str[i] == '-' && sb->str[i + 1] != '\0')
				ret = sb_lessmatch(*s1, sb->str, &i);
			else if (sb->str[i] == '[' && sb->str[i + 1] != '\0')
			{
				if (check_name_pos(&(sb->str)[i]))
					ret = sb_classmatch(*s1, sb->str, &i);
				else
					ret = sb__match_no(*s1, sb->str, &i);
			}
			else
				ret = sb__match(*s1, sb->str, &i);
			if (ret == 1)
				return (1);
		}
	ft_putendl("END check_sbmatch");
	return (0);
}

int		nmatch(char *s1, char *s2, t_new *sb)
{
	int		i;

	i = -1;
	ft_putendl("---->>>>> namtch");
	ft_putendl("#################################################################################");
//	ft_putendl(sb->str);
	ft_putendl("#################################################################################");
	if (s1 == NULL || s2 == NULL)
		return (0);
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (*s1 != '\0' && *s2 == '*')
		return (nmatch(s1 + 1, s2, sb) + nmatch(s1, s2 + 1, sb));
	if (*s1 == '\0' && *s2 == '*')
		return (nmatch(s1, s2 + 1, sb));
	if (sb && *s2 == -42 && *s1 != '\0' && *s2 != '\0')
	{
		ft_putstr("\t NAMATCH condition");
		ft_putendl(sb->str);
		i = check_sbmatch(s1, sb);
		if (i == 0)
			return(0);
		else
			return (nmatch(s1 + 1, s2 + 1, sb->next));
	}
	if ((*s1 == *s2 || *s2 == '?') && *s1 != '\0' && *s2 != '\0')
		return (nmatch(s1 + 1, s2 + 1, sb));
	if ((*s1 == *s2 || *s2 == '?') && *s1 == '\0' && *s2 == '\0')
		return (1);
	return (0);
}

t_glob	*check_slash(t_glob *g, t_new *st_path)
{
	char				*path;
	t_new				*rec_path;
	t_new				*f_path;
	t_new				*izi;
	t_glob				*sg;

//	(void)i;
	sg = g;
	f_path = st_path;
	ft_putendl("ft_check_slash");
//	if (i == 1)
//		g->slashzero = 1;
//	else if (g->slashzero == 1)
//	{
//		ft_putstr("oui");
//		g->slashzero = 0;
//		g = g->slash;
//		g->slashzero = 1;
//	}
//	else
//		ft_putstr("non");
//	sleep(1);
	rec_path = NULL;
	path = NULL;
	izi = NULL;
	ft_putstr("---check_slash >>>recurisif<<<\n");
//	if (st_path->str)
//		ft_putstr(st_path->str);
//	if (g->new)
//		ft_putendl(g->new->str);
	while (st_path != NULL)
	{
		ft_putstr("/n<*>/n");
//		sleep(1);
		if (g->slash != NULL)
		{
			ft_putendl("g->slash == NULL go to match_rep");
			rec_path = match_rep(g, st_path->str);
			izi = join_list(izi, rec_path);
		}
		else
		{
			ft_putendl("g->slash != NULL go to match_file");
			g = match_file(g, st_path->str);
			t_new				*ssss = g->resforever;
			ft_putendl("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
			while (ssss)
			{
				ft_putendl(ssss->str);
				ssss = ssss->next;
			}
			ft_putendl("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
//			sleep(3);
		}
		st_path = st_path->next;
	}
	ft_putstr("before go recu ckeck_slash rec_path == ");
	if (rec_path && rec_path->str)
		ft_putendl(rec_path->str);
	ft_putnbr(g->slashzero);
//	g->slash->slashzero = 1;
	if (izi != NULL)
	{
		free_resforever(st_path);
		return(check_slash(g->slash, izi));
	}
	else
		return (g);
}

t_glob	*do_we_match(t_glob	*g)
{
	int		i;
	t_new	*new;
	t_arg	*s;
	char	*str;
	char	*tmp;
	t_new	*st_path;
	t_glob	*gs;

	st_path = NULL;
	ft_putendl("DOWEMATCH()");
	gs = g;
	s = g->arg;
	new = g->new;
	str = NULL;
	tmp = NULL;
	i = 0;
	while (gs != NULL)
	{
		s = gs->arg;
		while (s != NULL)
		{
			if (s->id == 0)
				gs = add_word(gs, s->str);
			else if (s->id == 1)
				gs = add_interro(gs);
 			else if (s->id == 2)
				gs = add_sb(gs, s->str);
			else if (s->id == 3)
				gs = add_accolade(gs, s->str);
			s = s->next;
		}
		ft_putendl("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
		t_new *ssss = gs->new;
		while (ssss)
		{
			ft_putendl(ssss->str);
			ssss = ssss->next;
		}
		ft_putendl("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
		new = NULL;
		gs = gs->slash;
	}
	if (g->slashzero == 0)
		tmp = getcwd(NULL, 1024);
	else
		tmp = ft_strdup("/");
	st_path = add_path(st_path, tmp);
	ft_strdel(&tmp);
	g = check_slash(g, st_path);
	return (g);
}
