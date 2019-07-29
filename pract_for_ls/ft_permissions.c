/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_permissions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 09:53:04 by nlunga            #+#    #+#             */
/*   Updated: 2019/07/29 12:43:40 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_permissions(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	struct stat fileinfo;
	int i;

	i = 2;
//	while (ft_check_flags(argc, argv[i]) == 0)
//	{
	if (stat(argv[i], &fileinfo) < 0)
		return (1);
	printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
	printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
	printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
	printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
	printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
	printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
	printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
	printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
	printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
	printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
	//	printf("\n\n");

//		i++;
//	}
	return (0);
}
