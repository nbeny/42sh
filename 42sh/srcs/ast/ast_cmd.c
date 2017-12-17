/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 13:12:35 by nbeny             #+#    #+#             */
/*   Updated: 2017/11/17 15:39:41 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include <fcntl.h>
#include "globing.h"
static char	**get_avs(t_list *av)
{
	t_list	*tmp;
	char	**ret;
	int		len;

	len = 1;
	tmp = av;
	while (tmp && ++len)
		tmp = tmp->next;
	if (!(ret = malloc(sizeof(char *) * len)))
		return (NULL);
	ret[--len] = NULL;
	len = 0;
	tmp = av;
	while (tmp)
	{
		ret[len++] = ft_strdup((char *)tmp->content);
		tmp = tmp->next;
	}
	return (ret);
}

static void	ast_freecmdavs(char **lst)
{
	char **fptr;

	fptr = lst;
	while (*fptr)
	{
		free(*fptr);
		fptr++;
	}
	if (lst)
		free(lst);
}
#include <stdio.h>
static int    ft_listsize(t_envent *e)
{
    t_envent    *s;
    int            i;

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

static char        **env_to_tab_envglob(t_envent *e)
{
    char        **tstr;
    char        *stock;
    t_envent    *s;
    int            i;

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
t_cmd		*ast_newcmd(t_list *av, t_ast *redir, t_envent *t)
{
	t_cmd	*new;

	if (!(new = malloc(sizeof(t_cmd))))
		return (NULL);
	new->av = get_avs(av);
	ast_lstfree(av);
	ft_print_tab(new->av);
	new->av = globing_research(new->av, env_to_tab_envglob(t));
	ft_print_tab(new->av);
	new->next = NULL;
	new->sin = 0;
	new->sout = 0;
	new->pid = 0;
	new->flags = 0;
	new->redir = redir;
	return (new);
}

void		ast_freecmd(t_cmd *cmd)
{
	t_cmd	*fptr;
	t_ast	*fast;

	while (cmd)
	{
		fptr = cmd;
		cmd = cmd->next;
		ast_freecmdavs(fptr->av);
		fast = fptr->redir;
		ast_freeast(&fast);
		free(fptr);
	}
}
