/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 08:47:31 by nlunga            #+#    #+#             */
/*   Updated: 2019/09/18 16:14:39 by nlunga           ###   ########.fr       */
/*   Updated: 2019/09/13 22:45:30 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "./libft/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <sys/xattr.h>
# include <time.h>
# include <stdio.h>
# define FLAGE_SIZE 2019

typedef struct		s_flags
{
	int				l_flag;
	int				a_flag;
	int				r_flag;
	int				t_flag;
	int				cr_flag;
}					t_flags;

typedef struct	s_dir
{
	char		*name;
	char		*path;
	struct stat	file;
	int			mtime;
}				t_dir;

typedef struct		c_list
{
	char			*current;
	char			*strings[2018];
	char			*path;
	char			*mtime[2021];
	int				time[2021];
	char			*mfile[2021];
	char			*dr[2019];
	char			*big_r[20000];
	struct c_list	*next;
}					d_list;

void	ft_otherdir(char *argv, d_list *find_data);
void	ft_aotherdir(char *argv, d_list *find_data);
void	ft_opendirtime(char *path, t_dir data[]);
void	ft_currentdir(d_list *find_data);
void	ft_bubblesort(char **str);
void	do_flags(int argc, char **argv, t_flags *m_flags, d_list *find_data, t_dir *data);
void    ft_timeflag(int argc, char **path, t_flags *mflag, t_dir *data);
//void	ft_display_owner_perm(fileStat.st_mode);
int		ft_check_flags(int argc, char **argv);
//int	ft_isdir(int argc, char **argv);
int		ft_isdir(char *argv);
int		ft_arrlen(char **arr);
int		ft_structlen(t_dir gets[]);
int		ft_conflags(int argc, char **argv);
int		ft_reconflags(int argc, char **argv);
int		ft_check_multi(char *str, char c, int i);
int		ft_lflag(int argc, char **argv, t_flags *mf, d_list *f);
void	ft_rflag(int argc, char **argv, t_flags *m_flags, d_list *find_data);
//void	ft_tflag(int argc, char **argv, d_list *find_data);
char	**ft_tflag(char *dir, char **array, int n);
//void	ft_crflag(int argc, char **argv, t_flags *m_flags, d_list *find_data);
void	ft_crflag(int argc, char **path, t_flags *m_flags, d_list *find_data);
void	ft_aflag(int argc, char **argv, t_flags *m_flags, d_list *find_data);
int		ft_flags(int argc, char **argv);
int		ft_out_of_scope(int argc, char **argv);
//int	ft_permissions(/*int argc,*/ char **argv);
//void	ft_permissions(void);
void	ft_verflag(int argc, char	**argv, t_flags *m_flags);
void	da_perm(struct stat fileinfo);
void	ft_getuid(struct stat fileinfo);
void	ft_getgid(struct stat fileinfo);
void	ft_displaytime(t_dir test[], int n);
void	number_sort(t_dir order[], int n);
void	ft_m_time(const char *path);
char	**ft_sort(int argc, void (*ft_currentdir)(d_list), d_list *find_data);
#endif
