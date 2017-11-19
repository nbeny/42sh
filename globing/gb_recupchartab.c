/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_recupchartab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 02:11:00 by nbeny             #+#    #+#             */
/*   Updated: 2017/11/19 02:11:06 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "globing.h"

int		check_char42(char *s)
{
	int		i;

	i = 0;
	if (s != NULL)
		while (s[i] != '\0')
		{
			if (s[i] == -42)
				return (1);
			i++;
		}
	return (0);
}

void	reverse_char42(char *s)
{
	int		i;

	i = 0;
	if (s != NULL)
		while (s[i] != '\0')
		{
			if (s[i] == 42)
				s[i] = -42;
			i++;
		}
}

void	get_char42(char *s)
{
	int		i;

	i = 0;
	if (s != NULL)
		while (s[i] != '\0')
		{
			if (s[i] == -42)
				s[i] = 42;
			i++;
		}
}
