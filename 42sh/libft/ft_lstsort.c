/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 20:55:49 by nbeny             #+#    #+#             */
/*   Updated: 2017/05/23 20:55:55 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsort(t_list *lst, int (*f)(t_list *, t_list *))
{
	int		sorted;
	t_list	*cur;

	sorted = 0;
	while (sorted == 0)
	{
		cur = lst;
		sorted = 1;
		while (cur)
		{
			if (f(cur, cur->next) == 1)
			{
				ft_lstswap(cur, cur->next);
				sorted = 0;
			}
			cur = cur->next;
		}
	}
}
