/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 20:55:24 by nbeny             #+#    #+#             */
/*   Updated: 2017/05/23 20:55:34 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstswap(t_list *lst1, t_list *lst2)
{
	void	*tmp_content;
	size_t	tmp_content_size;

	tmp_content = lst1->content;
	tmp_content_size = lst1->content_size;
	lst1->content = lst2->content;
	lst1->content_size = lst2->content_size;
	lst2->content = tmp_content;
	lst2->content_size = tmp_content_size;
}
