/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreta <lbarreta@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 21:56:12 by lbarreta          #+#    #+#             */
/*   Updated: 2020/08/12 23:57:27 by lbarreta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static int buf_pos;
	static int return_value;
	int read_return;
	char *buf;
	char *rest;

	buf_pos = 0;
	rest = "";
	//printf("buffer_size: %i\n", BUFFER_SIZE);
	while (read_return = read(fd, buf, BUFFER_SIZE))
	{
		buf[read_return]='\0';
		printf("read_return: %i\n", read_return);
		rest = ft_strjoin(rest, buf);
		printf("rest: %s\n", rest);
	}
	line[0] = ft_split_line (rest, return_value);
	printf("line[0]: %s\n", line[0]);
	//read(fd, *buf, BUFFER_SIZE);

	buf_pos = buf_pos + read_return;
	return (return_value);
}

int main() {

	int fd;
	int a;
	char *linha;

	printf("Lendo arquivo ...\n");
	//open arquivo
	fd = open("arquivo",O_RDONLY);

	a = get_next_line(fd, &linha);
	printf("linha: %s\n",linha);
	printf("================\n");

	a = get_next_line(fd, &linha);
	printf("linha: %s\n",linha);
	printf("================\n");

	a = get_next_line(fd, &linha);
	printf("linha: %s\n",linha);
	printf("================\n");

	a = get_next_line(fd, &linha);
	printf("linha: %s\n",linha);
	printf("================\n");

	a = get_next_line(fd, &linha);
	printf("linha: %s\n",linha);
	printf("================\n");

	close(fd);
}
