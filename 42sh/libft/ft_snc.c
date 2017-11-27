/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:42:05 by nbeny             #+#    #+#             */
/*   Updated: 2017/11/14 16:42:05 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_snc(char *str, char c, int size)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (str != NULL)
	{
		while (str[i] != '\0' && i < size)
		{
			if (str[i] == c)
				count++;
			i++;
		}
	}
	return (count);
}
