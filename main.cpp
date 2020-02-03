/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 15:37:36 by dsamarsk          #+#    #+#             */
/*   Updated: 2020/02/03 15:54:55 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
/*  TEST */
#include "Block.hpp"
#include "Platform.hpp"
#include "Movable.hpp"

void		test_block()
{
//	Block test(21, 42, Block::Type::White);
	Block test(Block::Type::Brown);
	std::cout << test.getX() << std::endl;
	std::cout << test.getY() << std::endl;
	if (test.getType() == Block::Type::White)
	{
		std::cout << "Is white" << std::endl;
	}
	test.setX(13);
	test.setY(66);
	test.setType(Block::Type::Green);
	std::cout << test.getX() << std::endl;
	std::cout << test.getY() << std::endl;
	if (test.getType() == Block::Type::Green)
	{
		std::cout << "Is green" << std::endl;
	}
}

void		test_platform()
{
	Platform p1(21, 42);
	std::cout << p1.getX() << std::endl;
	std::cout << p1.getY() << std::endl;
	if (p1.getBlock(1)->getType() == Block::Type::White)
	{
		std::cout << "Is white" << std::endl;
	}
	p1.setBlock(1, Block::Type::Green);
	if (p1.getBlock(1)->getType() == Block::Type::Green)
	{
		std::cout << "Is green" << std::endl;
	}

}

int			main(void)
{
//	test_block();
	test_platform();

	system("leaks -q PongCraft");
	return (0);
}
