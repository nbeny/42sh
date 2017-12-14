/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 12:46:00 by nbeny             #+#    #+#             */
/*   Updated: 2017/11/14 16:39:34 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "shell.h"

void	ft_exit(char *str, int *out)
{
	g_out = 1;
	if (str && out)
		*out = ft_atoi(str);
}