/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 15:37:36 by dsamarsk          #+#    #+#             */
/*   Updated: 2020/02/02 16:47:10 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
/*  TEST */
#include "Block.hpp"


int			main(void)
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
	return (0);
}
