#ifndef RENDER_H
#define RENDER_H
# define WIDTH  1000
# define FLOOR_COLOUR 0x0
# define RAY_COLOUR 0xFFFFED
# define HEIGHT 1000
# define TILESIZE 64
# define WHITE 0xFFFFFF
# define RED   0xFF0000
# define BLUE  0x0000FF
# define GREEN 0x00FF00
# define MAGENTA 0xFF00FF
# define YELLOW 0xFFEA00
# define PINK 0xFFC0CB
# define WALL_LEN 255
# define VOID_COLOUR 0x000001
# define PLAYER_COLOUR 0xFF00008B
# define NORTH_C 0xFF0000
# define SOUTH_C 0x00FF00
# define EAST_C 0x8F0000
# define WEST_C 0x008F00
# include "../libft/libft.h"
# include "../parsing/parsing.h"
# include <mlx.h>
# include <errno.h>
# include <math.h>
# include <X11/keysym.h> 
#include <sys/time.h>
typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}				t_mlx;

typedef struct s_line
{
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	unsigned int	colour;
}	t_line;


typedef struct	s_img
{
	void	**img;
	void	*player;
	int		player_width;
	int		player_height;
	int		player_posx;
	int		player_posy;
	int		img_width;
	int		img_height;
	int		x_tilecount;
	int		y_tilecount;
	int		tileamount;
}				t_img;

typedef struct	s_2d
{
	void	*img_2d;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_2d;

typedef struct s_wasd
{
	char	w;
	char	a;
	char	s;
	char	d;
	char	left;
	char	right;
}			t_wasd;

typedef struct s_player
{
	int		x;
	int		y;
	double	radian;
	t_2d	*image;
	t_wasd	ctrl;
	double	direction;
}				t_player;

typedef struct s_raycast
{
	unsigned int	colour;
	size_t			distance;
	int				x_hit;
	int				y_hit;
}	t_raycast;

typedef struct	s_bundle
{
	t_player		*player;
	t_parse_data	*data;
	t_mlx			*mlx;
	t_2d			*minimap;
}				t_bundle;

typedef struct s_algo
{
	int	deltax;
	int	deltay;
	int	p;
	int	dirx;
	int	diry;
	int	p2;
}			t_algo;
/*Cannot fail. prints with perror. error is the error message, type is a char representing the error errno should be set to:
'n' means no manual setting of errno.*/
void	print_error(char *error, char type); 
void	my_mlx_pixel_put(t_2d *data, int x, int y, int color);
void	algo(t_2d *minimap, t_parse_data *data);
void	draw_line(t_2d *minimap, t_line *line);
void	draw_floor(t_2d *minimap, int x, int y);
void	draw_wall(t_2d *minimap, int x, int y);
int	calcdir(int p1, int p2);
int	checksize(int x1, int y1);
void	draw_line(t_2d *minimap, t_line *line);
void	draw_minimap(t_2d *minimap, t_parse_data *data);
unsigned int	pixel_color(t_2d *data, int x, int y);
void	initline(t_algo *algo, t_line *line);
void where_player2d(t_player *player, t_parse_data *data);
int	create_2d_player(t_player *player, t_mlx *mlx, t_parse_data *data);
void	init_game(t_2d *minimap, t_player *player, t_mlx *mlx, t_parse_data *data);
int	move_2d_player(t_bundle *bundle, int addx, int addy);
#endif
