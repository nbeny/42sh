#include "globing.h"

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
		else if (*i > 0 && str[*i] == '-' && str[*i + 1] != '\0')
			ret = sb_lessmatch(c, str, i);
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

int		sb_classmatch(int c, char *str, int *i)
{
	if (check_name_pos(&str[*i]))
	{
		if (!ft_strncmp(&str[*i], "[:blank:]", 10) && (((*i) += 10) > 0))
			return (ft_isblank(c));
		else if (!ft_strncmp(&str[*i], "[:alnum:]", 10) && (((*i) += 10) > 0))
			return (ft_isalnum(c));
		else if (!ft_strncmp(&str[*i], "[:alpha:]", 10) && (((*i) += 10) > 0))
			return (ft_isalpha(c));
		else if (!ft_strncmp(&str[*i], "[:ascii:]", 10) && (((*i) += 10) > 0))
			return (ft_isascii(c));
		else if (!ft_strncmp(&str[*i], "[:cntrl:]", 10) && (((*i) += 10) > 0))
			return (ft_iscntrl(c));
		else if (!ft_strncmp(&str[*i], "[:digit:]", 10) && (((*i) += 10) > 0))
			return (ft_isdigit(c));
		else if (!ft_strncmp(&str[*i], "[:graph:]", 10) && (((*i) += 10) > 0))
			return (ft_isgraph(c));
		else if (!ft_strncmp(&str[*i], "[:lower:]", 10) && (((*i) += 10) > 0))
			return (ft_islower(c));
		else if (!ft_strncmp(&str[*i], "[:print:]", 10) && (((*i) += 10) > 0))
			return (ft_isprint(c));
		else if (!ft_strncmp(&str[*i], "[:punct:]", 10) && (((*i) += 10) > 0))
			return (ft_ispunct(c));
		else if (!ft_strncmp(&str[*i], "[:space:]", 10) && (((*i) += 10) > 0))
			return (ft_isspace(c));
		else if (!ft_strncmp(&str[*i], "[:upper:]", 10) && (((*i) += 10) > 0))
			return (ft_isupper(c));
		else if (!ft_strncmp(&str[*i], "[:word:]", 9) && (((*i) += 9) > 0))
			return (ft_isword(c));
		else if (!ft_strncmp(&str[*i], "[:xdigit:]", 11) && (((*i) += 11) > 0))
			return (ft_isxdigit(c));
	}
	return (0);
}

int		sb__match(int c, char *str, int *i)
{
	while (str && str[*i] && str[*i] != '-' && str[*i] != '[')
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
