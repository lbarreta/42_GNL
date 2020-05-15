/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreta <lbarreta@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 21:56:12 by lbarreta          #+#    #+#             */
/*   Updated: 2020/05/12 22:51:48 by lbarreta         ###   ########.fr       */
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
	//read_return = read(fd, buf, BUFFER_SIZE, buf_pos);
	read_return = read(fd, buf, BUFFER_SIZE);

	rest = ft_strjoin(rest, buf);
	line = ft_split_line (rest, return_value);

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
