/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_salloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:45:58 by nbeny             #+#    #+#             */
/*   Updated: 2017/11/24 13:49:36 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_salloc(size_t size)
{
	void	*ret;

	if (!(ret = malloc(size)))
		exit(1);
	return (ret);
}

void	*ft_scalloc(size_t size)
{
	void	*ret;

	if (!(ret = malloc(size)))
		exit(1);
	ft_bzero(ret, size);
	return (ret);
}
