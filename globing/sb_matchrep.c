#include "globing.h"
#include <sys/types.h>
#include <sys/dir.h>

char	*tri_join(char *path, char *str)
{
	char	*join;
	char	*tmp;

	tmp = ft_strjoin(path, "/");
	ft_strdel(&path);
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
			if (d->d_type == 4 && nmatch(s->str, d->d_name, s) != 0)
			{
				ft_putstr("<<<<<<<<<match_repfound>>>>>>>>>>\n");
				str = tri_join(path, d->d_name);
				new_path = add_path(new_path, str);
				ft_strdel(&str);
			}
		}
		closedir(dir);
		s = s->next;
	}
	ft_putstr("<<<<<<<<<ENDmatch_repEND>>>>>>>>>>\n");
	return (new_path);
}

char	*found_path(char *path, struct dirent *d)
{
	char		*new_path;
	char		*found;
	char		*tmp;
	int			len[2];

	tmp = getcwd(NULL, 1024);
	len[0] = ft_strlen(tmp);
	len[1] = ft_strlen(path);
	ft_strdel(&tmp);
	if (len[0] < len[1] && path[len[0]] != '\0' && path[len[0] + 1] != '\0')
	{
		tmp = ft_strsub(path, (len[0] + 1), len[1]);
		found = ft_strjoin(tmp, "/");
		ft_strdel(&tmp);
		new_path = ft_strjoin(found, d->d_name);
		ft_strdel(&found);
	}
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
	while (s != NULL)
	{
		dir = opendir(path);
		while ((d = readdir(dir)) != NULL)
		{
			if (nmatch(s->str, d->d_name, g->new->sb) != 0)
			{
				ft_putstr("FOUND<match_file>FOUND\n");
				tmp = found_path(path, d);
				ft_putstr("DONEtmpDONE\n");
				izi = add_path(izi, tmp);
				ft_strdel(&tmp);
			}
		}
		closedir(dir);
		s = s->next;
	}
	ft_putstr("?<RETmatch_fileRET>?\n");
	return (izi);
}
