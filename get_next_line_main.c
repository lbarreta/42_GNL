/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreta <lbarreta@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 21:56:12 by lbarreta          #+#    #+#             */
/*   Updated: 2020/09/13 22:10:28 by lbarreta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//$ cat memory-leak.c
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main() {

	int fd;
	int a;
	char *linha;

	printf("Lendo arquivo ...\n");
	//open arquivo
	fd = open("arquivo",O_RDONLY);

	a = get_next_line(fd, &linha);
	printf("linha1: %s\n",linha);
	printf("retorno da função: %i\n",a);
	printf("================\n");

	a = get_next_line(fd, &linha);
	printf("linha2: %s\n",linha);
	printf("retorno da função: %i\n",a);
	printf("================\n");

	a = get_next_line(fd, &linha);
	printf("linha3: %s\n",linha);
	printf("retorno da função: %i\n",a);
	printf("================\n");

	a = get_next_line(fd, &linha);
	printf("linha4: %s\n",linha);
	printf("retorno da função: %i\n",a);
	printf("================\n");

	a = get_next_line(fd, &linha);
	printf("linha5: %s\n",linha);
	printf("retorno da função: %i\n",a);
	printf("================\n");

	a = get_next_line(fd, &linha);
	printf("linha6: %s\n",linha);
	printf("retorno da função: %i\n",a);
	printf("================\n");

	a = get_next_line(fd, &linha);
	printf("linha7: %s\n",linha);
	printf("retorno da função: %i\n",a);
	printf("================\n");

	a = get_next_line(fd, &linha);
	printf("linha8: %s\n",linha);
	printf("retorno da função: %i\n",a);
	printf("================\n");

	close(fd);
}
//$ clang -fsanitize=address -g memory-leak.c
//$ ./a.out
