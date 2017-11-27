/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wbytelen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:30:42 by nbeny             #+#    #+#             */
/*   Updated: 2017/11/14 16:30:42 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wbytelen(wchar_t *ws)
{
	size_t		len;
	size_t		bytelen;

	len = ft_wstrlen(ws);
	bytelen = 0;
	while (len > 0)
	{
		bytelen += ft_wcharlen(*ws);
		ws++;
		len--;
	}
	return (bytelen);
}
