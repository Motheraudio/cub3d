#include "render.h"
void	draw_line(t_2d *minimap, t_line *line);
unsigned int	pixel_color(t_2d *data, int x, int y)
{
	char	*dst;

	dst = data->addr + ((y * data->line_length)
			+ (x * (data->bits_per_pixel / 8)));
	return (*(unsigned int *)dst);
}

void	my_mlx_pixel_put(t_2d *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + ((y * data->line_length)
			+ (x * (data->bits_per_pixel / 8)));
	*(unsigned int *)dst = color;
}

void	draw_rectangle(t_2d *minimap, int x, int y, int type)
{
	int	i;
	int	j;
	
	i = y;
	while(i < y + minimap->blocky)
	{
		j = x;
		while (j < x + minimap->blockx)
			my_mlx_pixel_put(minimap, x, y, 0xFFFFFF);
		i++;
	}
}
int	calcdir(int p1, int p2)
{
	if (p1 < p2)
		return (1);
	else
		return (-1);
}

static void	initalgo(t_algo *algo, t_2d *minimap)
{
	algo->deltax = abs(minimap->x2 - minimap->x1);
	algo->deltay = -abs(minimap->y2 - minimap->y1);
	algo->p = algo->deltay + algo->deltax;
	algo->dirx = calcdir(minimap->x1, minimap->x2);
	algo->diry = calcdir(minimap->y1, minimap->y2);
}

int	checksize(int x1, int y1)
{
	if (x1 > WIDTH - 1 || x1 < 0
		|| y1 < 0 || y1 > HEIGHT - 1)
		return (0);
	else
		return (1);
}

void	algo(t_2d *minimap, t_parse_data *data)
{
	t_algo	algo;

	initalgo(&algo, minimap);
	while (1)
	{
		if (checksize(minimap->x1, minimap->y1) == 0)
			break ;
		my_mlx_pixel_put(minimap, minimap->x1, minimap->y1, 0xFFFFFF);
		algo.p2 = 2 * algo.p;
		if (algo.p2 >= algo.deltay)
		{
			if (minimap->x1 == minimap->x2)
				break ;
			algo.p += algo.deltay;
			minimap->x1 += algo.dirx;
		}
		if (algo.p2 <= algo.deltax)
		{
			if (minimap->y1 == minimap->y2)
				break ;
			algo.p += algo.deltax;
			minimap->y1 += algo.diry;
		}
	}
}
