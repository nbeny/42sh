#include "globing.h"
//gg

t_new	*init_new()
{
	t_new	*new;

	if (!(new = (t_new *)malloc(sizeof(t_new))))
		return (NULL);
	new->str = NULL;
	new->sb = NULL;
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
		{
//			if (s->str != NULL)
//				ft_putendl(s->str);

			s = s->next;
		}
		s->next = init_new();
		s = s->next;
	}
	else
	{
		s = init_new();
		return (s);
	}
//	ft_putendl("return ft_add_new()");
	return (new);
}
/*int nmatch(char *s1, char *s2)
  {
  if (!*s1 && !*s2)
  return (1);
  else if (*s1 == *s2 && *s1 != '*')
  return (nmatch(s1 + 1, s2 + 1));
  else if (*s1 == '*' && *s2 == '*')
  return (nmatch(s1 + 1, s2));
  else if (*s2 == '*' && !*s1)
  return (nmatch(s1, s2 + 1));
  else if (*s2 == '*' && *s2 && *s1)
  return (nmatch(s1, s2 + 1) + nmatch(s1 + 1, s2));
  else
  return (0);
  }
*/
int		check_sbmatch(char *s1, t_new *sb)
{
	ft_putstr("check_sbmatch");
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
	ft_putstr("---->>>>> namtch");
	if (s2 == NULL && s1 == NULL)
		return (1);
	if (*s1 != '\0' && *s2 == '*')
		return (nmatch(s1 + 1, s2, sb) + nmatch(s1, s2 + 1, sb));
	if (*s1 == '\0' && *s2 == '*')
		return (nmatch(s1, s2 + 1, sb));
	if (sb && *s2 == -42 && *s1 != '\0' && *s2 != '\0')
	{
		ft_putstr("\t NAMATCH condition");
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
t_new *ft_add_end(t_new *gres, t_new *n)
{
	t_new *s;

	if (gres)
	{
		s = gres;				
		while (gres)
		{

			if (gres->next == NULL)
			{
				gres->next = n;
				break ;
			}
						gres = gres->next;
		}
		return (s);
	}
	else
		return (n);
}

t_glob	*check_slash(t_glob *g, t_new *st_path, int i, int ret)
{
	char				*path;
	t_new				*rec_path;
	t_new				*izi;
	t_glob *sg;

	(void)i;
	sg = g ;
	ft_putendl("ft_check_slash");
	if (i == 1)
		g->slashzero = 1;
	else if (g->slashzero == 1)
	{
		ft_putstr("oui");
		g->slashzero = 0;
		g = g->slash;
		g->slashzero = 1;
	}
//	else if (i == 1)
//	{
//		g->slash->slashzero = 1;
//		ft_putstr("peut_etre");
//	}
	else
	{
		ft_putstr("non");
	}
//	g = g->slash;
//	sleep(1);
	rec_path = NULL;
	path = NULL;
	izi = NULL;
	ft_putstr("---check_slash >>>recurisif<<<\n");
	if (st_path->str)
		ft_putstr(st_path->str);
	if (g->new)
		ft_putendl(g->new->str);
	while (st_path != NULL)
	{
		ft_putstr("/n<*>/n");
//		sleep(1);
		if (g->slash != NULL)
		{
			ft_putendl("g->slash == NULL go to match_rep");
			rec_path = match_rep(g, st_path->str);
		}
		else
		{
			i = 1;
			ft_putendl("g->slash != NULL go to match_file");
			g->resforever = match_file(g, st_path->str);
			t_new				*ssss = g->resforever;
			ft_putendl("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
			while (ssss)
			{
				ft_putendl(ssss->str);
				ssss = ssss->next;
			}
			ft_putendl("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
//			sleep(3);
//			g->resforever = ft_add_end(g->resforever, izi);
//			g->resforever = izi;
			
				}
		st_path = st_path->next;
	}
	ft_putstr("before go recu ckeck_slash rec_path == ");
	if (rec_path && rec_path->str)
		ft_putendl(rec_path->str);
	ft_putnbr(g->slashzero);
//	g->slash->slashzero = 1;
	if (rec_path != NULL)
		return(check_slash(g->slash, rec_path, g->slashzero, i++));
	else
		return (g);
	t_glob *hh;
	hh = g;
	ft_putstr("heeeeere");
	while (hh->slash)
		hh = hh->slash;
	
	while (hh->resforever)
	{
		if (hh->resforever->str)
			ft_putendl(hh->resforever->str);
		hh->resforever = hh->resforever->next;
	}
//	return (sg);
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
	t_new		*ssss;
	st_path = NULL;
	sleep(5);
	ft_putendl("DOWEMATCH()");
	gs = g;
	s = g->arg;
	new = g->new;
	str = NULL;
	tmp = NULL;
	i = 0;
	if (s == NULL)
	{
		ft_putstr("qwerqwerqwerqwerqwerqwerqwer\n");
//		return (g);
	}
	if (s != NULL)
		ft_putendl("s non null;");
	while (gs != NULL)
	{
		s = gs->arg;
		while (s != NULL)
		{
			ft_putendl("while in dowee");
			ft_putstr(s->str);
			printf("\n{[-%p-]}\n", new);fflush(stdout);
			if (s->id == 0)
				new = add_word(new, s->str);
			else if (s->id == 1)
				new = add_interro(new);
			else if (s->id == 2)
				new = add_sb(new, s->str);
			else if (s->id == 3)
				new = add_accolade(new, s->str);
			s = s->next;
		}
//		ft_putstr(new->str);
		gs->new = new;
		new = NULL;
		ssss = gs->new;
		ft_putendl("/****************************************????????????????????***********************************/");
		while (ssss)
		{
			ft_putendl(ssss->str);
			ssss = ssss->next;
		}
		gs = gs->slash;
	}
//	sleep(3);
//	g->new = new;


	ft_putendl("end while dowee");
	if (g->slashzero == 0)
		tmp = getcwd(NULL, 1024);
	else
		tmp = ft_strdup("/");

	
	ft_putstr(tmp);
	if (g->slash == NULL)
		ft_putendl("g->s NULL");
	else
		ft_putendl("g->slash");
//	sleep(4);

	st_path = add_path(st_path, tmp);
	ft_strdel(&tmp);
	if (g->slashzero == 0)
		g = check_slash(g, st_path, 0, 0);
	else
		g->slash = check_slash(g, st_path, 0, 0);
	return (g);
}

