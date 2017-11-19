#include "globing.h"

void	free_split(char **split)
{
	int		i;

	i = 0;
	while (split && split[i])
	{
		ft_strdel(&(split[i]));
		i++;
	}
	free(split);
	split = NULL;
}

void	free_arg(t_arg *arg)
{
	t_arg		*s;
	t_arg		*f;

	ft_putstr("free_sb");
	s = arg;
	f = NULL;
	while (s)
	{
		printf(GREEN"\nfree :  %p"RESET"\n",arg);
		f = s;
		ft_strdel(&(s->str));
		s = s->next;
		free(f);
		f = NULL;
	}
}

void	free_new(t_new *new)
{
	t_new		*s;
	t_new		*f;

	ft_putstr("free_new");
	s = new;
	f = NULL;
	while (s)
	{
		printf(GREEN"\nfree :  %p"RESET"\n",s);
		f = s;
		ft_strdel(&(s->str));
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
	while (s != NULL)
	{
		if (s->arg)
			free_arg(s->arg);
		if (s->new)
			free_new(s->new);
		if (s->sb != NULL)
			free_new(s->sb);
		f = s;
		s = s->slash;
		printf(GREEN"free :  %p"RESET"\n",f);
		free(f);
		f = NULL;
	}
}