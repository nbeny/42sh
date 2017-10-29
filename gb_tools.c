#include "globing.h"
#include <libft.h>

t_new	*get_no_ascii(t_new *s, char *str, int *i, t_new *s_izi)
{
	if (str[i + 1] == '-')
	{
		if (str[i + 1] == '-' && str[i + 2] != '\0')
		{
			s_izi = sb_not_ascii_posjoin(s, (int)str[i], (int)str[i + 2], s_izi);
			i += 3;
		}
		else
		{
			s_izi = sb_not_ascii_posjoin(s, (int)str[i], ((int)str[i] + 1), s_izi);
			i++;
		}
	}
	else
	{
		s_izi = sb_not_ascii_posjoin(s, (int)str[i], ((int)str[i] + 1), s_izi);
		i++;
	}
	return (s_izi);
}

t_new	*get_ascii(t_new *s, char *str, int *i, s_izi *izi)
{
	if (str[i + 1] == '-')
	{
		if (str[i + 1] == '-' && str[i + 2] != '\0')
		{
			s_izi = sb_ascii_posjoin(s, (int)str[i], (int)str[i + 2], s_izi);
			i += 3;
		}
		else
		{
			s_izi = sb_ascii_posjoin(s, (int)str[i], ((int)str[i] + 1), s_izi);
			i++;
		}
	}
	else
	{
		s_izi = sb_ascii_posjoin(s, (int)str[i], ((int)str[i] + 1), s_izi);
		i++;
	}
	return (s_izi);
}

t_new	*check_class(t_new *s, char *class, t_new *s_izi)
{
	if (!ft_strncmp(class, "alnum\0", 6))
		s_izi = class_alnum_posix(s, s_izi);
	else if (!ft_strncmp(class, "alpha\0", 6))
		s_izi = class_alpha_posix(s, s_izi);
	else if (!ft_strncmp(class, "ascii\0", 6))
		s_izi = class_ascii_posix(s, s_izi);
	else if (!ft_strncmp(class, "blank\0", 6))
		s_izi = class_blank_posix(s, s_izi);
	else if (!ft_strncmp(class, "cntrl\0", 6))
		s_izi = class_cntrl_posix(s, s_izi);
	else if (!ft_strncmp(class, "digit\0", 6))
		s_izi = class_digit_posix(s, s_izi);
	else if (!ft_strncmp(class, "graph\0", 6))
		s_izi = class_graph_posix(s, s_izi);
	else if (!ft_strncmp(class, "lower\0", 6))
		s_izi = class_lower_posix(s, s_izi);
	else if (!ft_strncmp(class, "print\0", 6))
		s_izi = class_print_posix(s, s_izi);
	else if (!ft_strncmp(class, "punct\0", 6))
		s_izi = class_punct_posix(s, s_izi);
	else if (!ft_strncmp(class, "space\0", 6))
		s_izi = class_space_posix(s, s_izi);
	else if (!ft_strncmp(class, "upper\0", 6))
		s_izi = class_upper_posix(s, s_izi);
	else if (!ft_strncmp(class, "word\0", 5))
		s_izi = class_word_posix(s, s_izi);
	else if (!ft_strncmp(class, "xdigit\0", 7))
		s_izi = class_xdigit_posix(s, s_izi);
	else
		ft_printf(2, "shell: no class posix found: [:%s:]\n", class);
	return (s_izi);
}

t_new	*get_class_posix(s, str, *i, s_izi)
{
	int		p[2];
	char	*class;

	if (str[*i] == ':')
	{
		i++;
		p[0] = i;
		while (str[*i] != '\0' && str[*i] != ':' && str[*i] != ']')
			i++;
		p[1] = i;
		if (str[*i] == '\0' || str[*i] == ']')
			ft_printf(2, "shell: no matches found: %s[%s]\n", s->str, str);
		else
		{
			class = ft_strsub(str, p[0], p[1]);
			s_izi = check_class(s, class, s_izi);
			ft_strdel(&class);
		}
	}
	else
		ft_printf(2, "shell: no matches found: %s[%s]\n", s->str, str);
	return (s_izi);
}
