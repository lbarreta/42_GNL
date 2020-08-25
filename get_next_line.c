/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreta <lbarreta@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 21:56:12 by lbarreta          #+#    #+#             */
/*   Updated: 2020/08/25 20:17:51 by lbarreta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	int			read_return;
	char		buf[BUFFER_SIZE + 1];
	static char	*rest;

	if (fd < 0 || line == NULL || BUFFER_SIZE == 0)
		return (-1);
	if (rest == NULL)
		rest = "";
	while ((read_return = read(fd, buf, BUFFER_SIZE)) >0 )
	{
		buf[read_return]='\0';
		rest = ft_strjoin(rest, buf);
		while (read_return >= 0)
		{
			if(buf[read_return] == '\n')
				return (ft_split_line (rest, line));
			read_return --;
		}
	}
	if (ft_strlen(rest) > 1)
		return (ft_split_line (rest, line));
	return (0);
}
