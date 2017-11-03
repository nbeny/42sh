#include "globing.h"
//gg
#include <sys/types.h>
#include <sys/dir.h>

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
		}*/
int		nmatch(char *s1, char *s2)
{
	if (s2 == NULL && s1 == NULL)
		return (1);
	if (*s1 != '\0' && *s2 == '*')
		return (nmatch(s1 + 1, s2) + nmatch(s1, s2 + 1));
	if (*s1 == '\0' && *s2 == '*')
		return (nmatch(s1, s2 + 1));
	if ((*s1 == *s2 || *s2 == '?') && *s1 != '\0' && *s2 != '\0')
		return (nmatch(s1 + 1, s2 + 1));
	if ((*s1 == *s2 || *s2 == '?') && *s1 == '\0' && *s2 == '\0')
		return (1);
	return (0);
}

t_new	*check_walcards(t_new *new)
{
	t_new			*s;
	t_new			*izi;
	t_new			*s_izi;
	char			*path;
	struct dirent	*d;
	DIR				*dir;

	izi = NULL;
	ft_putendl("chECK_WAlcard");
	s = new;
	izi = add_new(izi);
	s_izi = izi;
	while (s != NULL)
	{
		path = getcwd(NULL, 1024);
		dir = opendir(path);
		
		//LEAAAKS
		while ((d = readdir(dir)) != NULL)
		{
			if (d->d_name[0] != '.')
			{
				ft_putendl(d->d_name);
				ft_putendl(s->str);
/*				if (check_char42(s->str))
				{
					ft_putstr("OUI");
					reverse_char42(d->d_name);
					ft_putchar('\t');
					ft_putendl(d->d_name);
					ft_putchar('\t');
					}*/
				if (nmatch(d->d_name, s->str) != 0)
				{
//					get_char42(d->d_name);
					ft_putendl("\nnmatch found");
					s_izi = add_new(s_izi);
					s_izi = s_izi->next;
					s_izi->str = ft_strdup(d->d_name);
				}
				else
					ft_putendl("no natch found");
			}
		}
		closedir(dir);
		s = s->next;
	}
	// MAYBE WRONG
//	if (izi->str == NULL)
//		free(izi);
	ft_putendl("return chECK_WAlcard");
	s_izi = izi;
	s_izi = s_izi->next;
	if (izi->str == NULL)
		ft_putendl("ASDASDAS");
	while (s_izi != NULL)
	{
		ft_putendl(s_izi->str);
		s_izi = s_izi->next;
	}
//	globing_free_new(new);
	return (izi);
}

#include <stdio.h>

t_new	*do_we_match(t_arg *arg, t_new *new)
{
	int		i;
	t_arg	*s;
	char	*str;
	char	*tmp;
	ft_putendl("DOWEMATCH()");
	s = arg;
	str = NULL;
	tmp = NULL;
	i = 0;
	if (arg == NULL)
		return (NULL);
	if (s != NULL)
		ft_putendl("s non null;");
	while (s != NULL)
	{
		ft_putendl("while in dowee");
		printf("\n{[-%p-]}\n", new);fflush(stdout);
		if (s->id == 0)
			new = add_word(new, s->str);
		else if (s->id == 1)
			new = add_interro(new);
//			new = add_interogation(new);
		else if (s->id == 2)
			new = add_square_bracket(new, s->str);
		else if (s->id == 3)
			new = add_accolade(new, s->str);
		s = s->next;
	}
	ft_putendl("end while dowee");
	new = check_walcards(new);
	return (new);
}
