


$all:
	gcc globing/*.c -L globing/libft -lft -I . -g
gg:
	~/.brew/Cellar/gcc/7.2.0/bin/gcc-7  globing/*.c -L globing/libft -lft -I . -g -fdump-rtl-expand
op:
	gcc globing/*.c -L globing/libft -lft -I . -g3 -fsanitize=address
