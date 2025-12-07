/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <your@mail.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 13:19:29 by mchoma            #+#    #+#             */
/*   Updated: 2025/12/06 19:11:19 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"
#include <fcntl.h>

void filename_validation()
{
	printf("---FILE_NAME_VALIDATION---\n");
	if (parse("h.cub") != NULL)
		printf("TEST 1 PASS\n");
	else 
		printf("TEST 1 FAIL\n");
	
	if (parse("ber.cab") == NULL)
		printf("TEST 2 PASS\n");
	else 
		printf("TEST 2 FAIL\n");

	if (parse("ub") == NULL)
		printf("TEST 3 PASS\n");
	else 
		printf("TEST 3 FAIL\n");
	printf("\n\n\n");
}

void	line_path_validation()
{
	t_parse_data	data;
	int				fd;
	char			*path;

	printf("---LINE-PARSING---\n");
	init_parse_data(&data);
	path = "./files/test1.cub";
	fd = open(path , O_RDONLY);
	if (fd == -1)
	{
		printf("file not found expected path = %s\n", path);
		return;
	}
	if (get_metadata(fd, &data) != -1)
	{
		if (
			ft_strncmp(data.n_texture, "./path_to_the_north_texture", ft_strlen(data.e_texture)) == 0 &&
			ft_strncmp(data.s_texture, "./path_to_the_south_texture", ft_strlen(data.e_texture)) == 0 &&
			ft_strncmp(data.w_texture, "./path_to_the_west_texture", ft_strlen(data.e_texture)) == 0 &&
			ft_strncmp(data.e_texture, "./path_to_the_east_texture", ft_strlen(data.e_texture)) == 0 &&
			data.celing.r == 255 &&
			data.celing.g == 254 &&
			data.celing.b == 253 &&
			data.floor.r == 0 &&
			data.floor.g == 1 &&
			data.floor.b == 2
		)
			printf("TEST 1 PASSED\n");
		else
			printf("TEST 1 FAILED[incorect parsing]\n");
	}
	else
		printf("TEST 1 FAILED [error when no error expected]\n");
	init_parse_data(&data);
	path = "./files/test2.cub";
	fd = open(path , O_RDONLY);
	if (fd == -1)
	{
		printf("file not found expected path = %s\n", path);
		return;
	}
	if (get_metadata(fd, &data) != -1)
	{
		if (
			ft_strncmp(data.n_texture, "./north", ft_strlen(data.e_texture)) == 0 &&
			ft_strncmp(data.s_texture, "./south", ft_strlen(data.e_texture)) == 0 &&
			ft_strncmp(data.w_texture, "./west", ft_strlen(data.e_texture)) == 0 &&
			ft_strncmp(data.e_texture, "./east", ft_strlen(data.e_texture)) == 0 &&
			data.celing.r == 200 &&
			data.celing.g == 30 &&
			data.celing.b == 0 &&
			data.floor.r == 0 &&
			data.floor.g == 255 &&
			data.floor.b ==255 
		)
			printf("TEST 2 PASSED\n");
		else
			printf("TEST 2 FAILED[incorect parsing]\n");
	}
	else
		printf("TEST 2 FAILED [error when no error expected]\n");
	init_parse_data(&data);
	path = "./files/test3.cub";
	fd = open(path , O_RDONLY);
	if (fd == -1)
	{
		printf("file not found expected path = %s\n", path);
		return;
	}
	if (get_metadata(fd, &data) != -1)
	{
		if (
			ft_strncmp(data.n_texture, "./north", ft_strlen(data.e_texture)) == 0 &&
			ft_strncmp(data.s_texture, "./south", ft_strlen(data.e_texture)) == 0 &&
			ft_strncmp(data.w_texture, "./west", ft_strlen(data.e_texture)) == 0 &&
			ft_strncmp(data.e_texture, "./east", ft_strlen(data.e_texture)) == 0 &&
			data.celing.r == 0 &&
			data.celing.g == 0 &&
			data.celing.b == 0 &&
			data.floor.r == 12 &&
			data.floor.g == 34 &&
			data.floor.b == 56 
		)
			printf("TEST 3 PASSED\n");
		else
		{
			print_parse_data(&data);
			printf("TEST 3 FAILED[incorect parsing]\n");
		}
	}
	else
		printf("TEST 3 FAILED [error when no error expected]\n");
	init_parse_data(&data);
	path = "./files/test4.cub";
	fd = open(path , O_RDONLY);
	if (fd == -1)
	{
		printf("file not found expected path = %s\n", path);
		return;
	}
	if (get_metadata(fd, &data) != -1)
	{
		printf("TEST 4 FAILED [no error when error expected]\n");
	}
	else
		printf("TEST 4 PASSED\n");
	init_parse_data(&data);
	path = "./files/test5.cub";
	fd = open(path , O_RDONLY);
	if (fd == -1)
	{
		printf("file not found expected path = %s\n", path);
		return;
	}
	if (get_metadata(fd, &data) != -1)
	{
		printf("TEST 5 FAILED [no error when error expected]\n");
	}
	else
		printf("TEST 5 PASSED\n");
	init_parse_data(&data);
	path = "./files/test6.cub";
	fd = open(path , O_RDONLY);
	if (fd == -1)
	{
		printf("file not found expected path = %s\n", path);
		return;
	}
	if (get_metadata(fd, &data) != -1)
	{
		printf("TEST 6 FAILED [no error when error expected]\n");
	}
	else
		printf("TEST 6 PASSED\n");

	init_parse_data(&data);
	path = "./files/test7.cub";
	fd = open(path , O_RDONLY);
	if (fd == -1)
	{
		printf("file not found expected path = %s\n", path);
		return;
	}
	if (get_metadata(fd, &data) != -1)
	{
		printf("TEST 7 FAILED [no error when error expected]\n");
	}
	else
		printf("TEST 7 PASSED\n");
	init_parse_data(&data);
	path = "./files/test8.cub";
	fd = open(path , O_RDONLY);
	if (fd == -1)
	{
		printf("file not found expected path = %s\n", path);
		return;
	}
	if (get_metadata(fd, &data) != -1)
	{
		printf("TEST 8 FAILED [no error when error expected]\n");
	}
	else
		printf("TEST 8 PASSED\n");
	init_parse_data(&data);
	path = "./files/test9.cub";
	fd = open(path , O_RDONLY);
	if (fd == -1)
	{
		printf("file not found expected path = %s\n", path);
		return;
	}
	if (get_metadata(fd, &data) != -1)
	{
		printf("TEST 9 FAILED [no error when error expected]\n");
	}
	else
		printf("TEST 9 PASSED\n");
	init_parse_data(&data);
	path = "./files/test10.cub";
	fd = open(path , O_RDONLY);
	if (fd == -1)
	{
		printf("file not found expected path = %s\n", path);
		return;
	}
	if (get_metadata(fd, &data) != -1)
	{
		printf("TEST 10 FAILED [no error when error expected]\n");
	}
	else
		printf("TEST 10 PASSED\n");
	init_parse_data(&data);
	path = "./files/test11.cub";
	fd = open(path , O_RDONLY);
	if (fd == -1)
	{
		printf("file not found expected path = %s\n", path);
		return;
	}
	if (get_metadata(fd, &data) != -1)
	{
		printf("TEST 11 FAILED [no error when error expected]\n");
	}
	else
		printf("TEST 11 PASSED\n");
	init_parse_data(&data);
}

void	map_validation(void)
{
	t_parse_data	data;
	int				fd;
	char			*path;

	parse("files/test1.cub");

	

}

int main(){
	// filename_validation();
	// line_path_validation();
	map_validation();

}
