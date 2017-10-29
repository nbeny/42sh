#include "globing.h"

t_new	*class_digit_posix(t_new *s, char *class, t_new *s_izi)
{
	s_izi = sb_ascii_posjoin(s, '0', '9', s_izi);
	return (s_izi);
}

t_new	*class_graph_posix(t_new *s, char *class, t_new *s_izi)
{
	s_izi = sb_ascii_posjoin(s, 21, 126, s_izi);
	return(s_izi);
}

t_new	*class_lower_posix(t_new *s, char *class, t_new *s_izi)
{
	s_izi = sb_ascii_posjoin(s, 'a', 'z', s_izi);
	return (s_izi);
}

t_new	*class_print_posix(t_new *s, char *class, t_new *s_izi)
{
	s_izi = sb_ascii_posjoin(s, 32, 126, s_izi);
	return (s_izi);
}

t_new	*class_punct_posix(t_new *s, char *class, t_new *s_izi)
{
	s_izi = sb_ascii_posjoin(s, 33, 47, s_izi);
	s_izi = sb_ascii_posjoin(s, 58, 64, s_izi);
	s_izi = sb_ascii_posjoin(s, 91, 96, s_izi);
	s_izi = sb_ascii_posjoin(s, 123, 126, s_izi);
	return (s_izi);
}
