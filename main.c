#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"

#ifdef STRCMP
int		ft_strcmp(char *s1, char *s2);
#else
# define STRCMP 0
#endif
#ifdef STRNCMP
int		ft_strncmp(char *s1, char *s2, unsigned int n);
#else
# define STRNCMP 0
#endif
#ifdef STRCAT
char	*ft_strcat(char *dest, char *src);
#else
# define STRCAT 0
#endif
#ifdef STRNCAT
char 	*ft_strncat(char *dest, char *src, unsigned int nb);
#else
# define STRNCAT 0
#endif
#ifdef STRSTR
char 	*ft_strstr(char *str, char *to_find);
#else
# define STRSTR 0
#endif
#ifdef STRLCAT
unsigned int ft_strlcat(char *dest, char *src, unsigned int size);
#else
# define STRLCAT 0
#endif

void check_int_fatal(void *buffer)
{
	if (!buffer)
	{
		write(2, "Fatal error\n", strlen("Fatal error\n"));
		exit(1);
	}
}

void ok()
{
	write(1, GREEN, strlen(GREEN));
	write(1, "[OK]", 5);
	write(1, RESET, strlen(RESET));
}

void ko()
{
	write(1, RED, strlen(RED));
	write(1, "[KO]", 5);
	write(1, RESET, strlen(RESET));
}

int		main()
{
#if STRCMP
	char s1[] = "Nada a ver";
	char s2[] = "Teste de Comparacao";
	char s3[] = "Teste";
	printf("STRCMP\n");
	char *buffer = calloc(50, sizeof(char));
	check_int_fatal(buffer);
	char *buffer2 = calloc(50, sizeof(char));
	check_int_fatal(buffer2);
	sprintf(buffer, "%d", ft_strcmp(s1, s2));
	sprintf(buffer2, "%d", strcmp(s1, s2));
	if (!strcmp(buffer, buffer2))
		ok();
	else
		ko();
	bzero(buffer, 50);
	bzero(buffer2, 50);
	sprintf(buffer, "%d", ft_strcmp(s2, s1));
	sprintf(buffer2, "%d", strcmp(s2, s1));
	if (!strcmp(buffer, buffer2))
		ok();
	else
		ko();
	bzero(buffer, 50);
	bzero(buffer2, 50);
	sprintf(buffer, "%d", ft_strcmp(s1, s3));
	sprintf(buffer2, "%d", strcmp(s1, s3));
	if (!strcmp(buffer, buffer2))
		ok();
	else
		ko();
	bzero(buffer, 50);
	bzero(buffer2, 50);
	sprintf(buffer, "%d", ft_strcmp(s3, s1));
	sprintf(buffer2, "%d", strcmp(s3, s1));
	if (!strcmp(buffer, buffer2))
		ok();
	else
		ko();
	bzero(buffer, 50);
	bzero(buffer2, 50);
	sprintf(buffer, "%d", ft_strcmp(s2, s3));
	sprintf(buffer2, "%d", strcmp(s2, s3));
	if (!strcmp(buffer, buffer2))
		ok();
	else
		ko();
	bzero(buffer, 50);
	bzero(buffer2, 50);
	sprintf(buffer, "%d", ft_strcmp(s3, s2));
	sprintf(buffer2, "%d", strcmp(s3, s2));
	if (!strcmp(buffer, buffer2))
	{
		write(1, GREEN, strlen(GREEN));
		write(1, "[OK]\n", 5);
		write(1, RESET, strlen(RESET));
	}
	else
	{
		write(1, RED, strlen(RED));
		write(1, "[KO]\n", 5);
		write(1, RESET, strlen(RESET));
	}
	free(buffer);
	free(buffer2);
#endif
#if STRNCMP
	char q1[] = "Nada a ver";
	char q2[] = "Teste de Comparacao";
	char q3[] = "Teste";
	printf("STRNCMP\n");
	char *zbuffer = calloc(50, sizeof(char));
	check_int_fatal(zbuffer);
	char *zbuffer2 = calloc(50, sizeof(char));
	check_int_fatal(zbuffer2);
	sprintf(zbuffer, "%d", ft_strncmp(q1, q2, 4));
	sprintf(zbuffer2, "%d", strncmp(q1, q2, 4));
	if (!strcmp(zbuffer, zbuffer2))
		ok();
	else
		ko();
	bzero(zbuffer, 50);
	bzero(zbuffer2, 50);
	sprintf(zbuffer, "%d", ft_strncmp(q2, q1, 10));
	sprintf(zbuffer2, "%d", strncmp(q2, q1, 10));
	if (!strcmp(zbuffer, zbuffer2))
		ok();
	else
		ko();
	bzero(zbuffer, 50);
	bzero(zbuffer2, 50);
	sprintf(zbuffer, "%d", ft_strncmp(q1, q3, -1));
	sprintf(zbuffer2, "%d", strncmp(q1, q3, -1));
	if (!strcmp(zbuffer, zbuffer2))
		ok();
	else
		ko();
	bzero(zbuffer, 50);
	bzero(zbuffer2, 50);
	sprintf(zbuffer, "%d", ft_strncmp(q3, q1, 100));
	sprintf(zbuffer2, "%d", strncmp(q3, q1, 100));
	if (!strcmp(zbuffer, zbuffer2))
		ok();
	else
		ko();
	bzero(zbuffer, 50);
	bzero(zbuffer2, 50);
	sprintf(zbuffer, "%d", ft_strncmp(q2, q3, 1));
	sprintf(zbuffer2, "%d", strncmp(q2, q3, 1));
	if (!strcmp(zbuffer, zbuffer2))
		ok();
	else
		ko();
	bzero(zbuffer, 50);
	bzero(zbuffer2, 50);
	sprintf(zbuffer, "%d", ft_strncmp(q3, q2, 0));
	sprintf(zbuffer2, "%d", strncmp(q3, q2, 0));
	if (!strcmp(zbuffer, zbuffer2))
	{
		write(1, GREEN, strlen(GREEN));
		write(1, "[OK]\n", 5);
		write(1, RESET, strlen(RESET));
	}
	else
	{
		write(1, RED, strlen(RED));
		write(1, "[KO]\n", 5);
		write(1, RESET, strlen(RESET));
	}
	free(zbuffer);
	free(zbuffer2);
#endif
#if STRCAT
	printf("STRCAT\n");
	char dest[20] = "Hello";
	char src[] = ", world!";
	ft_strcat(dest, src);
	char st_dest[20] = "Hello";
	char st_src[] = ", world!";
	strcat(st_dest, st_src);
	char *abuffer = calloc(50, sizeof(char));
	check_int_fatal(abuffer);
	char *abuffer2 = calloc(50, sizeof(char));
	check_int_fatal(abuffer2);
	sprintf(abuffer, "%s", dest);
	sprintf(abuffer2, "%s", st_dest);
	if (!strcmp(abuffer, abuffer2))
	{
		write(1, GREEN, strlen(GREEN));
		write(1, "[OK]\n", 5);
		write(1, RESET, strlen(RESET));
	}
	else
	{
		write(1, RED, strlen(RED));
		write(1, "[KO]\n", 5);
		write(1, RESET, strlen(RESET));
	}
	free(abuffer);
	free(abuffer2);
#endif
#if STRNCAT
	printf("STRNCAT\n");
	char dest2[20] = "123";
	char src2[] = "4567890";
	unsigned int nb = 8;

	ft_strncat(dest2, src2, nb);

	char st_dest2[20] = "123";
	char st_src2[] = "4567890";
	strncat(st_dest2, st_src2, nb);
	char *xbuffer = calloc(50, sizeof(char));
	check_int_fatal(xbuffer);
	char *xbuffer2 = calloc(50, sizeof(char));
	check_int_fatal(xbuffer2);
	sprintf(xbuffer, "%s", dest2);
	sprintf(xbuffer2, "%s", st_dest2);
	if (!strcmp(xbuffer, xbuffer2))
	{
		ok();
		write(1, "\n", 1);
	}
	else
	{
		ko();
		write(1, "\n", 1);
	}
	free(xbuffer);
	free(xbuffer2);
#endif
#if STRSTR
	printf("STRSTR\n");
	char str3[] = "012340123456789";
	char to_find3[] = "456";

	char st_str3[] = "012340123456789";
	char st_to_find3[] = "456";

	char *dbuffer = calloc(50, sizeof(char));
	check_int_fatal(dbuffer);
	char *dbuffer2 = calloc(50, sizeof(char));
	check_int_fatal(dbuffer2);
	sprintf(dbuffer, "%s", ft_strstr(str3, to_find3));
	sprintf(dbuffer2, "%s", ft_strstr(st_str3, st_to_find3));
	if (!strcmp(dbuffer, dbuffer2))
	{
		ok();
		write(1, "\n", 1);
	}
	else
	{
		ko();
		write(1, "\n", 1);
	}
	free(dbuffer);
	free(dbuffer2);
#endif
#if STRLCAT
	printf("STRLCAT\n");
	char dest4[20] = "123";
	char src4[] = "4567890";
	unsigned int size = 6;
	unsigned int result;
	unsigned int result2;

	result = ft_strlcat(dest4, src4, size);
//	printf("%s %d\n", dest4, result);

	char st_dest4[20] = "123";
	char st_src4[] = "4567890";

	result2 = strlcat(st_dest4, st_src4, size);
//	printf("%s %d\n", st_dest4, result);

	char *ebuffer = calloc(50, sizeof(char));
	check_int_fatal(ebuffer);
	char *ebuffer2 = calloc(50, sizeof(char));
	check_int_fatal(ebuffer2);
	sprintf(ebuffer, "%s %d\n", dest4, result);
	sprintf(ebuffer2, "%s %d\n", st_dest4, result2);
	if (!strcmp(ebuffer, ebuffer2))
	{
		ok();
		write(1, "\n", 1);
	}
	else
	{
		ko();
		write(1, "\n", 1);
	}
	free(ebuffer);
	free(ebuffer2);
#endif
}
