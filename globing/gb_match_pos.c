#include "globing.h"

int		sb_lessmatchno(int c, char *str, int *i)
{
	ft_putstr("\n\tLESS");
	if (str && str[*i])
	{
		if (c > str[*i] && c < str[*i + 2])
		{
			(*i) += 2;
			ft_putendl("1");
			return (1);
		}
		(*i) += 2;
	}
				ft_putendl("0");
	return (0);
}

int		sb_exclammatch(int c, char *str, int *i)
{
	int		ret;

	ft_putstr("LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL");
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
	ft_putstr("LESS");
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
		if (!ft_strncmp(&str[*i], "[:blank:]", 9) && (((*i) += 9) > 0))
			return (ft_isblank(c));
		else if (!ft_strncmp(&str[*i], "[:alnum:]", 9) && (((*i) += 9) > 0))
			return (ft_isalnum(c));
		else if (!ft_strncmp(&str[*i], "[:alpha:]", 9) && (((*i) += 9) > 0))
			return (ft_isalpha(c));
		else if (!ft_strncmp(&str[*i], "[:ascii:]", 9) && (((*i) += 9) > 0))
			return (ft_isascii(c));
		else if (!ft_strncmp(&str[*i], "[:cntrl:]", 9) && (((*i) += 9) > 0))
			return (ft_iscntrl(c));
		else if (!ft_strncmp(&str[*i], "[:digit:]", 9) && (((*i) += 9) > 0))
			return (ft_isdigit(c));
		else if (!ft_strncmp(&str[*i], "[:graph:]", 9) && (((*i) += 9) > 0))
			return (ft_isgraph(c));
		else if (!ft_strncmp(&str[*i], "[:lower:]", 9) && (((*i) += 9) > 0))
			return (ft_islower(c));
		else if (!ft_strncmp(&str[*i], "[:print:]", 9) && (((*i) += 9) > 0))
			return (ft_isprint(c));
		else if (!ft_strncmp(&str[*i], "[:punct:]", 9) && (((*i) += 9) > 0))
			return (ft_ispunct(c));
		else if (!ft_strncmp(&str[*i], "[:space:]", 9) && (((*i) += 9) > 0))
			return (ft_isspace(c));
		else if (!ft_strncmp(&str[*i], "[:upper:]", 9) && (((*i) += 9) > 0))
			return (ft_isupper(c));
		else if (!ft_strncmp(&str[*i], "[:word:]", 8) && (((*i) += 8) > 0))
			return (ft_isword(c));
		else if (!ft_strncmp(&str[*i], "[:xdigit:]", 10) && (((*i) += 10) > 0))
			return (ft_isxdigit(c));
	}
	return (0);
}

int		sb__match(int c, char *str, int *i)
{
	ft_putendl("sb__match()--");
	ft_putstr("int : ");
	ft_putnbr(c);
	ft_putstr(" str :");
	ft_putstr(str);
	ft_putstr("  ");
//	dt_putstr
	ft_putnbr(*i);
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
