/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <your@mail.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 13:19:29 by mchoma            #+#    #+#             */
/*   Updated: 2025/12/06 15:04:32 by mchoma           ###   ########.fr       */
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

	path = "./files/test1.cub";
	fd = open(path , O_RDONLY);
	if (fd == -1)
	{
		printf("file not found expected path = %s\n", path);
		return;
	}
	get_metadata(fd, &data);
	print_parse_data(&data);

}

int main(){
	filename_validation();
	line_path_validation();

}
