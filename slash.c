#include "globing/libft/include/libft.h"


typedef struct s_s
{
	char *str;
	struct s_s *next;
}	t_s;

t_s *init()
{
	t_s *s = NULL;
	s = malloc(sizeof(t_s));
	s->str = NULL;
	s->next = NULL;
	return s;
}

t_s *add(t_s *s, char *str)
{
	t_s *save;
	save = s;
	
	if (s == NULL)
	{
		s = init();
		s->str = ft_strdup(str);
		return s;
	}
	else
	{
		while (s->next != NULL)
			s = s->next;
		s->next= init();
		s->next->str = ft_strdup(str);
	}
	return save;
}


int main(int ac, char **av)
{
	char **split = NULL;
	char *path;
	t_s *s;
	
	s = NULL;
	path = NULL;
	if (av[1][0] == '/')
		path = getcwd(NULL, 1024);
	
	split = ft_strsplit(av[1],'/');

	
	ft_putstr("1");
	int k= 0;
	while (split[k] != NULL)
	{
		s = add(s, split[k++]);
		modify 
		
	}
	k = 0;
	while (split[k] != NULL)
	{
		
	}
	ft_putendl("\t2");
	while (s)
	{
		if (s->str != NULL)
			ft_putendl(s->str);
		s =s->next;
	}
	ft_putendl("\t3");
		int j= 0;
	while (split[j] != NULL)
		ft_putendl(split[j++]);
	return 0;
}
