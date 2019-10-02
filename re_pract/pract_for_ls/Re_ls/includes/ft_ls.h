/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 09:24:58 by nlunga            #+#    #+#             */
/*   Updated: 2019/10/02 14:52:15 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "./../libft/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <sys/xattr.h>
# include <time.h>
# include <stdio.h>

typedef struct	s_dir
{
	char		*name;
	char		*path;
	int			mtime;
}				t_dir;

typedef struct	s_flags
{
	int			cr_flag;
	int			l_flag;
	int			a_flag;
	int			r_flag;
	int			t_flag;
}				t_flags;

//void			ft_opendir(char *path, t_dir *data);
void			ft_opendir(char *path, t_dir data[]);
void			ft_bubblesort(t_dir order[]);
int				ft_check_flags(char **str);
int				ft_isdir(char *path);
void			ft_m_time(const char *path);
void			ft_perm(struct stat fileinfo);
void			ft_getid(struct stat buf);
int				ft_arrlen(char **arr);
int				ft_structlen(t_dir gets[]);
void			ft_display(t_dir test[], int n);
void			ft_displayall(t_dir test[], int n);
void			ft_displayrev(t_dir test[], int n);
void			ft_assign(char **str, t_flags *m_flags);
void			ft_verflag(char **str, t_flags *m_flags);
void			ft_lflag(char **path, t_flags *mflag, t_dir *data);

#endif
