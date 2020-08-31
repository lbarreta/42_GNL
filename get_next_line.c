/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreta <lbarreta@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 21:56:12 by lbarreta          #+#    #+#             */
/*   Updated: 2020/08/31 14:40:50 by lbarreta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	int			read_return;
	char		buf[BUFFER_SIZE + 1];
	char		*temp;
	static char	*rest;

	if (fd < 0 || line == NULL || BUFFER_SIZE == 0)
		return (-1);
	if (rest == NULL)
	{
		rest = malloc(1 * sizeof(char));
		rest[0] = '\0';
	}
	while ((read_return = read(fd, buf, BUFFER_SIZE)))
	{
		if (read_return < 0)
			return (-1);
		buf[read_return] = '\0';
		temp = ft_strjoin(rest, buf);
		ft_strfree(rest);
		rest = temp;
		while (read_return >= 0)
		{
			if (buf[read_return] == '\n')
				return (ft_split_line(rest, line));
			read_return--;
		}
	}
	return (ft_split_line(rest, line));
}
