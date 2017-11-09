#include "globing.h"
#include <sys/types.h>
#include <sys/dir.h>

t_new	*check_walcards(t_new *new)
{
	t_new			*s;
	t_new			*izi;
	t_new			*s_izi;
//	t_new			*weed;
	char			*path;
	struct dirent	*d;
	DIR				*dir;
	int note =  0;
	path = NULL;
	izi = NULL;
	ft_putendl("chECK_WAlcard !1!@!@!@!@");
	s = new;
	izi = add_new(izi);
	s_izi = izi;
	if (s == NULL)
		ft_putstr("BOUUUUHHHHH");
	while (s != NULL)
	{
		path = getcwd(NULL, 1024);
		dir = opendir(path);
		note = 0;
/*		if (s->acc == 1)
		{
					ft_putendl("\nnmatch found ACC = 1");
					ft_putstr(s->str);
					s_izi = add_new(s_izi);
					s_izi = s_izi->next;
					s_izi->str = s->str;
		}
*/
//		else
		{
			ft_putendl("ELSE acc = 0");
		while ((d = readdir(dir)) != NULL)
		{

			if (d->d_name[0] != '.')
			{
				path = s->str;
				ft_putendl(d->d_name);
				ft_putendl(path);
				
				ft_putendl("KKKKKKKKKKKKKKKKKK");
				if (nmatch(d->d_name, path, new->sb) != 0)
				{
					note = 1;
//					get_char42(d->d_name);
					ft_putendl("\nnmatch found");
					s_izi = add_new(s_izi);
					s_izi = s_izi->next;
					s_izi->str = ft_strdup(d->d_name);				
				}
				else
					ft_putendl("no natch found");
			}
		}
/*		if (note == 0 && s->acc == 1)
		{
		ft_putendl("\n\n**\t**  nomatchfound but acc");
		s_izi = add_new(s_izi);
		s_izi = s_izi->next;
		s_izi->str = s->str;
		}*/
		}
		closedir(dir);
		s = s->next;
	}
	// MAYBE WRONG
//	if (izi->str == NULL)
//		free(izi);
	ft_putendl("return chECK_WAlcard");
	s_izi = izi;
	s_izi = s_izi->next;
	if (izi->str == NULL)
		ft_putendl("ASDASDAS");
	while (s_izi != NULL)
	{
		ft_putendl(s_izi->str);
		s_izi = s_izi->next;
	}
//	globing_free_new(new);
	return (izi);
}
