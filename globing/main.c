#include "globing.h"

int main(int ac, char **av)
{
	char	**str;
	int		i;

	i = 0;
	str = globing_research(av);
	while (str && str[i])
	{
		ft_putendl(str[i]);
		i++;
	}
	i = 0;
	while(str && str[i])
	{
		ft_strdel(&str[i]);
	}
	free(str);
	str = NULL;
	return (0);
}
