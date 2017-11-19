/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_checkposix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 03:44:53 by nbeny             #+#    #+#             */
/*   Updated: 2017/11/19 03:44:55 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "globing.h"

int		check_name_pos(char *str)
{
	if (ft_strncmp(str, "[:blank:]", 9) == 0 ||\
		ft_strncmp(str, "[:alnum:]", 9) == 0 ||\
		ft_strncmp(str, "[:alpha:]", 9) == 0 ||\
		ft_strncmp(str, "[:ascii:]", 9) == 0 ||\
		ft_strncmp(str, "[:cntrl:]", 9) == 0 ||\
		ft_strncmp(str, "[:digit:]", 9) == 0 ||\
		ft_strncmp(str, "[:graph:]", 9) == 0 ||\
		ft_strncmp(str, "[:lower:]", 9) == 0 ||\
		ft_strncmp(str, "[:print:]", 9) == 0 ||\
		ft_strncmp(str, "[:punct:]", 9) == 0 ||\
		ft_strncmp(str, "[:space:]", 9) == 0 ||\
		ft_strncmp(str, "[:upper:]", 9) == 0 ||\
		ft_strncmp(str, "[:word:]", 8) == 0 ||\
		ft_strncmp(str, "[:xdigit:]", 10) == 0)
		return (1);
	return (0);
}

int		check_is_posix(char *str, int *i)
{
	int			j[2];
	int			save;
	char		*class;

	class = NULL;
	save = *i;
	j[0] = *i;
	while (str[*i] && str[*i] != ']')
	{
		(*i)++;
	}
	j[1] = ++(*i);
	class = ft_strsub(str, j[0], j[1]);
	if (check_name_pos(class) == 1)
	{
		ft_strdel(&class);
		return (*i);
	}
	ft_strdel(&class);
	return (++save);
}
