/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   htable.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgascoin <tgascoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 13:47:00 by tgascoin          #+#    #+#             */
/*   Updated: 2017/11/01 13:47:41 by tgascoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HTABLE_H
# define HTABLE_H

# include "libft.h"
# include <sys/types.h>
# include <dirent.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>

# define PATH_MAX 4096

typedef struct		s_htent
{
	unsigned long	hash;
	char			*key;
	void			*content;
	struct s_htent	*next;
	struct s_htent	*doub;
}					t_htent;

typedef struct		s_htbucket
{
	t_htent			**tab;
	unsigned int	min;
	unsigned int	max;
	unsigned int	count;
	int				doublon;
	void			**data;
}					t_htbucket;

t_htbucket			*ht_createbucket(t_htent *lst, void **data);
void				ht_insertentry(t_htent **root, char *key, void *content);
int					ht_tmpcount(t_htent *entries);
unsigned int		ht_hash(char *key);
t_htent				*ht_getval(char *key, t_htbucket *bk);

t_htbucket			*ht_loadbinaries(char *path);
char				*ht_getbin(char *name, t_htbucket *bk);

void				ht_free_ent(t_htent *ent);
void				ht_free_bucket(t_htbucket *bk);

#endif
