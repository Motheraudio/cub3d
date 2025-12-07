#ifndef RENDER_H
#define RENDER_H
# define WIDTH 1920
# define HEIGHT 1080
# define TILESIZE 64

# include "../libft/libft.h"
# include <mlx.h>
# include <errno.h>
# include <math.h>


typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}				t_mlx;

typedef struct	s_img
{
	void	**img;
	void	*player;
	int		player_width;
	int		player_height;
	int		img_width;
	int		img_height;
	int		x_tilecount;
	int		y_tilecount;
	int		tileamount;
}				t_img;

/*Cannot fail. prints with perror. error is the error message, type is a char representing the error errno should be set to:
'n' means no manual setting of errno.*/
void	print_error(char *error, char type); 
#endif
