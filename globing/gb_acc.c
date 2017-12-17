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

//			while (1);

	tmp = NULL;
	res = NULL;
	i = 0;
	if (!tab)
		return (NULL);
	while (tab[i])
	{
			tmp = ft_split_acc(tab[i], 0);
			while(1);
			res = ft_fusion_array(res, tmp);
//						while(1);
			ft_print_tab(res);
			tmp = NULL;

		i++;
	}
				
			ft_free_array(tmp);
	ft_free_array(tab);
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
	ut->res2 = NULL;
	return (ut);
}

t_utils *ft_create_res(t_utils *ut)
{
	
	if (ut->res ==  NULL)
	{
		ut->res = ft_strsplit(ut->tmp, ',');
		printf(RED"5 CREATE ut->res = %p\n"RESET, ut->res);
		ft_strdel(&ut->tmp);
		ut->tmp = NULL;
		ut->res = ft_join_tab(ut->res, ut->start);
	printf(RED"5 AFTER join tab ut->res = %p\n"RESET, ut->res);	
		ft_print_tab(ut->res);
		ft_strdel(&(ut->start));
		if (ut->str[ut->i] != '\0')
		{
			ut->j = ut->i + 1;
			while (ut->str[ut->i])
				ut->i++;
			ut->tmp = ft_strsub(ut->str, ut->j, ut->i);
			printf(RED"5 RES bef join tab endut->res = %p\n"RESET, ut->res);
			ut->res = ft_join_tab_end(ut->res, ut->tmp);
			printf(RED"5 AFTER JOIN TAB END ut->res = %p\n"RESET, ut->res);
		}
	}
   	printf("5 ut->tmp = %p\n", ut->tmp);
	printf("5 ut->str = %p\n", ut->str);
	printf("5 ut->res = %p\n", ut->res);
	return (ut);
}

char	**ft_split_acc(char *str, int check)
{
	t_utils *ut;
	char **res;


	ut = malloc(sizeof(t_utils));
	printf("4 ut = %p\n", ut);
	ut = init_ut(ut, str);
	while (str && str[ut->i] != '\0')
	{
		if (str[ut->i] == '{')
		{
			ut->tmp = ft_strsub(ut->str, 0, ut->i);
			    printf(RED"4 malloc ut->tmp = %p\n"RESET, ut->tmp);
			ut->j = ut->i + 1;
			if (ut->tmp)
			{
				ut->start = ft_strjoin(ut->tmp2, ut->tmp);
				printf("4 ut->start = %p\n", ut->start);
			}
			printf(GREEN"4 free ut->tmp = %p\n"RESET, ut->tmp);
			printf(GREEN"4 free ut->tmp2 = %p\n"RESET, ut->tmp2);
			ft_strdel(&(ut->tmp));
			ft_strdel(&(ut->tmp2));
			ut->tmp2 = NULL;
			ut->tmp = NULL;
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
//	free(ut->res);
	printf("4 ut->res = %p\n", ut->res);
	printf("4 ut->res = %p\n", res);
	free(ut);
	ft_putstr("hehre");
	return (res);
}

