#include "globing.h"

char	*gb_get_env(char **env)
{
	size_t	i;
	char	*home;

	home = NULL;
	i = 0;
	while (env && env[i])
	{
		if (!ft_strncmp(env[i], "HOME=", 5) && ft_strlen(env[i]) > 5)
		{
			home = ft_strdup(&env[i][5]);
			return(home);
		}
		i++;
	}
	return (NULL);
}
/*
t_new	*gb_home_path(t_new *res, t_glob *g)
{
	t_new	*s;
	char	*tmp1;
	char	*tmp2;

	tmp1 = NULL;
	tmp2 = NULL;
	s = res;
	while (s)
	{
		tmp1 = ft_strjoin(g->home, "/");
		tmp2 = ft_strdup(s->str);
		ft_strdel(&(s->str));
		s->str = ft_strjoin(tmp1, tmp2);
		ft_strdel(&tmp1);
		ft_strdel(&tmp2);
		s = s->next;
	}
	return (res);
}
*/
