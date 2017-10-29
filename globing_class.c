#include "globing.h"

t_new	*class_alnum_posix(t_new *s, t_new *s_izi)
{
	s_izi = sb_ascii_posjoin(s, 'a', 'z', s_izi);
	s_izi = sb_ascii_posjoin(s, 'A', 'Z', s_izi);
	s_izi = sb_ascii_posjoin(s, '0', '9', s_izi);
	return (s_izi);
}

t_new	*class_alpha_posix(t_new *s, t_new *s_izi)
{
	s_izi = sb_ascii_posjoin(s, 'a', 'z', s_izi);
	s_izi = sb_ascii_posjoin(s, 'A', 'Z', s_izi);
	return (s_izi);
}

t_new	*class_blank_posix(t_new *s, t_new *s_izi)
{
	s_izi = sb_ascii_posjoin(s, ' ', ' ', s_izi);
	s_izi = sb_ascii_posjoin(s, '\t', '\t', s_izi);
	return (s_izi);
}

t_new	*class_ascii_posix(t_new *s, t_new *s_izi)
{
	s_izi = sb_ascii_posjoin(s, 0, 127, s_izi);
	return (s_izi);
}

t_new	*class_cntrl_posix(t_new *s, t_new *s_izi)
{
	s_izi = sb_ascii_posjoin(s, 0, 31, s_izi);
	s_izi = sb_ascii_posjoin(s, 127, 127, s_izi);
	return (s_izi);
}
