/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <your@mail.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 13:19:29 by mchoma            #+#    #+#             */
/*   Updated: 2025/12/06 13:33:05 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

int main(){
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
