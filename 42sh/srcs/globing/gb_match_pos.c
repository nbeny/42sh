/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_match_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 02:10:40 by nbeny             #+#    #+#             */
/*   Updated: 2017/11/19 02:10:42 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "globing.h"

int		sb_lessmatchno(int c, t_new *sb)
{
	if (sb->str && sb->str[sb->i])
	{
		if (c > sb->str[sb->i] && c < sb->str[sb->i + 2])
		{
			sb->i += 2;
			return (1);
		}
		sb->i += 2;
	}
	return (0);
}

int		sb_exclammatch(int c, t_new *sb)
{
	int		ret;

	ret = 0;
	sb->i++;
	while (sb->str && sb->str[sb->i])
	{
		if (sb->str[sb->i] == '[' && sb->str[sb->i + 1] != '\0')
		{
			if (check_name_pos(&(sb->str[sb->i])))
				ret = sb_classmatch(c, sb);
			else
				ret = sb__match_no(c, sb);
		}
//		else if (sb->str[sb->i + 1] == '-' && sb->str[sb->i + 2] != '\0')
//			ret = sb_lessmatchno(c, sb);
		else
		{
			ret = sb__match(c, sb);
		}
		if (ret == 1)
			return (0);
		sb->i++;
	}
	return (1);
}

int		sb_lessmatch(int c, t_new *sb)
{
	if (sb->str && sb->str[sb->i])
	{
		if (c >= sb->str[sb->i - 1] && c <= sb->str[(sb->i + 1)])
		{
			sb->i += 2;
			return (1);
		}
		sb->i += 2;
	}
	return (0);
}

int		sb__match(int c, t_new *sb)
{
	while (sb->str && sb->str[sb->i] &&\
		sb->str[sb->i] != ']')
	{
		if (c == sb->str[sb->i])
			return (1);
		sb->i++;
	}
	return (0);
}

int		sb__match_no(int c, t_new *sb)
{
	if (sb->str && sb->str[sb->i])
	{
		if (c == sb->str[sb->i])
			return (1);
		sb->i++;
	}
	return (0);
}
