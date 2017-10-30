#include "globing.h"

t_new   *class_digit_posix_dup(t_new *s_izi)
{
    s_izi = sb_ascii_posdup(s_izi, '0', '9');
    return (s_izi);
}

t_new   *class_graph_posix_dup(t_new *s_izi)
{
    s_izi = sb_ascii_posdup(s_izi, 21, 126);
    return(s_izi);
}

t_new   *class_lower_posix_dup(t_new *s_izi)
{
    s_izi = sb_ascii_posdup(s_izi, 'a', 'z');
    return (s_izi);
}

t_new   *class_print_posix_dup(t_new *s_izi)
{
    s_izi = sb_ascii_posdup(s_izi, 32, 126);
    return (s_izi);
}

t_new   *class_punct_posix_dup(t_new *s_izi)
{
    s_izi = sb_ascii_posdup(s_izi, 33, 47);
    s_izi = sb_ascii_posdup(s_izi, 58, 64);
    s_izi = sb_ascii_posdup(s_izi, 91, 96);
    s_izi = sb_ascii_posdup(s_izi, 123, 126);
    return (s_izi);
}
