/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_accolade1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 02:09:37 by nbeny             #+#    #+#             */
/*   Updated: 2017/11/19 02:10:09 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "globing.h"

t_new	*make_comma(t_new *new, char *str)
{
	char	**split;
	t_new	*s;
	t_new	*izi;
	int		i;

	izi = NULL;
	s = new;
	if (!(split = ft_strsplit(str, ',')))
		return (new);
	if (s != NULL)
	{
		while (s != NULL)
		{
			i = 0;
			while (split && split[i])
				izi = add_joinaccolade(izi, s->str, split[i++]);
			s = s->next;
		}
		free_new(new);
	}
	else
		izi = make_commadup(split);
	free_split(split);
	return (izi);
}

int		check_rebuild_path(char *str)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == -42)
			return (1);
		i++;
	}
	return (0);
}

char	*rebuild_path(t_new *sb, char *str)
{
	char		*tmp1;
	char		*tmp2;
	char		*new;
	t_new		*s;
	int			i;
	int			p[2];

	i = 0;
	s = sb;
	new = NULL;
	while (str && str[i] && sb)
	{
		if (str[i] == -42)
		{
			i++;
			tmp1 = ft_strjoin(new, "[");
			tmp2 = ft_strjoin(tmp1, s->str);
			new = ft_strjoin(tmp2, "]");
			ft_strdel(&tmp1);
			ft_strdel(&tmp2);
			s = s->next;
		}
		else
		{
			p[0] = i;
			while (str && str[i])
				i++;
			p[1] = i;
			tmp1 = ft_strsub(str, p[0], p[1]);
			tmp2 = ft_strjoin(new, tmp1);
			new = ft_strdup(tmp2);
			ft_strdel(&tmp1);
			ft_strdel(&tmp2);
		}
	}
	return (new);
}
