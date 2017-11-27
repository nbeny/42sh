/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 11:01:12 by nbeny             #+#    #+#             */
/*   Updated: 2017/11/03 12:17:13 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

void			p_initgl(t_pos *pos, t_read_args args)
{
	tcgetattr(args.u, &pos->default_term);
	if (args.e)
		ft_set_term(args.u, 0);
	else
		(args.s) ? ft_set_term(args.u, 2) : ft_set_term(args.u, 1);
	pos->keys = NULL;
	pos->width = 0;
	pos->h = 0;
	pos->uh = 0;
	pos->exp = 0;
	pos->imax = 0;
	pos->rhs = NULL;
	pos->crstr = NULL;
	pos->t = 0;
	pos->tfd = 1;
	win_size_ch(pos, 0);
	pos->ps = NULL;
	pos->str = NULL;
	pos->s = 0;
	pos->ss = 0;
	pos->se = 0;
	ft_putstr_fd(tgetstr("am", NULL), pos->tfd);
	pos->i = 0;
}

static int		ft_insertkey(char *k, t_pos *pos, int e)
{
	char	*tmp;

	if ((e && printable(k)) || (e == 0 && k[0] != 127))
	{
		if (e)
		{
			ft_putstr(tgetstr("im", NULL));
			ft_putstr(k);
			ft_putstr(tgetstr("ei", NULL));
		}
		tmp = (pos->str) ? ft_strjoin_at(pos->str, k, pos->i) : ft_strdup(k);
		pos->i += ft_strlen(k);
		pos->imax += ft_strlen(k);
		ft_strdel(&pos->str);
		pos->str = tmp;
		if (pos->i != pos->imax)
			return (2);
		return (1);
	}
	return (1);
}

static int		ft_pka(int e, int size, char *key, t_pos *pos)
{
	if (ft_insertkey(key, pos, e) == 2)
		return (2);
	if (size == 1 && key[0] == 127)
	{
		if (e == 0)
			print_delete();
		return (ft_key_bs(pos, &pos->i, &pos->str, 1));
	}
	if (e == 0)
		return (0);
	if (size == 1 && key[0] == 4 && pos->str && pos->str[0])
		return (ft_key_bs(pos, &pos->i, &pos->str, 0));
	if (size == 3 && key[0] == 27 && key[1] == 91 && key[2] == 67)
		return (ft_key_right(&pos->i, pos));
	if (size == 3 && key[0] == 27 && key[1] == 91 && key[2] == 68)
		return (ft_key_left(&pos->i, *pos));
	if (size == 4 && key[0] == 27 && key[1] == 91 && key[2] == 51 \
			&& key[3] == 126)
		return (ft_key_bs(pos, &pos->i, &pos->str, 0));
	return (0);
}

char			*poor_return_line(t_read_args args)
{
	t_pos	pos;
	char	buffer[1024];

	p_initgl(&pos, args);
	while (1)
	{
		if (pos.keys == NULL)
		{
			ft_memset(buffer, '\0', sizeof(buffer));
			pos.s = read(0, buffer, sizeof(buffer));
			pos.keys = ft_strndup(buffer, pos.s);
		}
		if (!win_size_ch(&pos, 0))
		{
			if (!ft_shall_leave(pos.keys, pos.str, args, 0) && \
					ft_pka(args.e, ft_strlen(pos.keys), pos.keys, &pos) == 2)
				ft_clear_line(pos.i, pos, pos.str, 2);
		}
		if (ft_shall_leave(pos.keys, pos.str, args, 1))
			break ;
		else
			ft_strdel(&pos.keys);
	}
	ft_strdel(&pos.keys);
	return (pos.str);
}
