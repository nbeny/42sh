/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 17:27:58 by nbeny             #+#    #+#             */
/*   Updated: 2017/04/13 13:23:47 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*sptr;
	char	*lptr;

	sptr = (char *)s;
	lptr = (*s == c) ? (char *)s : (char *)0;
	while (*sptr != '\0')
	{
		if (*sptr == c)
			lptr = sptr;
		sptr++;
	}
	if (*sptr == c)
		lptr = sptr;
	return (lptr);
}
