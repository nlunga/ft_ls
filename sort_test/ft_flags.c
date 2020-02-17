/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 13:08:13 by nlunga            #+#    #+#             */
/*   Updated: 2019/08/05 09:42:03 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int ft_flags(int argc, char **argv)
{
    struct stat file_stat;

    if (argc != 2)
        return 1;
    if (stat(argv[2],&file_stat) < 0)    
        return 1;
    printf("Information for %s\n",argv[2]);
    printf("---------------------------\n");
    printf("File Size: \t\t%ld bytes\n",file_stat.st_size);
    printf("Number of Links: \t%ld\n",file_stat.st_nlink);
    printf("File inode: \t\t%ld\n",file_stat.st_ino);
    printf("File Permissions: \t");
    printf( (S_ISDIR(file_stat.st_mode)) ? "d" : "-");
    printf( (file_stat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (file_stat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (file_stat.st_mode & S_IXUSR) ? "x" : "-");
    printf( (file_stat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (file_stat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (file_stat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (file_stat.st_mode & S_IROTH) ? "r" : "-");
    printf( (file_stat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (file_stat.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n\n");
 
    printf("The file %s a symbolic link\n", (S_ISLNK(file_stat.st_mode)) ? "is" : "is not");
    return 0;
}
