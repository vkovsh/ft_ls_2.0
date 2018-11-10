/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 13:47:29 by vkovsh            #+#    #+#             */
/*   Updated: 2018/08/14 13:47:32 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "ft_printf.h"
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <sys/sysmacros.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <errno.h>
# define LS_SMALL_L 1
# define LS_BIG_R 2
# define LS_SMALL_A 4
# define LS_SMALL_R 8
# define LS_SMALL_D 16
# define LS_ONE 32
# define LS_BIG_U 64
# define LS_SMALL_T 128
# define LS_BIG_S 256
# define LS_SMALL_I 512
# define LS_SMALL_S 1024
# define FLAGS_ARRAY "lRard1UtSis"
# define PERM_FULL "-rwxrwxrwx"  
# define HELP_TXT "Try './ft_ls --help' for more information.\n"
# define PM_A {0,S_IRUSR,S_IWUSR,S_IXUSR,S_IRGRP,S_IWGRP,
# define PM_B S_IXGRP,S_IROTH,S_IWOTH,S_IXOTH}
# define PERM_MACRO PM_A PM_B
# define DIR_COLOR 0x0000ff
# define SOFT_LINK_COLOR 0x00ffff
# define BIN_COLOR 0x00ff00
# define REG_COLOR 0xffffff
# define FIF_COLOR 0x0f00f0
# define TIM_A {S_IFREG, S_IFDIR, S_IFCHR, S_IFBLK, S_IFIFO,
# define TYPE_ID_MACRO TIM_A S_IFLNK, S_IFSOCK}
# define REG_PAIR (t_colorpair){.fc=0xffffff}
# define DIR_PAIR (t_colorpair){.fc=0x6666FF}
# define CHR_PAIR (t_colorpair){.fc=0x0000ff,.bc=0xffff00}
# define BLK_PAIR (t_colorpair){.fc=0x0000ff,.bc=0x00ffff}
# define FIFO_PAIR (t_colorpair){.fc=0xa0a000}
# define LNK_PAIR (t_colorpair){.fc=0x00ffff}
# define SOC_PAIR (t_colorpair){.fc=0x00ffff}
# define CP_A {REG_PAIR, DIR_PAIR, CHR_PAIR, BLK_PAIR,
# define COLOR_PAIRS CP_A FIFO_PAIR, LNK_PAIR, SOC_PAIR}
# define FILE_TYPE_MARKERS "-dcbpls"
# define IS_FLAG_SET(fs, f) ((fs) & (f))
# define FT_ERROR(n)({ft_printf("ft_ls: %s\n", strerror(errno));})
# define APPEND_IT(f,name)(name[0] != '.' || IS_FLAG_SET(f, LS_SMALL_A))
# define IS_BIN(m)((m&S_IXUSR)|(m&S_IXGRP)|(m&S_IXOTH))

extern int				g_depth;
int						errno;
typedef struct stat		t_stat;
typedef struct dirent	t_dirent;
typedef void			(*t_bintree_traverse)(t_bintree **t,
						t_node_action action);
typedef void			(*t_update_width)(void *c);

typedef struct			s_colorpair
{
	int					fc;
	int					bc;
}						t_colorpair;

typedef enum			e_perm
{
	IRUSR,
	IWUSR,
	IXUSR,
	IRGRP,
	IWGRP,
	IXGRP,
	IROTH,
	IWOTH,
	IXOTH,
	PERM_TOTAL
}						t_perm;

typedef enum			e_filetype
{
	ERR = -1,
	REG_FILE,
	DIR_FILE,
	CHR_FILE,
	BLK_FILE,
	FIFO_FILE,
	LNK_FILE,
	SOCK_FILE,
	FILE_TYPE_TOTAL
}						t_filetype;

typedef enum			e_lsflag
{
	LS_SMALL_L_POS,
	LS_BIG_R_POS,
	LS_SMALL_A_POS,
	LS_SMALL_R_POS,
	LS_SMALL_D_POS,
	LS_ONE_POS,
	LS_BIG_U_POS,
	LS_SMALL_T_POS,
	LS_BIG_S_POS,
	LS_SMALL_I_POS,
	LS_SMALL_S_POS,
	LS_FLAG_TOTAL
}						t_lsflag;

typedef struct			s_catalog
{
	char				*name;
	t_filetype			filetype;
	t_stat				*clstat;
	int					stat_res;
	int					lstat_res;
}						t_catalog;

typedef struct			s_ftls
{
	uint8_t				pw_name_width;
	uint8_t				gr_name_width;
	uint8_t				nlink_width;
	uint8_t				size_width;
	uint8_t				major_width;
	uint8_t				minor_width;
	int					flags;
	t_bintree			*arguments;
	char				delimiter;
	void				(*print_arg)(t_catalog *, char);
	t_bintree_traverse	traverse;
	t_update_width		update_width_ptr;
	t_compare_keys		compare_func_ptr;
}						t_ftls;

extern t_ftls			*g_ftls;

int						set_catalog_from_arg(t_bintree **b,
						char *str, void *order);
bool					is_system_dot_dir(char *arg);
void					get_args(int a, char **args);
void					parse_args(t_bintree *b);
void					print_verbose_info(t_catalog *c, char delim);
void					print_info(t_catalog *c, char delim);
t_filetype				get_file_type(t_catalog *c);
t_bintree				*read_directory(const char *str);
const char				*cut_name(const char *name);
void					update_field_width(void *ptr);
int						comp_scalars(int64_t *a, int64_t *b);
#endif
