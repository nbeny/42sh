#include "globing.h"

int check_is_acc(char *str)
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
	if (!(res = (char **)malloc(sizeof(char *) * (len_tab + 1) )))
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

char **ft_join_tab_end(char **tab, char *end)
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
	if (!(res = (char **)malloc(sizeof(char *) * (len_tab + 1))))
		return (NULL);
	i = 0;
	while (tab[i])
	{
		res[i] = ft_strjoin(tab[i], end);
		i++;
	}
	res[i] = NULL;
	i = 0;
	while (tab[i])
		ft_strdel(&tab[i++]);
	free(tab);
	return (res);
}

int check_res(char **tab)
{
	int i;

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

void ft_free_array(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_strdel(&tab[i++]);
	}
	free(tab);
	tab = NULL;
}

char **ft_fusion_array(char **tab1, char **tab2)
{
	int i;
	char **res;
	int len_tab;
	int len_tab2;

	len_tab2 = 0;
	len_tab = 0;
	if (!tab1 && tab2)
		return (tab2);
	else if (tab1 && !tab2)
		return (tab1);
	else if (!tab1 && !tab2)
		return NULL;
	while (tab1[len_tab])
		len_tab++;
	while (tab2[len_tab2])
		len_tab2++;
	res = NULL;
	if (!(res = (char **)malloc(sizeof(char *) * (len_tab + len_tab2 + 1) )))
		return (NULL);
	i = 0;
	while (tab1[i])
	{
		res[i] = ft_strdup(tab1[i]);
		i++;
	}
	len_tab = 0;
	while (tab2[len_tab])
	{
		res[i] = ft_strdup(tab2[len_tab]);
		len_tab++;
		i++;
	}
	res[i] = NULL;
	ft_free_array(tab1);
	ft_free_array(tab2);
	return (res);	
}

char **ft_split_acc_tab(char **tab)
{
	int i;
	char **res;
	char **tmp;
	int j;

	tmp = NULL;
	res = NULL;
	i = 0;
	if (!tab)
		return (NULL);
	while (tab[i])
	{
		{
			tmp = ft_split_acc(tab[i], 0);
			res = ft_fusion_array(res, tmp);
			ft_print_tab(res);
			tmp = NULL;
		}
		i++;
	}
	j = 0;
	if(tmp)
	{
		while (tmp[j])
			ft_strdel(&tmp[j++]);
		free(tmp);
	}
	i = 0;
	while (tab[i])
		ft_strdel(&tab[i++]);
	free (tab);
	return (res);
}
char **ft_split_acc(char *str, int check)
{
	int i;
	char **res;
	char *start;
	char *tmp;
	int j;
	char *tmp2;
	
	j = 0;
	i = 0;
	tmp = NULL;
	start = NULL;
	res = NULL;
	tmp2 = ft_strdup("\0");
	while (str && str[i] != '\0')
	{
		if (str[i] == '{')
		{
			tmp = ft_strsub(str,0, i );
			j = i + 1;
			if (tmp)
				start = ft_strjoin(tmp2, tmp);
			ft_strdel(&tmp);
			ft_strdel(&tmp2);
			tmp2 = NULL;
			res = NULL;
			while (str[i] != '\0' && str[i] != '}')
				i++;
			tmp = ft_strsub(str, j, i);
			if (res ==  NULL)
			{
				res = ft_strsplit(tmp, ',');
				ft_strdel(&tmp);
				tmp = NULL;
				res = ft_join_tab(res, start);
				ft_print_tab(res);
				ft_strdel(&start);
				if (str[i] != '\0')
				{
					j = i + 1;
					while (str[i])
						i++;
					tmp = ft_strsub(str, j, i);
					res = ft_join_tab_end(res, tmp);
				}
			}
			ft_strdel(&tmp);
		}
		if (str[i] == '\0')
		break ;
			i++;
	}
	i = 0;
	(void)check;
	return (res);
}

