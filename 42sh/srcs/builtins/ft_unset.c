/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 16:11:00 by nbeny             #+#    #+#             */
/*   Updated: 2017/10/26 10:55:33 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_unset(char **av, t_envent **locals)
{
	int	i;

	if (!av[1])
		return (ft_putendl("usage: unset [ ... NAMES ]"));
	i = 0;
	while (av[++i])
		env_delentriy(av[i], locals);
}
