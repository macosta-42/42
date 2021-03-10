/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <macosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 03:53:04 by macosta           #+#    #+#             */
/*   Updated: 2020/12/08 04:35:19 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void		ft_check_strcpy(void)
{
	char	str1[] = "Bonjour";
	char	str2[] = "Hello";
	char	str3[] = "We live, not as we wish to, but as we can.";
	char	str4[] = "All parts of a life must be beautiful.";
	char	str5[] = "Menander";
	char	str6[] = "Socrates";
	char	str7[] = "";
	printf("\033[32m=================\n");
	printf("\033[32m[+] ft_strcpy [+]\n");
	printf("\033[32m=================\n\n");
	printf("\033[36mlibasm:\033[00m");
	printf("|%s|\n", ft_strcpy(str1, str2));
	printf("\033[36mlibc  :\033[00m");
	printf("|%s|\n\n", strcpy(str1, str2));
	printf("\033[36mlibasm:\033[00m");
	printf("|%s|\n", ft_strcpy(str3, str4));
	printf("\033[36mlibc  :\033[00m");
	printf("|%s|\n\n", strcpy(str3, str4));
	printf("\033[36mlibasm:\033[00m");
	printf("|%s|\n", ft_strcpy(str5, str6));
	printf("\033[36mlibc  :\033[00m");
	printf("|%s|\n\n", strcpy(str5, str6));
	printf("\033[36mlibasm:\033[00m");
	printf("|%s|\n", ft_strcpy(str6, str7));
	printf("\033[36mlibc  :\033[00m");
	printf("|%s|\n\n", strcpy(str6, str7));
	printf("\033[36mlibasm:\033[00m");
	printf("|%s|\n", ft_strcpy(str7, str6));
	printf("\033[36mlibc  :\033[00m");
	printf("|%s|\n\n", strcpy(str7, str6));
}

void	ft_check_strlen(void)
{
	printf("\033[32m=================\n");
	printf("\033[32m[+] ft_strlen [+]\n");
	printf("\033[32m=================\n\n");
	printf("\033[36mlibasm : \033[00m");
	printf("|%zd|\n", ft_strlen("Hello word"));
	printf("\033[36mlibc   : \033[00m");
	printf("|%zd|\n\n", strlen("Hello word"));
	printf("\033[36mlibasm : \033[00m");
	printf("|%zd|\n", ft_strlen("a"));
	printf("\033[36mlibc   : \033[00m");
	printf("|%zd|\n\n", strlen("a"));
	printf("\033[36mlibasm : \033[00m");
	printf("|%zd|\n", ft_strlen("test"));
	printf("\033[36mlibc   : \033[00m");
	printf("|%zd|\n\n", strlen("test"));
}

void		ft_check_strcmp(void)
{
	char	strcmp1[] = "";
	char	strcmp2[] = "Hello World !";
	printf("\033[32m=================\n");
	printf("\033[32m[+] ft_strcmp [+]\n");
	printf("\033[32m=================\n\n");
	printf("\033[36mlibasm :\033[00m");
	printf("[%d]\n", ft_strcmp("Hello", "Hello"));
	printf("\033[36mlibc   :\033[00m");
	printf("[%d]\n\n", strcmp("Hello", "Hello"));
	printf("\033[36mlibasm :\033[00m");
	printf("[%d]\n", ft_strcmp("abcd", "abce"));
	printf("\033[36mlibc   :\033[00m");
	printf("[%d]\n\n", strcmp("abcd", "abce"));
	printf("\033[36mlibasm :\033[00m");
	printf("[%d]\n", ft_strcmp(strcmp2, strcmp1));
	printf("\033[36mlibc   :\033[00m");
	printf("[%d]\n\n", strcmp(strcmp2, strcmp1));
}

void		ft_check_write(void)
{
	printf("\033[32m=================\n");
	printf("\033[32m[+] ft_write [+]\n");
	printf("\033[32m=================\n\n");
	printf("\033[36mlibasm :\033[00m\n");
	printf("[%zd]\n", ft_write(1, "Hello World !", 13));
	printf("\033[36mlibc   :\033[00m\n");
	printf("[%zd]\n\n", write(1, "Hello World !", 13));
	printf("\033[36mlibasm :\033[00m\n");
	printf("[%zd]\n", ft_write(1, "Here is a quote from Marcus Aurelius in order to test long strings: Do not act as if you are going to live ten thousand years. The inevitable hangs over you. As long as you live, while it is in your power, be good.", 215));
	printf("\033[36mlibc   :\033[00m\n");
	printf("[%zd]\n\n", write(1, "Here is a quote from Marcus Aurelius in order to test long strings: Do not act as if you are going to live ten thousand years. The inevitable hangs over you. As long as you live, while it is in your power, be good.", 215));
	printf("\033[36mlibasm :\033[00m\n");
	printf("[%zd]\n", ft_write(1, NULL, 3));
	printf("\033[36mlibc   :\033[00m\n");
	printf("[%zd]\n\n", write(1, NULL, 3));
}

void		ft_check_read(void)
{
	ssize_t		ret_read;
	int			fd;	
	char		buf[5000];

	printf("\033[32m=================\n");
	printf("\033[32m[+] ft_read [+]\n");
	printf("\033[32m=================\n\n");
	fd = open("ft_write.s", O_RDONLY);
	printf("\033[36mlibasm :\033[00m");
	ret_read = ft_read(fd, buf, 42);
	buf[ret_read] = '\0';
	printf("|%s|\n[%zd]\n", buf, ret_read);
	close(fd);
	fd = open("ft_write.s", O_RDONLY);
	printf("\033[36mlibc   :\033[00m");
	ret_read = read(fd, buf, 42);
	buf[ret_read] = '\0';
	printf("|%s|\n[%zd]\n\n", buf, ret_read);
	close(fd);
	fd = open("ft_write.s", O_RDONLY);
	printf("\033[36mlibasm :\033[00m");
	ret_read = 0;
	ret_read = ft_read(fd, buf, 2000);
	buf[ret_read] = '\0';
	printf("|%s|\n[%zd]\n", buf, ret_read);
	close(fd);
	fd = open("ft_write.s", O_RDONLY);
	printf("\033[36mlibc   :\033[00m");
	ret_read = 0;
	ret_read = read(fd, buf, 2000);
	buf[ret_read] = '\0';
	printf("|%s|\n[%zd]\n\n", buf, ret_read);
	close(fd);
}

void		ft_check_strdup(void)
{
	char	dup[] = "New Malloc";
	char	dup1[] = "little";
	char	dup2[] = "Very big malloc, Here is a quote from Marcus Aurelius in order to test long strings: Do not act as if you are going to live ten thousand years. The inevitable hangs over you. As long as you live, while it is in your power, be good.";
	printf("\033[32m=================\n");
	printf("\033[32m[+] ft_strdup [+]\n");
	printf("\033[32m=================\n\n");
	printf("\033[36mlibasm :\033[00m");
	printf("|%s|\n", ft_strdup(dup));
	printf("\033[36mlibc   :\033[00m");
	printf("|%s|\n\n", strdup(dup));
	printf("\033[36mlibasm :\033[00m");
	printf("|%s|\n", ft_strdup(dup1));
	printf("\033[36mlibc   :\033[00m");
	printf("|%s|\n\n", strdup(dup1));
	printf("\033[36mlibasm :\033[00m");
	printf("|%s|\n", ft_strdup(dup2));
	printf("\033[36mlibc   :\033[00m");
	printf("|%s|\n\n", strdup(dup2));
}
/*
void		ft_check_strdup(void)
{
	char *h = ft_strdup("bonjour");
	printf("%s\n", h);
	free(h);
}
*/
int		main(void)
{
	ft_check_strlen();
	ft_check_strcpy();
	ft_check_strcmp();
	ft_check_write();
	ft_check_read();
	ft_check_strdup();
	return (0);
}
