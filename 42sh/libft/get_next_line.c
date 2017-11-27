/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 14:24:57 by nbeny             #+#    #+#             */
/*   Updated: 2017/06/26 14:30:18 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_nl_pointer(int fd, char **old_buffer, char **chr_ptr)
{
	char	buffer[BUFF_SIZE + 1];
	char	*free_ptr;
	int		readed;

	readed = 0;
	if (!*old_buffer && !(*old_buffer = ft_strnew(0)))
		return (-1);
	*chr_ptr = NULL;
	while (!(*chr_ptr = ft_strchr(*old_buffer, '\n')) &&
(readed = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[readed] = '\0';
		free_ptr = *old_buffer;
		if (!(*old_buffer = ft_strjoin(*old_buffer, buffer)))
			return (-1);
		free(free_ptr);
	}
	if (*chr_ptr)
		return (1);
	if (**old_buffer)
		return (1);
	return ((readed > 0) ? 1 : readed);
}

int			get_next_line(int const fd, char **line)
{
	static char	*buff;
	char		*nl_ptr;
	char		*free_ptr;
	int			result;

	if (fd < 0 || (result = get_nl_pointer(fd, &buff, &nl_ptr)) == -1)
		return (-1);
	if (!buff)
		return (0);
	free_ptr = buff;
	if (nl_ptr)
	{
		if (!(*line = ft_strsub(buff, 0, nl_ptr - buff)) ||
!(buff = ft_strdup(nl_ptr + 1)))
			return (-1);
		free(free_ptr);
	}
	else if (!(*line = ft_strdup(buff)))
		return (-1);
	else if (buff)
	{
		free(buff);
		buff = NULL;
	}
	return (result);
}
