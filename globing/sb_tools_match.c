#include "globing.h"

int ft_islower(int c)
{
	if (c >= 97 && c <= 122)
		return (1);
	return (0);
}

int ft_isupper(int c)
{
	if (c >= 65 && c <= 90)
		return (1);
	return (0);
}

int ft_iscntrl(int c)
{
	if ((c >= 0x0 && c <= 0x1F) || c == 0x7F)
		return(1);
	return (0);
}

int ft_isgraph(int c)
{
	if (c >= 0x21 && c <= 0x7E)
		return(1);
	return (0);
}

int ft_isprint(int c)
{
	if (c >= 0x20 && c <= 0x7E)
		return(1);
	return (0);

}

int ft_ispunct(int c)
{
	if (c == '[' || c == '!' || c =='"' || c == '#' || c == '$' || c == '%'\
		|| c == '&' || c == '\'' || c == '(' || c == ')' || c == '*' || \
		c == '+' || c == ',' || c == '-' || c == '.' || c == '/' ||\
		c == ':' || c == ';' || c == '<' || c == '=' || c == '>' ||\
		c == '?' || c == '@' || c == '[' || c == '\\' || c == ']' ||\
		c == '^' || c == '_' || c == '`' || c == '{' || c == '|' ||\
		c =='}' || c == '~' || c == ']')
		return (1);
	return (0);
}

int ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\n' || \
		c == '\v' || c == '\f')
		return (1);
	return (0);
}

int ft_isword(int c)
{
	if (!ft_islower(c) || !ft_isupper(c) || !ft_isdigit(c))
		return (1);
	return (0);
}

int ft_isblank(int c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}
int ft_isxdigit(int c)
{

	c = c;
	return (0);
}
