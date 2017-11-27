/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:47:26 by nbeny             #+#    #+#             */
/*   Updated: 2017/11/14 16:47:26 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(void *data, size_t len)
{
	void	*dup;

	if (!data || !(dup = malloc(sizeof(len))))
		return (NULL);
	ft_memcpy(dup, data, len);
	return (dup);
}
