/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_acc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 00:44:11 by nbeny             #+#    #+#             */
/*   Updated: 2017/11/27 00:44:15 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "globing.h"

char	**ft_split_acc_tab(char **tab)
{
	int		i;
	char	**res;
	char	**tmp;
	int		j;

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
	if (tmp)
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

t_utils *init_ut(t_utils *ut, char *str)
{
	ut->j = 0;
	ut->i = 0;
	ut->tmp = NULL;
	ut->start = NULL;
	ut->res = NULL;
	ut->str = str;
	ut->tmp2 = ft_strdup("\0");	
	return (ut);
}

t_utils *ft_create_res(t_utils *ut)
{
	if (ut->res ==  NULL)
	{
		ut->res = ft_strsplit(ut->tmp, ',');
		ft_strdel(&ut->tmp);
		ut->tmp = NULL;
		ut->res = ft_join_tab(ut->res, ut->start);
		ft_print_tab(ut->res);
		ft_strdel(&(ut->start));
		if (ut->str[ut->i] != '\0')
		{
			ut->j = ut->i + 1;
			while (ut->str[ut->i])
				ut->i++;
			ut->tmp = ft_strsub(ut->str, ut->j, ut->i);
			ut->res = ft_join_tab_end(ut->res, ut->tmp);
		}
	}
	return (ut);
}

char	**ft_split_acc(char *str, int check)
{
	t_utils *ut;
	char **res;
	
	ut = malloc(sizeof(t_utils));
	ut = init_ut(ut, str);
	while (str && str[ut->i] != '\0')
	{
		if (str[ut->i] == '{')
		{
			ut->tmp = ft_strsub(ut->str, 0, ut->i);
			ut->j = ut->i + 1;
			if (ut->tmp)
				ut->start = ft_strjoin(ut->tmp2, ut->tmp);
			ft_strdel(&(ut->tmp));
			ft_strdel(&(ut->tmp2));
			ut->tmp2 = NULL;
			ut->res = NULL;
			while (str[ut->i] != '\0' && str[ut->i] != '}')
				ut->i++;
			ut->tmp = ft_strsub(str, ut->j, ut->i);
			ut = ft_create_res(ut);
			ft_strdel(&(ut->tmp));
		}
		if (str[ut->i] == '\0')
			break ;
		ut->i++;
	}
	(void)check;
	res = ut->res;
	free(ut);
	ft_putstr("hehre");
	return (res);
}

