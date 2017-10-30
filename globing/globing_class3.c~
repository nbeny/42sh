#include "globing.h"

t_new   *class_alnum_posix_dup(t_new *s_izi)
{
	s_izi = sb_ascii_posdup(s_izi, 'a', 'z');
	s_izi = sb_ascii_posdup(s_izi, 'A', 'Z');
	s_izi = sb_ascii_posdup(s_izi, '0', '9');
	return (s_izi);
}

t_new   *class_alpha_posix_dup(t_new *s_izi)
{
	s_izi = sb_ascii_posjoin(s_izi, 'a', 'z');
	s_izi = sb_ascii_posjoin(s_izi, 'A', 'Z');
	return (s_izi);
}

t_new   *class_blank_posix_dup(t_new *s_izi)
{
	s_izi = sb_ascii_posjoin(s_izi, ' ', ' ');
	s_izi = sb_ascii_posjoin(s_izi, '\t', '\t');
	return (s_izi);
}

t_new   *class_ascii_posix_dup(t_new *s_izi)
{
	s_izi = sb_ascii_posjoin(s_izi, 0, 127);
	return (s_izi);
}

t_new   *class_cntrl_posix_dup(t_new *s_izi)
{
	s_izi = sb_ascii_posjoin(s_izi, 0, 31);
	s_izi = sb_ascii_posjoin(s_izi, 127, 127);
	return (s_izi);
}
