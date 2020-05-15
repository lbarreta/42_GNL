#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *ptr;

	ptr = (unsigned char *)b;
	while (len--)
		*ptr++ = (unsigned char)c;
	return (b);
}


int ft_len(char *s)
{
    int i;
    i = 0;
    while (s[i] != 0)
    {
        i++;
    }
    return i;
}

int ft_strcpy(char *origem, char *destino, size_t idx)
{
    size_t i;
    
    i = 0;
    while (i < idx)
    {
        destino[i] = origem[i];
        i++;
    }
    destino[i] = 0;
    return 0;
}

char *ft_strjoin(char *s1, char *s2)
{
    char *temp;
    int n1;
    int n2;
    int i;

    n1 = ft_len(s1);
    n2 = ft_len(s2);
    temp = malloc(sizeof(char)*(n1+n2+1));
    i = 0;
    while(s1[i] != 0)
    {
        temp[i] = s1[i];
        i++;
    }
    i = 0;
    while(s2[i] != 0)
    {
        temp[i+n1] = s2[i];
        i++;
    }
    temp[i+n1] = 0;
    return temp;
}

int ft_checa_armazem(char **armazem, char *line)
{
    int i;
    int sa;
    char *aux;
    char *temp;
    char *a;

    a = *armazem;

    sa = ft_len(a);
    i = 0;
    while(a[i] != 0)
    {
        if(a[i] == '\n')
        {
            ft_strcpy(a, line, i);
            if (sa > i)
            {
                temp = *armazem;
                aux = malloc(sizeof(char)*(sa - i));
                ft_strcpy(&a[i+1],aux,sa-i-1);
                *armazem = aux;
                free(aux);
            }
            return(1);
        }
    i++;
    }
    printf("Nao achou\n");
    return 0;
}

int get_next_line(int fd, char **line)
{
    static char *arm;
    char *buffer = 0;
    char *temp;
    int BUFFER_SIZE = 3; // substituir pela cte depois
   
    arm = malloc(1);
    if (ft_checa_armazem(&arm, *line) == 1)
    {
        return 1;
    }
    else
    {
        buffer = malloc(BUFFER_SIZE);
        while (read(fd, buffer, BUFFER_SIZE) > 0)
        {   
            temp = ft_strjoin(arm, buffer); 
            arm = temp;
            if (ft_checa_armazem(&arm, *line) == 1)
            {
                free(buffer);
                return 1;
            }
        ft_memset(buffer,0,BUFFER_SIZE);
        }
        free(buffer);
    }
    return 0;
}   

int main()
{
    // ve se tem \n no armazem
    // se tiver
        // extrai string ate /n
        // copia esta string para line
        // retorna 1
    // se nao tiver
        // retorna 0
    // while not eof
        // le buffer
        // acrescenta no armazem
        // ve se tem /n no armazem

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
