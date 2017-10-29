#include "globing.h"

t_new   *class_space_posix_dup(t_new *s_izi)
{
    s_izi = sb_ascii_posdup(s_izi, ' ', ' ');
    s_izi = sb_ascii_posdup(s_izi, '\t', '\t');
    s_izi = sb_ascii_posdup(s_izi, '\r', '\r');
    s_izi = sb_ascii_posdup(s_izi, '\n', '\n');
    s_izi = sb_ascii_posdup(s_izi, '\v', '\v');
    s_izi = sb_ascii_posdup(s_izi, '\f', '\f');
    return (s_izi);
}

t_new   *class_upper_posix_dup(t_new *s_izi)
{
    s_izi = sb_ascii_posdup(s_izi, 'A', 'Z');
    return (s_izi);
}

t_new   *class_word_posix_dup(t_new *s_izi)
{
    s_izi = sb_ascii_posdup(s_izi, '_', '_');
    s_izi = sb_ascii_posdup(s_izi, 'a', 'z');
    s_izi = sb_ascii_posdup(s_izi, 'A', 'Z');
    s_izi = sb_ascii_posdup(s_izi, '0', '9');
    return (s_izi);
}

t_new   *class_xdigit_posix_dup(t_new *s_izi)
{
    s_izi = sb_ascii_posdup(s_izi, 'A', 'F');
    s_izi = sb_ascii_posdup(s_izi, 'a', 'f');
    s_izi = sb_ascii_posdup(s_izi, '0', '9');
    return (s_izi);
}
