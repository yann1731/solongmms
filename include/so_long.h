#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include "../libft/libft.h"

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_criteria
{
	int	C;
	int	P;
	int	E;
}	t_criteria;

char	**convertmaptostring(char *mapfile);
int		countlines(char *mapfile);
int		checkmap(char **map);
int		validchar(char c);
int		checkboundaries(char **map, int lines);
int		checkbody(char **map, int lines);
int		checkcriteria(char **map, int lines, t_criteria info);
int		parsecriteria(t_criteria info);
int		checkshape(char **map, int lines);
void	checkarg(int argc);
void	initinfo(t_criteria *info);
void	errorhandling(int status);

#endif