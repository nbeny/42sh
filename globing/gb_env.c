#include "globing.h"

char	*gb_get_env(char **env)
{
	size_t	i;
	char	*home;

	home = NULL;
	i = 0;
	ft_putstr("ok");
	while (env && env[i])
	{
		if (!ft_strncmp(env[i], "HOME=", 5) && ft_strlen(env[i]) > 5)
		{
			home = ft_strdup(&env[i][5]);
			ft_putendl(home);
			return(home);
		}
		i++;
	}
	ft_putstr("ok");
	return (NULL);
}
