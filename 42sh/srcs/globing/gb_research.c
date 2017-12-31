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
		tmp2 = ft_my_str_sub(line, g->p[0], g->p[1]);
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

char	**globing_research(char *cmd, char **env)
{
	t_zoom z;
	if (cmd[ft_strlen(cmd -1)] == -42)
	    cmd[ft_strlen(cmd) - 1] = '\0';
	init_z(&z, cmd, env);
//	while (z.cmd && z.cmd[z.j])
	{
		z.g = init_glob(z.env);
		if (check_isglob(z.cmd))
			go_to_acc(&z);
		else
			z.res = add_path(z.res, z.cmd);
		if (z.g != NULL)
			free(z.g);
		z.j++;
	}
	z.end = list_to_tab_new(z.res);
	free_resforever(z.res);
	z.j = 0;
	env = NULL;
	ft_print_tab(z.end);
	return (z.end);
}
