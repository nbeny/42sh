#include "globing.h"
#include <sys/types.h>
#include <sys/dir.h>

char	*tri_join(int zero, char *path, char *str)
{
	char	*join;
	char	*tmp;


	if (zero == 0)
		tmp = ft_strjoin(path, "/");
	else
		tmp = ft_strdup(path);
//	ft_strdel(&path);
	path = ft_strjoin(tmp, str);
	ft_strdel(&tmp);
	return (path);
}

t_new	*match_rep(t_glob *g, char *path)
{
	t_new				*new_path;
	t_new				*s;
	struct dirent		*d;
	DIR					*dir;
	char				*str;

	ft_putstr("<<<<<<<<<match_rep>>>>>>>>>>\n");
	s = g->new;
	new_path = NULL;
	while (s != NULL)
	{
		dir = opendir(path);
		while ((d = readdir(dir)) != NULL)
		{
			if (d->d_type == 4 && !ft_strncmp(d->d_name, ".\0", 2) &&\
				!ft_strncmp(d->d_name, "..\0", 3) && nmatch(d->d_name, s->str, s->sb) != 0)
			{
				ft_putstr("<<<<<<<<<match_repfound>>>>>>>>>>\n");
				str = tri_join(g->slashzero, path, d->d_name);
				new_path = add_path(new_path, str);
				ft_strdel(&str);
			}
		}
		closedir(dir);
		s = s->next;
	}
	ft_putendl(path);
//	ft_putendl(new_path->str);
	ft_putstr("\n\n<<<<<<<<<ENDmatch_repEND>>>>>>>>>>\n");

	return (new_path);
}

char	*found_path(int zero, char *path, char *dname)
{
	char		*new_path;
	char		*found;
	char		*tmp;
	int			len[2];
	ft_putendl("ENTER PATH FOUND ");
	if (zero == 0)
	{
		ft_putendl("IIIFFFF   IF IF PATH FOUND ");
		tmp = getcwd(NULL, 1024);
		len[0] = ft_strlen(tmp);
		len[1] = ft_strlen(path);
		ft_strdel(&tmp);
		if (len[0] < len[1] && path[len[0]] != '\0' && path[len[0] + 1] != '\0')
		{
			tmp = ft_strsub(path, (len[0] + 1), len[1]);
			found = ft_strjoin(tmp, "/");
			ft_strdel(&tmp);
			new_path = ft_strjoin(found, dname);
			ft_strdel(&dname);
			ft_strdel(&found);
		}
	}
	else
	{
		ft_putendl("\n\nHERE IN FOUND PATH WE ARE GOOD VERY GOOD YOLO");
		ft_putendl(path);
		tmp = ft_strdup(path);
		new_path = ft_strjoin(tmp, dname);
		ft_strdel(&tmp);
		ft_strdel(&dname);
	}
	ft_putendl("\nEND PATH FOUND");
	return (new_path);
}

t_new	*match_file(t_glob *g, char *path)
{
	t_new				*izi;
	t_new				*s;
	struct dirent		*d;
	DIR					*dir;
	char				*tmp;

	tmp = NULL;
	izi = NULL;
	s = g->new;
	ft_putstr("?<match_file>?\n");
//	if (!s->str)
	//	ft_putendl("g->arg->str == UNLL");
	//else
	//ft_putstr(s->str);

	if (s == NULL)
		ft_putstr("?<match_file>?  is null sss \n");
	if (path != NULL)
ft_putstr(path);
	else
		ft_putstr("NULL");
	while (s != NULL)
	{
		
		dir = opendir(path);
		ft_putstr(path);
		while ((d = readdir(dir)) != NULL)
		{
			ft_putendl("while d_dir");
			ft_putendl(d->d_name);
			ft_putendl(s->str);
			if (nmatch(d->d_name, s->str, s->sb) != 0)
			{
				ft_putstr("FOUND<match_file>FOUND\n");
				tmp = found_path(g->slashzero, path, ft_strdup(d->d_name));
				
				ft_putstr("DONEtmpDONE\n");
				ft_putstr(tmp);
				izi = add_path(izi, tmp);
//				s = izi
//				ft_strdel(&tmp);
				ft_putstr("endif");
			}
			else
				ft_putendl("not__fpund");
		}
		ft_putstr("coucou");
		closedir(dir);
		s = s->next;
	}
/*	while (izi)
	{
		ft_putendl(izi->str);
		izi = izi->next;
		}*/
	ft_putstr("?<RETmatch_fileRET>?\n");
	return (izi);
}