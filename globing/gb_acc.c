#include "globing.h"

int check_is_acc(char *str)
{
	int i;
	int cout;

	ft_putendl("check is acc");
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

void ft_print_tab(char **tab)
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
}

char **ft_join_tab(char **tab, char *start)
{
	int i;
	char **res;
	int len_tab;

	len_tab = 0;
	if (!tab)
		return (NULL);
	while (tab[len_tab])
		len_tab++;
	res = NULL;
	res = (char **)malloc(sizeof(char *) * len_tab);
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
	return (res);
}
char **ft_split_acc(char *str)
{
	int i;
	char **res;
	char *start;
	char *tmp;
	int j;

	j = 0;
	i = 0;
	tmp = NULL;
	start = NULL;
	res = NULL;
	start = ft_strdup("\0");
	
	while (str[i] != '\0')
	{
		if (str[i] == '{')
		{
			tmp = ft_strsub(str,0, i );
			j = i + 1;
			if (tmp)
				start = ft_strjoin(start, tmp);
			while (str[i] != '}')
			{
				i++;
			}
			ft_strdel(&tmp);
			tmp = ft_strsub(str, j, i);
			ft_putendl(tmp);
			if (res ==  NULL)
			{
				res = ft_strsplit(tmp, ',');
				res = ft_join_tab(res, start);
			}
			ft_strdel(&tmp);
		}
			i++;
	}
	
	ft_print_tab(res);
	sleep(3);
	ft_putendl(start);
	return (res);
}
