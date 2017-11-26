/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_research.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 02:11:11 by nbeny             #+#    #+#             */
/*   Updated: 2017/11/19 02:11:13 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "globing.h"

t_glob	*remake_arg(t_glob *g, char *line)
{
	t_arg	*s;
	char	*tmp1;
	char	*tmp2;

	tmp1 = NULL;
	tmp2 = NULL;
	s = g->arg;
	if (s != NULL)
	{
		while (s->next != NULL)
			s = s->next;
		tmp1 = ft_strdup(s->str);
		tmp2 = ft_strsub(line, g->p[0], g->p[1]);
		ft_strdel(&(s->str));
		s->str = ft_strjoin(tmp1, tmp2);
		ft_strdel(&tmp1);
		ft_strdel(&tmp2);
	}
	else
		g = add_arg(g, line, 0);
	return (g);
}

t_glob	*zoom_research(t_glob *g, char *line)
{
	t_glob	*s;
	int		i;

	i = 0;
	s = g;
	if (line == NULL)
		return (NULL);
	while (line[i])
	{
		if (line[i] == '/')
			s = slash_gestion(s, line, &i);
		if (line[i] == '[')
			s = square_bracket(s, line, &i);
		else if (line[i] == '{')
			s = accolade(s, line, &i);
		else if (line[i] == '?')
			s = interogation(s, line, &i);
		else
			s = part_arg(s, line, &i);
	}
	g = do_we_match(g);
	return (g);
}

int		check_isglob(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '*' || line[i] == '?' ||\
			line[i] == '[' || line[i] == '{')
			return (1);
		i++;
	}
	return (0);
}

char	**globing_research(char **cmd)
{
	int			j;
	t_new		*res;
	char		**end;
	t_glob		*g;
	t_glob		*s;
	char **split;
	int i;

	split = NULL;
	i = 0;
	j = 1;
	g = NULL;
	res = NULL;
	while (cmd && cmd[j])
	{
		g = init_glob();
		if (check_isglob(cmd[j]))
		{
			if (check_is_acc(cmd[j]))
			{
				split = ft_split_acc(cmd[j], 1);
								ft_print_tab(split);
				while(check_res(split))
					split = ft_split_acc_tab(split);
				ft_putendl("printable");
				ft_print_tab(split);
				i = 0;	
					while (split[i])
					{
						if (check_isglob(split[i]))
						{
							g = zoom_research(g, split[i++]);
							s = g;
							while (s->slash)
								s = s->slash;
							if (res)
								res = join_list(res, s->resforever);
							else
								res = add_path(res, split[i]);
							free_glob_slash(g);
							i++;
						}
						else
							res = add_path(res, split[i]);
					}
			}
			else
			{
				g = zoom_research(g, cmd[j]);
				s = g;
				while (s->slash)
					s = s->slash;
				if (res)
					res = join_list(res, s->resforever);
				else
					res = add_path(res, cmd[j]);
				
				free_glob_slash(g);
			}
		}
		else
			res = add_path(res, cmd[j]);
		j++;
	}
	end = list_to_tab_new(res);
	free_resforever(res);
	j = 0;
	while (end && end[j])
	{
		ft_putendl(end[j]);
		j++;
	}
	i = 0;
	if (split)
	{
	while (*split)
	{
		ft_strdel(&split[i++]);
	}
	free(split);
	}
//	while(1);
	return (end);
}
