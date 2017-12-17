/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_recupchartab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 02:11:00 by nbeny             #+#    #+#             */
/*   Updated: 2017/11/19 02:11:06 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "globing.h"

int		check_char42(char *s)
{
	int		i;

	i = 0;
	if (s != NULL)
		while (s[i] != '\0')
		{
			if (s[i] == -42)
				return (1);
			i++;
		}
	return (0);
}

void	reverse_char42(char *s)
{
	int		i;

	i = 0;
	if (s != NULL)
		while (s[i] != '\0')
		{
			if (s[i] == 42)
				s[i] = -42;
			i++;
		}
}

void	get_char42(char *s)
{
	int		i;

	i = 0;
	if (s != NULL)
		while (s[i] != '\0')
		{
			if (s[i] == -42)
				s[i] = 42;
			i++;
		}
}
static int	ft_listsize(t_envent *e)
{
	t_envent	*s;
	int			i;

	i = 0;
	s = e;
	if (e != NULL)
	{
		while (s != NULL)
		{
			i++;
			s = s->next;
		}
	}
	return (i);
}

char		**env_to_tab_envglob(t_envent *e)
{
	char		**tstr;
	char		*stock;
	t_envent	*s;
	int			i;

	s = e;
	if (e == NULL)
		return (NULL);
	i = ft_listsize(e);
	if (!(tstr = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	i = 0;
	while (s != NULL)
	{
		stock = ft_strjoin(s->name, "=");
		tstr[i] = ft_strjoin(stock, s->value);
		ft_strdel(&stock);
		i++;
		s = s->next;
	}
	tstr[i] = NULL;
	return (tstr);
}
