/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 15:37:36 by dsamarsk          #+#    #+#             */
/*   Updated: 2020/02/05 19:49:46 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Display.hpp"
#include "Game.hpp"
/* TEST	*/
void		test_block();
void		test_platform();
void		test_ball();

void		testing()
{
//	test_block();
	test_platform();
//	test_ball();
}


int			main(void)
{
//	testing();

	Game	PongCraft;
	
	PongCraft.init();

	system("leaks -q PongCraft");
	return (0);
}
