#include "globing.h"
#include <sys/types.h>
#include <sys/dir.h>

char	*tri_join(int zero, char *path, char *str)
{
	char	*join;
	char	*tmp;


	tmp = ft_strjoin(path, "/");
	join = ft_strjoin(tmp, str);
	ft_strdel(&tmp);
	return (join);
}

t_new	*match_rep(t_glob *g, char *path)
{
	t_new				*new_path;
	t_new				*s;
	struct dirent		*d;
	DIR					*dir;
	char				*str;
	int					neg;

	str = NULL;
	s = g->new;
	new_path = NULL;
	neg = 0;
	while (s != NULL)
	{
		dir = opendir(path);
		ft_putstr(path);
		while ((d = readdir(dir)) != NULL)
		{
			str = tri_join(g->slashzero, path, d->d_name);
			if (nmatch(d->d_name, s->str, g->sb) != 0)
			{
				if (!access(str, R_OK) && d->d_type == 4 && d->d_name[0] != '.')
				{
					ft_strdel(&str);
					str = tri_join(g->slashzero, path, d->d_name);
					new_path = add_path(new_path, str);
				}
			}
			ft_strdel(&str);
		}
		closedir(dir);
		s = s->next;
	}
	return (new_path);
}

char	*found_path(int zero, char *path, char *dname)
{
	char		*new_path;
	char		*found;
	char		*tmp;
	int			len[2];

	new_path = NULL;
	if (zero == 0)
	{
		tmp = getcwd(NULL, 1024);
		len[0] = ft_strlen(tmp);
		len[1] = ft_strlen(path);
		ft_strdel(&tmp);
		if (len[0] <= len[1] && path[len[0]] != '\0' && path[len[0] + 1] != '\0')
		{
			tmp = ft_strsub(path, (len[0] + 1), len[1]);
			found = ft_strjoin(tmp, "/");
			ft_strdel(&tmp);
			new_path = ft_strjoin(found, dname);
			ft_strdel(&dname);
			ft_strdel(&found);
		}
		else
		{
			new_path = ft_strdup(dname);
			ft_strdel(&dname);
		}
	}
	else
	{
		tmp = ft_strjoin(path, "/");
		new_path = ft_strjoin(tmp, dname);
		ft_strdel(&tmp);
		ft_strdel(&dname);
	}
	return (new_path);
}

t_glob	*match_file(t_glob *g, t_new *st_path)
{
	t_new				*s;
	struct dirent		*d;
	DIR					*dir;
	char				*tmp;

	tmp = NULL;
	s = g->new;
	while (s != NULL)
	{
		dir = opendir(st_path->str);
		while ((d = readdir(dir)) != NULL)
		{
			if (nmatch(d->d_name, s->str, g->sb) != 0)
			{
				if (d->d_name[0] != '.')
				{
					s->i = 1;
					tmp = found_path(g->slashzero, st_path->str, ft_strdup(d->d_name));
					g->resforever = add_path(g->resforever, tmp);
					ft_strdel(&tmp);
				}
			}
		}
	}
		closedir(dir);
		s = s->next;
	}
	return (g);
}
