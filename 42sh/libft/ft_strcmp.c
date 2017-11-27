/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 17:22:51 by nbeny             #+#    #+#             */
/*   Updated: 2017/04/18 18:23:19 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *a, const char *b)
{
	char	*ptra;
	char	*ptrb;

	ptra = (char *)a;
	ptrb = (char *)b;
	if (!ptra && !ptrb)
		return (0);
	while (*ptra && *ptrb && *ptra == *ptrb)
	{
		ptra++;
		ptrb++;
	}
	return ((unsigned char)*ptra - (unsigned char)*ptrb);
}
