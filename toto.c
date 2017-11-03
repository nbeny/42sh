#include "globing/libft/include/libft.h"

int main(int ac, char **av)
{
	char *gg;

	gg = NULL;
	gg = ft_strjoin(av[1],av[2]);
	ft_putstr(gg);
	return (0);
}
