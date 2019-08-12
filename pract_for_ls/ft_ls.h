/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 08:47:31 by nlunga            #+#    #+#             */
/*   Updated: 2019/08/12 16:31:28 by nlunga           ###   ########.fr       */
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

typedef struct		c_list
{
	char			*current;
	struct c_list	*next;
}					d_list;

void				ft_otherdir(char *argv);
void				ft_a_otherdir(char *argv);
void				ft_currentdir(int argc, char **argv);
void				ft_a_currentdir(int argc, char **argv);
//void				ft_display_owner_perm(fileStat.st_mode);
int					ft_check_flags(int argc, char **argv);
int					ft_isdir(int argc, char **argv);
int					ft_conflags(int argc, char **argv);
int					ft_reconflags(int argc, char **argv);
int					ft_check_multi(char *str, char c, int i);
int					ft_lflag(int argc, char **argv, t_flags *m_flags);
int					ft_flags(int argc , char ** argv);
int					ft_out_of_scope(int argc, char **argv);
//int					ft_permissions(/*int argc,*/ char **argv);
//void					ft_permissions(void);
int					ft_verflag(char	**argv, t_flags *m_flags);
void				ft_m_time(const char *path);
#endif
