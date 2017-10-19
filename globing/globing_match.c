#include "globing.h"

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

	s = new;
	if (s = NULL)
	{
		while (s != NULL)
			s = s->next;
		s->next = init_new();
		s = s->next;
	}
	else
	{
		s = init_new();
	}
	return (new);
}

t_new	*check_walcards(t_new *new)
{
	t_new			*s;
	t_new			*izi;
	t_new			*s_izi;
	char			*path;
	struct dirent	*d;
	DIR				*dir;

	s = new;
	while (s != NULL)
	{
		path = getcwd(NULL, 1024);
		dir = opendir(path);
		izi = add_new(izi);
		s_izi = izi;
		while (d = readdir(dir) != NULL)
		{
			if (nmatch(str, d->d_name) != 0)
			{
				s_izi->next = add_new(izi);
				s_izi = s_izi->next;
				s_izi->str = ft_strdup(d->d_name);
			}
		}
		closedir(dir);
		s = s->next;
	}
	globing_free_new(new);
	return (izi);
}

t_new	*do_we_match(t_arg *arg, t_new *new)
{
	int		i;
	t_arg	*s;
	char	*str;
	char	*tmp;

	s = arg;
	str = NULL;
	tmp = NULL;
	i = 0;
	while (s != NULL)
	{
		if (s->id == 0)
			new = add_word(new, s->str);
		else if (s->id == 1)
			new = add_interogation(new);
		else if (s->id == 2)
			new = add_square_bracket(new, s->str);
		else if (s->id == 3)
			new = add_accolade(new, s->str);
		s = s->next;
	}
	new = check_walcards(new);
	return (new);
}
