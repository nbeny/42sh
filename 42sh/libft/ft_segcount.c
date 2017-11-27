/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_segcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 17:38:14 by nbeny             #+#    #+#             */
/*   Updated: 2017/04/18 13:01:14 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_segcount(char const *s, char c)
{
	int		reading;
	int		segcount;

	if (!s)
		return (0);
	reading = 0;
	segcount = 0;
	while (*s)
	{
		if (!reading && *s != c)
		{
			reading = 1;
			segcount++;
		}
		else if (*s == c)
			reading = 0;
		s++;
	}
	return (segcount);
}
