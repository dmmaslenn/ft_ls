/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 17:05:10 by dmaslenn          #+#    #+#             */
/*   Updated: 2017/05/17 17:28:58 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_LS_H
# define __FT_LS_H
# include "libft/libft.h"
# include <dirent.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>

typedef	struct		s_f
{
	int denied;
	int wl;
	int u;
	int min;
	int maj;
	int mr;
	int rmin;
	int rmaj;
	int rmmaj;
	int rmmin;
	int				f;
	char			*path;
	int				id;
	int				i;
	int				r;
	int				t;
	int				r1;
	char			*a;
	char			*name;
	int				month;
	long			time;
	int				tiime;
	long long		ntime;
	int tim;
	int j;
	char			*rcall;
}					t_f;

typedef struct		s_node
{
	t_f				*d;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct		s_dbl
{
	int 			wheellen;
	char 			*wheel;
	int				err;
	char 			**c;
	int				ert;
	int				erf;
	int				a;
	int				l;
	int				k;
	int				rbf;
	int				r;
	int				t;
	int				u;
	int				s;
	int				ww;
	int				aa;
	int				hh;
	int				ii;
	int				bb;
	int				gg;
	int				kk;
	int				mm;
	int				ff;
	int				error;
	char			*d;
	char			*path;
	char  			*pathf;
	char			**q;
	int				ll;
	int				w;
	int				tim;
	int				target;
	char			*folder;
	size_t			size;
	t_node			*head;
	t_node			*tail;
}					t_dbl;

int			checkifdenied(char *path);
char				**sortr(char **d, t_dbl *list);
char		*sortingr(t_dbl *list, int a, char **d, char *f, int i);
char		*spinitr(t_dbl *list, int a, char **d, char *f, int i, int b);
char				**excluder(t_dbl *list, char **d, char *c, int q);
int			validationr(int argc, char **argv, t_dbl *list);
int			errorr(char **argv, int i, t_dbl *list);
int			checkfolderr(t_dbl *list, char **argv, int i);
int		er(char **argv, int c, t_dbl *list, int i);
int		whilejr(t_dbl *list, char **argv, int i, int c);
int		heeelpr(t_dbl *list, int w);
int		checkflagr(char c, t_dbl *list);
int		checklr(int i, int c, char **argv, t_dbl *list);
int		checkllr(int i, int c, char **argv, t_dbl *list);
int		checkthisr(t_dbl *list, char **argv, int w, int k);
int		checkthisbufr(int argc, char **argv, t_dbl *list);
int					heeelp(t_dbl *list, int w);
char				*add(char *d, char *d_name);
char				*folderdelete(t_dbl *list);
char				*folderprint(t_dbl *list, int i);
t_dbl				*help(t_dbl *list);
int					folder(t_dbl *list);
int					count(char *path, t_dbl *list);
int					counttotal(char *path, t_dbl *list);
t_f					*maked(char *path, t_dbl *list);
int					letsprintit(t_dbl *list);
t_dbl				*letsdoit(char *path, t_dbl *list);
t_dbl				*cll(void);
int					addit(t_dbl *list, t_node *tmp);
void				dll(t_dbl *list);
t_dbl				*createlist(void);
char				**whileone(t_dbl *list, t_f *q);
int					caseone(t_dbl *list, int c, char *cwd);
int					casetwo(t_dbl *list, int c, char *cwd);
int					iff(t_dbl *list, char *cwd, int c);
int					main(int argc, char **argv);
int					checktarget(char *c, char *cwd);
int					validation(int argc, char **argv, t_dbl *list);
int					error(char **argv, int i, t_dbl *list);
int					checkfolder(t_dbl *list, char **argv, int i);
int					whilerevtime(t_f *q, int s, char **c, struct stat filestat);
int					whilettime(t_f *q, int s, char **c, struct stat filestat);
t_f					*readd(t_f *q, t_dbl *list);
char				**exclude(char **d, char *c, int argc, int q);
t_f					*rsort(char **argv, int argc, t_f *q, t_dbl *list);
t_f					*sort(char **argv, int argc, t_f *q, t_dbl *list);
t_f					*checkprivilege(t_f *q, int i);
char				*spinit(t_dbl *list, int argc, char **argv, char *c);
char				*sorting(t_dbl *list, int argc, char **argv, char *c);
char				*spinittwice(t_dbl *list, int argc, char **argv, char *c);
char				*rsorting(t_dbl *list, int argc, char **argv, char *c);
t_f					*decideit(t_dbl *list, t_f *q, char **c, int i);
int					finishstat(struct stat filestat, \
		char *timebuf, t_dbl *list, int i);
int					statt(t_dbl *list, int i);
int					rank(int i);
int					ssizee(t_dbl *list);
int					ssize(t_dbl *list);
int					chmood(struct stat filestat, t_dbl *list, int i);
int					whatevs(struct stat filestat);
int					setattr(t_dbl *list, int i);
char				*helper(t_dbl *list, int argc, char **argv, char *c);
char				*helpera(t_dbl *list, int argc, char **argv, char *c);
char				**excludetime(char **d, char *c, int s);
int					ntime(char *a, t_f *q, long time, long ttime);
int					revntime(char *a, t_f *q, long time, long ttime);
t_f					*revttimme(t_f *q, char **c);
t_f					*ttimme(t_f *q, char **c);
int					e(char **argv, int c, t_dbl *list, int i);
int					whilej(t_dbl *list, char **argv, int i, int c);
int					checkflag(char c, t_dbl *list);
int					checkl(int i, int c, char **argv, t_dbl *list);
int					checkll(int i, int c, char **argv, t_dbl *list);
int					checkthis(t_dbl *list, char **argv, int w, int k);
int					checkthisbuf(int argc, char **argv, t_dbl *list);

#endif
