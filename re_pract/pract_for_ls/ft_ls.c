/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 08:13:30 by nlunga            #+#    #+#             */
/*   Updated: 2019/08/31 02:06:58 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
/*
int	the_time(int argc, char **argv)
{
	time_t			my_time;
	struct tm		*mytm;

	my_time = time(NULL);

	printf("%s\n", ctime(&my_time));
	return (0);
}*/

int	main(int argc, char **argv)
{
	int	i;
	int c;

	struct s_flags *m_flags;
	struct c_list *find_data;
	//d_list *man_data;

	m_flags = (t_flags *)malloc(sizeof(t_flags));
	find_data = (d_list *)malloc(sizeof(d_list));
	i = 1;
	if (argc < 2)
	{
		if (argv[0])
		{
			c = 0;
			ft_otherdir(".", find_data);
			while (find_data->dir_strings[c] != NULL)
				ft_strdel(&find_data->dir_strings[c++]);
	//12		ft_sort(argc, ft_currentdir(find_data))
		}
		free(find_data);
	}
	else
	{
		/*
		c = 0;
		while (argv[i] != NULL)
		{
			ft_putstr(argv[i]);
			ft_putendl(":");
			ft_otherdir(argv[i], find_data);
			while (find_data->dir_strings[c] != NULL)
				ft_putendl(find_data->dir_strings[c++]);
			ft_putendl(" ");
			i++;
		}
		*/

		do_flags(argc, argv, m_flags, find_data);

//		while (argv[i])
//		{
	//		ft_otherdir(argv[i]);
//			i++;
//		}
		//ft_isdir(argc,argv);
	//	i = 1;
/*3		if (ft_check_flags(argc, argv) == 0)
			printf("Not a flag");
		else
		{333333*/
			//ft_out_of_scope(argc, argv);
			/*
			ft_verflag(argv, m_flags);
			printf("Testing -l flag: %d\n", m_flags->l_flag);
			printf("Testing -r flag: %d\n", m_flags->r_flag);
			printf("Testing -a flag: %d\n", m_flags->a_flag);
			printf("Testing -t flag: %d\n", m_flags->t_flag);
			printf("Testing -R flag: %d\n", m_flags->cr_flag);
			*/
	//		if (m_flags->l_flag)
	//			ft_lflag(argc, argv, m_flags, find_data);
	//1		if (m_flags->a_flag)
	//1			ft_aflag(argc, argv, m_flags, find_data);
	//1		if (m_flags->r_flag)
	//1			ft_rflag(argc, argv, m_flags, find_data);
	//		if (m_flags->cr_flag)
	//			ft_crflag(argc, argv, m_flags, find_data);
	//		free(m_flags);
			//printf("Is a flag");
	//	}
/*
		while (argv[i])
		{
			if (ft_check_flags(argc, argv) == 1) // come back and edit
				i++;
			else if (ft_isdir(argc, argv))// == 1) // come back and edit
			{
				ft_otherdir(argv[i]);
			}
			ft_otherdir(argv[i]);
			i++;
		}
		*/
	}
//	the_time(argc, argv);
//	sleep(10);
	return (0);
}

// when someone runs the ft_ls program
// the program must take in a certain number of parameters
// the first parameter is the program name
// if you just ran the program without adding any parameter
// the program must print the items within the current directory
// if you ran the program with parameters
// check which parameters are options
// you can identify an option because it has '-' infront of the option
// if not an option is it a directory
// if it's directory open it and print out its contents
//
// a way to handle indefine arity is through the use of linked lists
// strsplit the arguments removing all the spacing
// use
// create a list and then iterate trough the lists
// store the last variable/node of the list somewhere
//
