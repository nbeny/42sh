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
