#include "globing.h"
#include <libft.h>

int		ft_listsize(t_env *e)
{
	t_env	*s;
	int		i;

	i = 0;
	s = e;
	if (e != NULL)
	{
		while (s != NULL)
		{
			i++;
			s = s->next;
		}
	}
	return (i);
}

void	globing_free_new(t_new *new)
{
	t_new	*f;
	t_new	*s;

	s = new;
	if (s != NULL)
		while (s != NULL)
		{
			f = s;
			s = s->next;
			if (f->str != NULL)
				ft_strdel(&(f->str));
			free(f);
			f = NULL;
		}
}

char	**ft_magic_list_to_tab(t_new *new)
{
	char	**tstr;
	char	*stock;
	t_new	*s;
	int		i;

	s = new;
	if (new == NULL)
		return (NULL);
	i = ft_listsize(new);
	if (!(tstr = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	i = 0;
	while (s != NULL)
	{
		stock = ft_strjoin(s->name, "=");
		tstr[i] = ft_strjoin(stock, s->value);
		ft_strdel(&stock);
		i++;
		s = s->next;
	}
	tstr[i] = NULL;
	return (tstr);
}

t_new	*ft_magic_tab_to_list(char **env)
{
	t_	*e;
	t_env	*s;
	int		i;

	i = 1;
	if (env == NULL || env[0] == NULL)
		return (NULL);
	if (!(e = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	e->name = ft_strsub(env[0], 0, (ft_equal(env[0]) - 1));
	e->value = ft_strdup(&env[0][ft_equal(env[0])]);
	s = e;
	while (env[i] != NULL)
	{
		if (!(s->next = (t_env *)malloc(sizeof(t_env))))
			return (NULL);
		s = s->next;
		s->name = ft_strsub(env[i], 0, (ft_equal(env[i]) - 1));
		s->value = ft_strdup(&env[i][ft_equal(env[i])]);
		i++;
	}
	s->next = NULL;
	return (e);
}
