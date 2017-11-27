/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 17:23:20 by nbeny             #+#    #+#             */
/*   Updated: 2017/04/17 15:36:12 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char	*sptr;
	char	*dptr;

	dptr = dest;
	sptr = (char *)src;
	while ((*dptr++ = *sptr++))
	{
	}
	return (dest);
}
