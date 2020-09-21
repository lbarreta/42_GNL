/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreta <lbarreta@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 21:56:12 by lbarreta          #+#    #+#             */
/*   Updated: 2020/09/20 23:40:56 by lbarreta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_firstalloc(char *s1)
{
	s1 = malloc(1 * sizeof(char));
	s1[0] = '\0';
	return (s1);
}

int		ft_error(char **rest)
{
	ft_strfree(rest);
	return (-1);
}

void	ft_changerest(char **rest, char *buf)
{
	char	*temp;

	temp = ft_strjoin(*rest, buf);
	ft_strfree(rest);
	*rest = temp;
}

int		get_next_line(int fd, char **line)
{
	int			read_return;
	char		buf[BUFFER_SIZE + 1];
	static char	*rest;
	int			len;

	if (fd < 0 || line == NULL || BUFFER_SIZE == 0)
		return (-1);
	if (rest == NULL)
		rest = ft_firstalloc(rest);
	while ((read_return = read(fd, buf, BUFFER_SIZE)))
	{
		if (read_return < 0)
			return (ft_error(&rest));
		buf[read_return] = '\0';
		ft_changerest(&rest, buf);
		len = ft_strlen(rest);
		while (len >= 0)
		{
			if (rest[len] == '\n')
				return (ft_split_line(&rest, line));
			len--;
		}
	}
	return (ft_split_line(&rest, line));
}
