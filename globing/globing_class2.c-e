#include "globing.h"

t_new	*class_space_posix(t_new *s, t_new *s_izi)
{
	s_izi = sb_ascii_posjoin(s, ' ', ' ', s_izi);
	s_izi = sb_ascii_posjoin(s, '\t', '\t', s_izi);
	s_izi = sb_ascii_posjoin(s, '\r', '\r', s_izi);
	s_izi = sb_ascii_posjoin(s, '\n', '\n', s_izi);
	s_izi = sb_ascii_posjoin(s, '\v', '\v', s_izi);
	s_izi = sb_ascii_posjoin(s, '\f', '\f', s_izi);
	return (s_izi);
}

t_new	*class_upper_posix(t_new *s, t_new *s_izi)
{
	s_izi = sb_ascii_posjoin(s, 'A', 'Z', s_izi);
	return (s_izi);
}

t_new	*class_word_posix(t_new *s, t_new *s_izi)
{
	s_izi = sb_ascii_posjoin(s, '_', '_', s_izi);
	s_izi = sb_ascii_posjoin(s, 'a', 'z', s_izi);
	s_izi = sb_ascii_posjoin(s, 'A', 'Z', s_izi);
	s_izi = sb_ascii_posjoin(s, '0', '9', s_izi);
	return (s_izi);
}

t_new	*class_xdigit_posix(t_new *s, t_new *s_izi)
{
	s_izi = sb_ascii_posjoin(s, 'A', 'F', s_izi);
	s_izi = sb_ascii_posjoin(s, 'a', 'f', s_izi);
	s_izi = sb_ascii_posjoin(s, '0', '9', s_izi);
	return (s_izi);
}
