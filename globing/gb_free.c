#include "globing.h"

void	free_arg(t_arg *arg)
{
	t_arg		*s;
	t_arg		*f;

	s = arg;
	f = NULL;
	while (s)
	{
		ft_putendl("aaaaaaaaaaaaaarrrrrrrrrrrrrgggggggggggggggg");
		f = s;
		if (s && s->str)
			ft_strdel(&(s->str));
		ft_putendl("aaaaaaaaaaaaaarrrrrrrrgggggggsssssssstttttttttrrrrrrrrrrrrrr");
		s = s->next;
		free(f);
		f = NULL;
	}
	ft_putendl("EEEEEEEEEEEEEEEEENNNNNNNNNNNNNNNNNNNNNNNNNNNDDDDDDDDDDDDDDDDDDD");
}

void	free_new(t_new *new)
{
	t_new		*s;
	t_new		*f;
	t_new		*sb;

	s = new;
	f = NULL;
	sb = NULL;
	while (s)
	{
		f = s;
		if (s->str)
			ft_strdel(&(s->str));
/*		sb = s->sb;
		while (sb)
		{
			f = sb;
			ft_strdel(&(sb->str));
			sb = sb->next;
			free(f);
			f = NULL;
			}*/
		s = s->next;
		free(f);
		f = NULL;
	}
}

void	free_resforever(t_new *resforever)
{
	t_new		*s;
	t_new		*f;

	s = resforever;
	f = NULL;
	while (s)
	{
		f = s;
		ft_strdel(&(s->str));
		s = s->next;
		free(f);
		f = NULL;
	}
}

void	free_glob_slash(t_glob *g)
{
	t_glob		*s;
	t_glob		*f;

	s = g;
	f = NULL;
	if (s)
	{
		ft_putendl("1111111111111111111111111111111");
		if (s->arg)
			free_arg(s->arg);
		ft_putendl("222222222222222222222222222222");
		if (s->new)
			free_new(s->new);
		ft_putendl("33333333333333333333333333333333");
//		if (s->resforever)
//			free_resforever(s->resforever);
		ft_putendl("444444444444444444444444444444444444");
		s = s->slash;
	}
	while (s)
	{
		ft_putendl("555555555555555555555555555555555");
		if (s->arg)
			free_arg(s->arg);
		ft_putendl("6666666666666666666666666666666666");
		if (s->new)
			free_new(s->new);
		ft_putendl("77777777777777777777777777777777");
		if (s->resforever)
			free_resforever(s->resforever);
		ft_putendl("888888888888888888888888888888888");
		f = s;
		s = s->slash;
		free(f);
		s = NULL;
	}
}
