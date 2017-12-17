#include "globing.h"

int		check_is_acc(char *str)
{
	int i;
	int cout;

	cout = 0;
	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '{')
			cout++;
		if (cout > 0 && str[i] == '}')
			return (1);
		i++;
	}
	return (0);
}

void	ft_print_tab(char **tab)
{
	int i;

	i = 0;
	ft_putendl("tab : {");
	if (tab)
		while (tab[i] != NULL)
		{
			ft_putendl(tab[i++]);
		}
	ft_putendl("}");
	return;
}

char	**ft_join_tab(char **tab, char *start)
{
	int		i;
	char	**res;
	int		len_tab;

	len_tab = 0;
	if (!tab)
		return (NULL);
	while (tab[len_tab])
		len_tab++;
	res = NULL;
	if (!(res = (char **)malloc(sizeof(char *) * (len_tab + 1))))
		return (NULL);
	i = 0;
	while (tab[i])
	{
		res[i] = ft_strjoin(start, tab[i]);
		i++;
	}
	res[i] = NULL;
	i = 0;
	while (tab[i])
		ft_strdel(&tab[i++]);
	free(tab);
	tab = NULL;
	return (res);
}

int		check_res(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
	{
		if (check_is_acc(tab[i]))
			return (1);
		i++;
	}
	return (0);
}
