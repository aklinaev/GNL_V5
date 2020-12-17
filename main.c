/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apenrose <apenrose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 23:47:54 by apenrose          #+#    #+#             */
/*   Updated: 2020/12/16 00:48:37 by apenrose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <fcntl.h>
// #include <string.h>
// #include "get_next_line.h"
// //#include "get_next_line_bonus.h"
// #include <stdio.h>
// #define RESET   "\033[0m"
// #define GREEN   "\033[32m"
// #define MAGENTA "\033[35;1m"
// #define YELLOW  "\033[33m"
// #define BLUE    "\033[34m"
// #define DOLLAR GREEN"$" RESET
//
// int	test_gnl(int fd, char *line)
// {
// 	int i;
// 	printf(MAGENTA"\n********************************** ( fd %d ) *********************************"RESET"\n\n", fd);
// 	while ((i = get_next_line(fd, &line)) > 0)
// 	{
//
// 		printf("i = %d %s%s\n", i, line, DOLLAR);
// 		free(line);
// 	}
// 	if (fd > 0)
// 	{
// 		printf("i = %d %s%s\n", i, line, DOLLAR);
// 		free(line);
// 	}
// 	return (0);
// }
// int main()
// {
// 	int fd[10];
// 	char *line = NULL;
//
// 	fd[0] = open("/Users/apenrose/get_next_line/alphabet.txt", O_RDONLY);
// 	fd[1] = open("/Users/apenrose/get_next_line/all_i_ask.txt", O_RDONLY);
// 	fd[2] = open("/Users/apenrose/get_next_line/empty.txt", O_RDONLY);
// 	fd[3] = open("/Users/apenrose/get_next_line/file.txt", O_RDONLY);
// 	fd[4] = open("/Users/apenrose/get_next_line/fail.txt", O_RDONLY);
// 	fd[5] = open("/Users/apenrose/get_next_line/christmas_tree.txt", O_RDONLY);
//
// 	for(int i = 0; i < 6; i++)
// 		test_gnl(fd[i], line);
// 	//while(1){}
// 	//sleep (100);
// 	return (0);
// }

 #include<stdio.h>
 #include<fcntl.h>
 #include<stdlib.h>
 #include "get_next_line.h"

 int main(void)
 {
   int n;
   n = 1;
   int fd;
   char *str;
   int i = 0;

   //fd = open("christmas_tree.txt", O_RDONLY);
   fd = open("/Users/apenrose/get_next_line_5/r2.txt", O_RDONLY);
   while (n > 0)
      {
          n = get_next_line(fd, &str);
          i++;
          //printf("gnl = %d\n", n);
          printf("%s\n", str);
          free(str);

      }
     printf("%s\n", str);
   //free(str);
 //  sleep(100);
     return (0);
 }



//#include <fcntl.h>
//#include <sys/stat.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <unistd.h>
//
//int				get_next_line(int fd, char **line);
//
//int main()
//{
//    int             fd;
//    int             i;
//    int             j;
//    char    		*line = 0;
//    char			*lineadress[66];
//
//    j = 1;
//    printf("\n==========================================\n");
//    printf("========== TEST 1 : The Alphabet =========\n");
//    printf("==========================================\n\n");
//
//    if (!(fd = open("/Users/apenrose/get_next_line_3/files/alphabet", O_RDONLY)))
//    {
//        printf("\nError in open\n");
//        return (0);
//    }
//    while ((i = get_next_line(fd, &line)) > 0)
//    {
//        printf("|%s\n", line);
//        lineadress[j - 1] = line;
//        j++;
//    }
//    printf("|%s\n", line);
//    free(line);
//    close(fd);
//
//    if (i == -1)
//        printf ("\nError in Fonction - Returned -1\n");
//    else if (j == 66)
//        printf("\nRight number of lines\n");
//    else if (j != 66)
//        printf("\nNot Good - Wrong Number Of Lines\n");
//    while (--j > 0)
//        free(lineadress[j - 1]);
//    j = 1;
//
//    printf("\n==========================================\n");
//    printf("========= TEST 2 : Empty Lines ===========\n");
//    printf("==========================================\n\n");
//
//    if (!(fd = open("/Users/apenrose/get_next_line_3/files/empty_lines", O_RDONLY)))
//    {
//        printf("\nError in open\n");
//        return (0);
//    }
//    while ((i = get_next_line(fd, &line)) > 0)
//    {
//        printf("|%s\n", line);
//        free(line);
//        j++;
//    }
//    printf("|%s\n", line);
//    free(line);
//    close(fd);
//
//    if (i == -1)
//        printf ("\nError in Fonction - Returned -1\n");
//    else if (j == 9)
//        printf("\nRight number of lines\n");
//    else if (j != 9)
//        printf("\nNot Good - Wrong Number Of Lines\n");
//    j = 1;
//    printf("\n==========================================\n");
//    printf("======== TEST 3 : The Empty File =========\n");
//    printf("==========================================\n\n");
//
//    if (!(fd = open("/Users/apenrose/get_next_line_3/files/empty_file", O_RDONLY)))
//    {
//        printf("\nError in open\n");
//        return (0);
//    }
//    while ((i = get_next_line(fd, &line)) > 0)
//    {
//        printf("|%s\n", line);
//        free(line);
//        j++;
//    }
//    printf("|%s\n", line);
//    free(line);
//    close(fd);
//
//    if (i == -1)
//        printf ("\nError in Fonction - Returned -1\n");
//    else if (j == 1)
//        printf("\nRight number of lines\n");
//    else if (j != 1)
//        printf("\nNot Good - Wrong Number Of Lines\n");
//    j = 1;
//    printf("\n==========================================\n");
//    printf("========= TEST 4 : One New Line ==========\n");
//    printf("==========================================\n\n");
//
//    if (!(fd = open("/Users/apenrose/get_next_line_3/files/1_newline", O_RDONLY)))
//    {
//        printf("\nError in open\n");
//        return (0);
//    }
//    while ((i = get_next_line(fd, &line)) > 0)
//    {
//        printf("|%s\n", line);
//        free(line);
//        j++;
//    }
//    printf("|%s\n", line);
//    free(line);
//    close(fd);
//
//    if (i == -1)
//        printf ("\nError in Fonction - Returned -1\n");
//    else if (j == 2)
//        printf("\nRight number of lines\n");
//    else if (j != 2)
//        printf("\nNot Good - Wrong Number Of Lines\n");
//    j = 1;
//    printf("\n==========================================\n");
//    printf("========= TEST 5 : Four New Lines ========\n");
//    printf("==========================================\n\n");
//
//    if (!(fd = open("/Users/apenrose/get_next_line_3/files/4_newlines", O_RDONLY)))
//    {
//        printf("\nError in open\n");
//        return (0);
//    }
//    while ((i = get_next_line(fd, &line)) > 0)
//    {
//        printf("|%s\n", line);
//        free(line);
//        j++;
//    }
//    printf("|%s\n", line);
//    free(line);
//    close(fd);
//
//    if (i == -1)
//        printf ("\nError in Fonction - Returned -1\n");
//    else if (j == 5)
//        printf("\nRight number of lines\n");
//    else if (j != 5)
//        printf("\nNot Good - Wrong Number Of Lines\n");
//    j = 1;
//    printf("\n==========================================\n");
//    printf("============== TEST 6 : 42 ===============\n");
//    printf("==========================================\n\n");
//
//    if (!(fd = open("/Users/apenrose/get_next_line_3/files/41_char", O_RDONLY)))
//    {
//        printf("\nError in open\n");
//        return (0);
//    }
//    while ((i = get_next_line(fd, &line)) > 0)
//    {
//        printf("|%s\n", line);
//        free(line);
//        j++;
//    }
//    printf("|%s\n", line);
//    free(line);
//    close(fd);
//    if (!(fd = open("/Users/apenrose/get_next_line_3/files/42_char", O_RDONLY)))
//    {
//        printf("\nError in open\n");
//        return (0);
//    }
//    while ((i = get_next_line(fd, &line)) > 0)
//    {
//
//        printf("|%s\n", line);
//        free(line);
//        j++;
//    }
//    printf("|%s\n", line);
//    free(line);
//    close(fd);
//    if (!(fd = open("/Users/apenrose/get_next_line_3/files/43_char", O_RDONLY)))
//    {
//        printf("\nError in open\n");
//        return (0);
//    }
//    while ((i = get_next_line(fd, &line)) > 0)
//    {
//        printf("|%s\n", line);
//        free(line);
//        j++;
//    }
//    printf("|%s\n", line);
//    free(line);
//    close(fd);
//
//    if (i == -1)
//        printf ("\nError in Fonction - Returned -1\n");
//    else if (j == 1)
//        printf("\nRight number of lines\n");
//    else if (j != 1)
//        printf("\nNot Good - Wrong Number Of Lines\n");
//    j = 1;
//    printf("\n==========================================\n");
//    printf("============= TEST 7 : Marge =============\n");
//    printf("==========================================\n\n");
//
//    int fd2;
//
//    if (!(fd = open("/Users/apenrose/get_next_line_3/files/half_marge_top", O_RDONLY)))
//    {
//        printf("\nError in open\n");
//        return (0);
//    }
//    if (!(fd2 = open("files/half_marge_bottom", O_RDONLY)))
//    {
//        printf("\nError in open\n");
//        return (0);
//    }
//    while ((i = get_next_line(fd, &line)) > 0)
//    {
//        printf("%s\n", line);
//        free(line);
//        j++;
//    }
//    free(line);
//    while ((i = get_next_line(fd2, &line)) > 0)
//    {
//        printf("%s\n", line);
//        free(line);
//        j++;
//    }
//    printf("%s\n", line);
//    free(line);
//    close(fd);
//    close(fd2);
//
//    if (i == -1)
//        printf ("\nError in Fonction - Returned -1\n");
//    else if (j == 25)
//        printf("\nRight number of lines\n");
//    else if (j != 25)
//        printf("\nNot Good - Wrong Number Of Lines\n");
//    j = 1;
//    printf("\n==========================================\n");
//    printf("========= TEST 8 : Wrong Input ===========\n");
//    printf("==========================================\n\n");
//
//    if (get_next_line(180, &line) == -1)
//        printf("Well Done, you return -1 if no FD\n\n");
//    else
//        printf("Not Good, you don't return -1 if no FD\n\n");
//    //sleep(100);
//    return (0);
//
//}

