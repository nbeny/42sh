/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 02:11:44 by nbeny             #+#    #+#             */
/*   Updated: 2017/11/19 02:11:55 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "globing.h"

int		main(int ac, char **av, char **env)
{
	char	**str;
	int		i;

	i = 0;
/*
	while (env && env[i] != NULL)
	{
		ft_putendl(env[i]);
		i++;
	}
*/
	str = globing_research(av, env);
	while (1);
	return (0);
}
