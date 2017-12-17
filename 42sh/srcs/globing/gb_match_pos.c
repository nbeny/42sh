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

int		sb_lessmatchno(int c, char *str, int *i)
{
	if (str && str[*i])
	{
		if (c > str[*i] && c < str[*i + 2])
		{
			(*i) += 2;
			return (1);
		}
		(*i) += 2;
	}
	return (0);
}

int		sb_exclammatch(int c, char *str, int *i)
{
	int		ret;

	ret = 0;
	(*i)++;
	while (str && str[*i])
	{
		if (str[*i] == '[' && str[*i + 1] != '\0')
		{
			if (check_name_pos(&str[*i]))
				ret = sb_classmatch(c, str, i);
			else
				ret = sb__match_no(c, str, i);
		}
		else if (str[*i + 1] == '-' && str[*i + 2] != '\0')
			ret = sb_lessmatchno(c, str, i);
		else
		{
			ret = sb__match(c, str, i);
		}
		if (ret == 1)
			return (0);
		(*i)++;
	}
	return (1);
}

int		sb_lessmatch(int c, char *str, int *i)
{
	if (str && str[*i])
	{
		if (c >= str[*i - 1] && c <= str[*i + 1])
		{
			(*i) += 2;
			return (1);
		}
		(*i) += 2;
	}
	return (0);
}

int		sb__match(int c, char *str, int *i)
{
	while (str && str[*i] && str[*i] != '-' && str[*i] != ']')
	{
		if (c == str[*i])
			return (1);
		(*i)++;
	}
	return (0);
}

int		sb__match_no(int c, char *str, int *i)
{
	if (str && str[*i] && str[*i])
	{
		if (c == str[*i])
			return (1);
		(*i)++;
	}
	return (0);
}
